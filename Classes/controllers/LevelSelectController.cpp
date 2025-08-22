#include "LevelSelectController.h"
#include "GameScene.h"
#include "GameModel.h"
#include "DrawBackgroundView.h"
#include "LevelButtonView.h"

LevelSelectController* LevelSelectController::create(LevelSelectView* view) {
    LevelSelectController* ret = new (std::nothrow) LevelSelectController();
    if (ret && ret->init(view)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool LevelSelectController::init(LevelSelectView* view) {
    if (!Node::init()) return false;
    levelSelectView = view;

    initView();

    return true;
}

void LevelSelectController::initView() {
    //渲染背景
    auto bg = DrawBackgroundView::create(Vec2(0, 0), Vec2(1080, 2080), Color4F::BLACK);
    bg->setPosition(Vec2::ZERO);
    levelSelectView->addChild(bg, -1);

    //生成一个按钮
    auto btn = LevelButtonView::create(1, [this](std::string levelName) {
        //关卡已选择，回调函数
        this->setSelectedLevel(levelName);
        });
    btn->setPosition(Vec2(540, 1040));
    levelSelectView->addChild(btn, 0);
}

//传入model
void LevelSelectController::setSelectedLevel(std::string levelName) {
    GameModel::getInstance()->setSelectedLevel(levelName);//将关卡id传入model
    //进入Game
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, scene));
}

