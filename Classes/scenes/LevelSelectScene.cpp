#include "SimpleAudioEngine.h"
#include "LevelSelectScene.h"
#include "LevelSelectController.h"
#include "LevelSelectView.h"

Scene* LevelSelectScene::createScene()
{
    return LevelSelectScene::create();
}

bool LevelSelectScene::init()
{
    if (!Scene::init()) return false;

    auto view = LevelSelectView::create();
    auto controller = LevelSelectController::create(view);
    this->addChild(view);

    return true;
}
