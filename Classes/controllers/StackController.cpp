#include"StackController.h"
#include"CardStateModel.h"
#include"StackCardView.h"
#include"MatchZoneController.h"

StackCard* StackController::_stackCards = nullptr;
std::function<void(CardView*)> StackController::_onCardClicked = nullptr;

void StackController::init() {
    _onCardClicked = [](CardView* card) {
        handleCardClick(card);
        };
    }

void StackController::initView(Node* rootNode) {
    creatTypeCard(rootNode,_onCardClicked);
}

void StackController::creatTypeCard(Node* rootNode, std::function<void(CardView*)> onCardClicked) {
    auto cardState = CardStateModel::getInstance();//获取model
    _stackCards = StackCard::create(cardState, onCardClicked);//创建view

    rootNode->addChild(_stackCards);
}

void StackController::addToView(CardView* card) {
    _stackCards->addCard(card);
}

void StackController::withdrawCard() {
    _stackCards->withdrawOneCard();
}

void StackController::handleCardClick(CardView* card) {
    //check() 无逻辑判断，始终为真

    //run() 
    card = _stackCards->back();
    
    auto move1 = MoveTo::create(GameConfig::moveDuration_sta, GameConfig::matchZonePos);;
    auto callback = CallFunc::create([card]() {
        _stackCards->removeCard();
        MatchZoneController::addTo(card);
        });
    card->runAction(Sequence::create(move1, callback, nullptr));
    
    //update()
    card->getModel()->updateClickEnabled(false);
    card->updateEnableClick();
    CardStateModel::getInstance()->pushbackUndoStack(STACK);
}

