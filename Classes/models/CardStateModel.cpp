#include"CardStateModel.h"
#include"GameConfig.h"

CardStateModel* CardStateModel::_instance = nullptr;
CardStateModel* CardStateModel::getInstance() {
    if (!_instance) {
        _instance = new CardStateModel();
        if (_instance ) {
            _instance->retain();  // 增加引用，防止被释放
        }
        else {
            CC_SAFE_DELETE(_instance);
        }
    }
    return _instance;
}


void CardStateModel::addToStack(int face, int suit, int x, int y) {
    auto card = CardModel::create(face, suit, x, y);
    _stackCards.pushBack(card);
}

void CardStateModel::addToPlayfield(int face, int suit, int x, int y) {
    y = GameConfig::stackSize.height + y;
    auto card = CardModel::create(face, suit, x, y);
    _playfieldCards.pushBack(card);
}

void CardStateModel::pushbackUndoStack(CardArea cardArea) {
    _undoStack.push_back(cardArea);
}
void CardStateModel::popUndoStack() {
    _undoStack.pop_back();
}

const CardArea CardStateModel::getUndoStackBack() {
    CardArea cardArea= _undoStack.back();
    _undoStack.pop_back();
    return cardArea;
 }