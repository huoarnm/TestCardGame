#include"PlayfieldController.h"

#include"MatchZoneController.h"
#include"PlayfieldCardView.h"
#include"CardStateModel.h"

std::function<void(CardView*)> PlayfieldController::_onCardClicked = nullptr;
Node* PlayfieldController::_playfieldView = nullptr;

void PlayfieldController::init() {
    _onCardClicked = [](CardView* card) {
        handleCardClick(card);
        };
}
void PlayfieldController::initView(Node* rootNode) {
    _playfieldView = Node::create();
    rootNode->addChild(_playfieldView);
    creatTypeCard(_onCardClicked);
}

void PlayfieldController::creatTypeCard(std::function<void(CardView*)> onCardClicked) {
    //获取model
    auto cardState = CardStateModel::getInstance();
    for (auto& cardModel : cardState->getPlayfieldCards()) {
        //由model生成view
        auto card = PlayfieldCard::create(cardModel, onCardClicked);
        _playfieldView->addChild(card);
    }
}

void PlayfieldController::handleCardClick(CardView* card) {

    //check() 检查 可否匹配 不匹配返回
    int topCardFace = CardStateModel::getInstance()->getTopCardFace();
    int cardFace = card->getModel()->getFace();
    if (topCardFace != cardFace + 1 && cardFace != topCardFace + 1)return;

    //run() 执行匹配动作
    auto move = MoveTo::create(GameConfig::moveDuration_pla, GameConfig::matchZonePos);//移动到匹配区
    auto callback = CallFunc::create([card]() {
        MatchZoneController::addTo(card);       //调用匹配区添加方法
        });
    card->runAction(Sequence::create(move, callback, nullptr));

    //update()
    card->getModel()->updateClickEnabled(false);
    card->updateEnableClick();
    CardStateModel::getInstance()->pushbackUndoStack(PLAYFIELD);
}

void PlayfieldController::addToView(CardView* card) {
    _playfieldView->addChild(card);
}