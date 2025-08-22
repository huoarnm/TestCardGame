#pragma once

#include "cocos2d.h"
#include "GameConfig.h"

#include "GameView.h"//ÌáÈ¡ÉùÃ÷
#include "GameViewManager.h"
#include "CardView.h"

USING_NS_CC;

class GameController : public Node {
public:
    virtual bool init(GameView* view);
    static GameController* create(GameView* view);
private:
    GameViewManager* _viewManager;
    
    void loadLevel();
    void initController();
    void iniView();

    GameView* _gameView;
    
};