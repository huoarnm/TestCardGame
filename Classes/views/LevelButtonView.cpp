#include"LevelButtonView.h"

LevelButtonView* LevelButtonView::create(int levelNumber, std::function<void(std::string)> callback) {
    LevelButtonView* ret = new (std::nothrow) LevelButtonView();
    if (ret && ret->init(levelNumber, callback)); {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool LevelButtonView::init(int levelNumber, std::function<void(std::string)> callback) {
    if (!Node::init()) return false;

    _callback = callback;
    setView(levelNumber);
    bindEvent();

    return true;
}

void LevelButtonView::setView(int levelNumber) {
    // 背景:黑色
    _background = DrawNode::create();
    Vec2 origin(0, 0), dest(400, 160);
    Color4F black = Color4F::BLACK;
    _background->drawSolidRect(origin, dest, black);
    this->addChild(_background);

    // 文字:白色
    _label = Label::createWithSystemFont("Level " + std::to_string(levelNumber), "Arial", 56);
    _label->setTextColor(Color4B::WHITE);
    _label->setPosition(Vec2(200, 80)); // 中心
    this->addChild(_label);

    Vec2 sizeVec = dest - origin;
    this->setContentSize(Size(sizeVec));
    this->setAnchorPoint(Vec2(0.5, 0.5));
}

void LevelButtonView::bindEvent() {
    //添加点击监听器
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [this](Touch* touch, Event* event) {
        Vec2 locationInNode = this->convertToNodeSpace(touch->getLocation());
        Size size = this->getContentSize();
        Rect rect(0, 0, size.width, size.height);

        if (rect.containsPoint(locationInNode)) {
            if (_callback) {
                _callback(_label->getString());
            }
            return true;
        }
        return false;
        };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}