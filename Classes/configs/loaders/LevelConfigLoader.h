#pragma once

#include "cocos2d.h"
#include "json/document.h"
#include "json/error/en.h"

class LevelConfigLoader {
public:
    // 加载关卡数据
    static bool loadLevel(const std::string& filename, const std::string& levelName, 
                            rapidjson::Document& outDoc, rapidjson::Value*& outLevelData);
};
