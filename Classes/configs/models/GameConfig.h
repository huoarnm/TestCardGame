#pragma once

#include"cocos2d.h"
USING_NS_CC;

namespace GameConfig {
	//Size
	static const Size playfeildSize= Size(Vec2(1080, 1500));
	static const Size stackSize= Size(Vec2(1080, 580));
	static const Size cardSize= Size(Vec2(182, 282));
	
	//Pos
	static const Vec2 undoButtonPos = Vec2(900, 290);
	static const Vec2 matchZonePos = Vec2(700, 290);

	//String
	static const std::string levelConfigPath = "configs/LevelConfig.json";

	//duration
	static const float moveDuration_pla = 0.3f;
	static const float moveDuration_sta = 0.3f;

}
