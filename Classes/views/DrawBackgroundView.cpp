#include "DrawBackgroundView.h"

DrawBackgroundView* DrawBackgroundView::create(Vec2 origin, Vec2 dest, Color4F color) {
    DrawBackgroundView* ret = new(std::nothrow) DrawBackgroundView();
    if (ret && ret->init(origin, dest, color)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool DrawBackgroundView::init(Vec2 origin, Vec2 dest, Color4F color) {
    if (!Node::init()) return false;

    _background = DrawNode::create();
    _background->drawSolidRect(origin, dest, color);//ÊÖÅÆÇø
    this->addChild(_background);

    return true;
}