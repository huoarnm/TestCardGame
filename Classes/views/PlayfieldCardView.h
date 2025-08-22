#pragma once
#include "cocos2d.h"
#include "CardView.h"

USING_NS_CC;

class PlayfieldCard {
public:
	static CardView* create(CardModel* cardmodel, std::function<void(CardView*)> onCardClicked);
};
