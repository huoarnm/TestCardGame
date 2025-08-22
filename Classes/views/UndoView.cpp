#include "UndoView.h"


bool UndoView::init() {
    if (!Node::init()) {
        return false;
    }

    auto label = Label::createWithSystemFont("Return", "Arial", 36);
    label->setTextColor(Color4B::WHITE);

    auto menuItem = MenuItemLabel::create(label, [this](Ref* sender) {
        if (onUndoClicked) {
            onUndoClicked(); // 调用回调
        }
        else {
            CCLOG("no define");
        }
        });

    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}
