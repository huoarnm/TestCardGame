#pragma once

#include "cocos2d.h"
#include "CardView.h"
#include"CardStateModel.h"
USING_NS_CC;

class StackCard : public Node {
public:
    static StackCard* create(const CardStateModel* stackModel, const std::function<void(CardView*)> onCardClicked);
    virtual bool init(const CardStateModel* stackModel, const std::function<void(CardView*)> onCardClicked);


    void addCard(CardView* card);
    void removeCard();
    void withdrawOneCard();
    void layoutCards(); // ≈≈¡– ÷≈∆
    CardView* back() { return index != -1 ? _cards.at(index) : nullptr; }
    

private:
    int index = -1;
    Vector<CardView*> _cards;
};