#include"MatchZoneController.h"
#include"CardStateModel.h"

//test
#include"UndoController.h"

MatchZoneView* MatchZoneController::_matchZoneView = nullptr;

void MatchZoneController::init() {
    ;
}

void MatchZoneController::initView(Node* rootNode) {
    creatView(rootNode);
}

void MatchZoneController::creatView(Node* rootNode) {
    _matchZoneView = MatchZoneView::create();
    rootNode->addChild(_matchZoneView);
}

void MatchZoneController::addTo(CardView* card) {
    //action
    _matchZoneView->setCard(card);
    //update
    int curFace = card->getModel()->getFace();
    CardStateModel::getInstance()->updateTopCardFace(curFace);
    
    UndoController::pushCard(card);
}
void MatchZoneController::replaceToTop(CardView* card) {
    //action
    _matchZoneView->setCard(card);
    card->setVisible(true);
    //update
    int curFace = card->getModel()->getFace();
    CardStateModel::getInstance()->updateTopCardFace(curFace);

}

//解除top绑定，并将其移回,设置为可点击，
void MatchZoneController::moveTopBack(CardView* card) {
    //action
    _matchZoneView->clearCard();

    auto move = MoveTo::create(0.3f, card->getModel()->getOriginPosition());
    auto callback = CallFunc::create([card]() {
        card->getModel()->updateClickEnabled(true);
        card->updateEnableClick();
    });

    auto sequence = Sequence::create(move, callback, nullptr);
    card->runAction(sequence);
}