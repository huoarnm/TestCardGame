#include"CardModel.h"

int CardModel::_cardCnt = 0;

CardModel* CardModel::create(int face, int suit, int x, int y) {
    auto card = new CardModel();
    if (card && card->init(face, suit, x, y)) {
        card->autorelease(); // 加入自动释放池
        return card;
    }
    CC_SAFE_DELETE(card);
    return nullptr;
}

bool CardModel::init(int face, int suit, int x, int y) {
    _id = _cardCnt++;
    _face = face;
    _suit = suit;
    _originPos = Vec2(x, y);

    return true;
}

