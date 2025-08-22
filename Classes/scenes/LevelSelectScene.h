#ifndef __LevelSelect_SCENE_H__
#define __LevelSelect_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class LevelSelectScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(LevelSelectScene);
};

#endif // __LevelSelect_SCENE_H__