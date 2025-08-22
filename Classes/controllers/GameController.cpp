#include"GameController.h"

#include"PlayfieldController.h"//子控制器
#include"StackController.h"
#include"MatchZoneController.h"
#include"UndoController.h"

#include"GameModel.h"//model
#include"GameModelFromLevelGenerator.h"//service


GameController* GameController::create(GameView* view) {
    GameController* ret = new (std::nothrow) GameController();
    if (ret && ret->init(view)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

bool GameController::init(GameView* view) {
    if (!Node::init()) return false;
    _gameView = view;

    //生成简单view
    _viewManager = GameViewManager::create(_gameView);
    _viewManager->setView();

    //Game执行流程
    loadLevel();//加载关卡信息
    initController();//初始化 子controller
    iniView();//子controller 生成各自view

    return true;
}

//从config读取关卡，初始化至model
void GameController::loadLevel() {
    //获取参数
    std::string filename = GameConfig::levelConfigPath;
    std::string levelName = GameModel::getInstance()->getSelectedLevel();
    //service层 读取+存储
    GameModelFromLevelGenerator::generateCardModel(levelName, filename);
}

//
void GameController::initController() { 
    PlayfieldController::init();
    StackController::init();
    MatchZoneController::init();
    UndoController::init();
}
//
void GameController::iniView() {
    PlayfieldController::initView(_gameView);
    StackController::initView(_gameView);
    MatchZoneController::initView(_gameView);
    UndoController::initView(_gameView);
    
}


