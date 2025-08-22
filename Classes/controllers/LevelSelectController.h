#pragma once

#include"cocos2d.h"
#include"LevelSelectView.h"
USING_NS_CC;

class LevelSelectController : public Node {
public:
    virtual bool init(LevelSelectView* view);
    static LevelSelectController* create(LevelSelectView* view);

private:
    void initView();
    void setSelectedLevel(std::string levelName);

    LevelSelectView* levelSelectView;
};