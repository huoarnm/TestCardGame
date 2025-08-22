#pragma once
#include "cocos2d.h"

USING_NS_CC;

class DrawBackgroundView : public Node {
public:
    

    static DrawBackgroundView* create(Vec2 origin, Vec2 dest, Color4F color);
    virtual bool init(Vec2 origin, Vec2 dest, Color4F color);

private:
    DrawNode* _background;
};
