#pragma once

#include "cocos2d.h"
#include"MatchZoneView.h"
#include"UndoView.h"
USING_NS_CC;

class GameView : public Node {
public:
    CREATE_FUNC(GameView);
    bool init() override;
};