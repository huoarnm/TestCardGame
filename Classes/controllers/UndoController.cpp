#include "UndoController.h"
#include"CardStateModel.h"
#include"GameConfig.h"

#include"MatchZoneController.h"
#include"StackController.h"

UndoView* UndoController::_undoView = nullptr;
Vector<CardView*> UndoController::_undoCards;
void UndoController::init() {

}
void UndoController::initView(Node* rootNode) {
    _undoView = UndoView::create();
    _undoView->onUndoClicked = []() {
        if (_undoCards.size() > 1)
        handleWithdraw(); // µ÷ÓÃ¿ØÖÆÆ÷Âß¼­
        };
    _undoView->setPosition(GameConfig::undoButtonPos);
    rootNode->addChild(_undoView);
}

void UndoController::handleWithdraw() {
    //get

    CardView* upCard, * underCard;
    getTheLeastTwo(upCard, underCard);
    
    MatchZoneController::moveTopBack(upCard);
    MatchZoneController::replaceToTop(underCard);

    if (CardStateModel::getInstance()->getUndoStackBack() == CardArea::STACK)
        StackController::withdrawCard();
}

void UndoController::pushCard(CardView* card) {
    _undoCards.pushBack(card);
}
void UndoController::popCard() {
    if (!_undoCards.empty())
        _undoCards.popBack();
}
void UndoController::getTheLeastTwo(CardView*& upCard, CardView*& underCard) {
    upCard = _undoCards.back();
    popCard();
    underCard = _undoCards.back();
}