#include "LevelConfigLoader.h"


using namespace cocos2d;
using namespace rapidjson;

bool LevelConfigLoader::loadLevel(const std::string& filename, const std::string& levelName, Document& outDoc, rapidjson::Value*& outLevelData) {
    std::string fullPath = FileUtils::getInstance()->fullPathForFilename(filename);
    std::string jsonStr = FileUtils::getInstance()->getStringFromFile(fullPath);
    auto paths = FileUtils::getInstance()->getSearchPaths();
    for (const auto& path : paths) {
        CCLOG("Search path: %s", path.c_str());
    }

    outDoc.Parse(jsonStr.c_str());
    if (outDoc.HasParseError()) {
        CCLOG("JSON解析失败: %s (%u)", GetParseError_En(outDoc.GetParseError()), (unsigned)outDoc.GetErrorOffset());
        return false;
    }

    if (!outDoc.HasMember(levelName.c_str())) {
        CCLOG("找不到关卡: %s", levelName.c_str());
        return false;
    }

    rapidjson::Value &levelArray = outDoc[levelName.c_str()];
    if (!levelArray.IsArray() || levelArray.Size() == 0) {
        CCLOG("关卡数据格式错误: %s", levelName.c_str());
        return false;
    }

    outLevelData = &levelArray[0];
    return true;
}
