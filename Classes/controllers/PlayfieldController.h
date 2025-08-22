#pragma once

#include "cocos2d.h"
#include "GameConfig.h"
#include"CardView.h"
USING_NS_CC;

class PlayfieldController{
public:
    static void init();
    static void initView(Node* rootNode);
    static void handleCard
    (CardView* card);
    static void addToView(CardView* card);
    
private:
    //处理Playfield 被点击的牌
    static void handleCardClick(CardView* card);
    //生成Playfield 上的牌，绑定回调函数
    static void creatTypeCard(std::function<void(CardView*)> onCardClicked);

    static std::function<void(CardView*)> _onCardClicked;//playfield里的回调函数
    static Node* _playfieldView;
};