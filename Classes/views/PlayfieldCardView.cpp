#include "PlayfieldCardView.h"

CardView* PlayfieldCard::create(CardModel* cardModel, std::function<void(CardView*)> onCardClicked) {

    auto card = CardView::create(cardModel);
    card->setClickCallback(onCardClicked);
    return card;
}
