#include"GameViewManager.h"
#include"DrawBackgroundView.h"

USING_NS_CC;

GameViewManager* GameViewManager::create(Node* rootNode) {
    auto mgr = new GameViewManager();
    if (mgr && mgr->init(rootNode)) {
        mgr->autorelease();
        return mgr;
    }
    CC_SAFE_DELETE(mgr);
    return nullptr;
}

bool GameViewManager::init(Node* rootNode) {
    _rootNode = rootNode;

    return true;
}

void GameViewManager::setView() {
    setBackground();
}

void GameViewManager::setBackground() {
    auto bgStack = DrawBackgroundView::create(Vec2(0, 0), Vec2(1080, 580), Color4F(0.6f, 0.0f, 0.6f, 1.0f));
    auto bgPlayfield = DrawBackgroundView::create(Vec2(0, 580), Vec2(1080, 2080), Color4F(0.6f, 0.4f, 0.2f, 1.0f));
    bgStack->setPosition(Vec2::ZERO);
    bgPlayfield->setPosition(Vec2::ZERO);

    _rootNode->addChild(bgPlayfield, -1);
    _rootNode->addChild(bgStack, -1);

}