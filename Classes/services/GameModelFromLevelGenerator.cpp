#include"GameModelFromLevelGenerator.h"

bool GameModelFromLevelGenerator::generateCardModel(const std::string& levelName, const std::string& configFile) {
    //获取state类，失败返回false
    auto cardState = CardStateModel::getInstance();
    if (!cardState) return false;

    
    rapidjson::Document doc;
    rapidjson::Value* levelData = nullptr;

    if (LevelConfigLoader::loadLevel(configFile, levelName, doc, levelData)) {//调用LevelConfigLoader::loadLevel 获取LevelConfig
        // 读取 Playfield
        const auto& playfield = (*levelData)["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfield.Size(); ++i) {
            const auto& card = playfield[i];
            int face = card["CardFace"].GetInt();
            int suit = card["CardSuit"].GetInt();
            float x = card["Position"]["x"].GetFloat();
            float y = card["Position"]["y"].GetFloat();

            // 调用桌牌区add
            cardState->addToPlayfield(face, suit, x, y);
        }
        // 读取 Stack
        const auto& stack = (*levelData)["Stack"];
        for (rapidjson::SizeType i = 0; i < stack.Size(); ++i) {
            const auto& card = stack[i];
            int face = card["CardFace"].GetInt();
            int suit = card["CardSuit"].GetInt();
            float x = card["Position"]["x"].GetFloat();
            float y = card["Position"]["y"].GetFloat();

            //调用 堆牌区add
            cardState->addToStack(face, suit, x, y);
        }
        return true;
    }
    return false;
}
