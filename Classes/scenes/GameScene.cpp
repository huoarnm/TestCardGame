#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "GameController.h"
#include "GameView.h"

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{
    if (!Scene::init()) return false;

    auto view = GameView::create();
    auto controller = GameController::create(view);
    this->addChild(view);

    return true;
}

