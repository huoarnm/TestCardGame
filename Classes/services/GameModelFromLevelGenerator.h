#pragma once

#include <string>
#include "CardStateModel.h"
#include "LevelConfigLoader.h" // 提供 loadLevel

using namespace cocos2d;
using namespace rapidjson;

// 将指定关卡名的数据从配置读取并写入 model，返回是否成功
class GameModelFromLevelGenerator {
public:
    static bool generateCardModel(const std::string& levelName, const std::string& configFile);
};
