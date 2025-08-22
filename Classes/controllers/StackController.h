#pragma once

#include "cocos2d.h"
#include "GameConfig.h"
#include"CardView.h"
#include"StackCardView.h"
USING_NS_CC;

class StackController{
public:
    static void init();
    static void initView(Node* rootNode);
    
    static void addToView(CardView* card);
    static void withdrawCard();
    
    
private:
    static void handleCardClick(CardView* card);
    static void creatTypeCard(Node* rootNode, std::function<void(CardView*)> onCardClicked);

    static std::function<void(CardView*)> _onCardClicked;
    static StackCard* _stackCards;
};