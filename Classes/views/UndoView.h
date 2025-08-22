#pragma once
#include "cocos2d.h"
USING_NS_CC;

class UndoView : public Node {
public:
    CREATE_FUNC(UndoView);
    virtual bool init() override;

    std::function<void()> onUndoClicked;
};
