#pragma once

#include "cocos2d.h"

#include"CardView.h"
#include"MatchZoneView.h"
USING_NS_CC;

class MatchZoneController {
public:
    static void init();
    static void initView(Node* rootNode);

    static void addTo(CardView* card);//在匹配区 添加一张卡
    static void moveTopBack(CardView* card);//移除top卡
    static void replaceToTop(CardView* card);


    static MatchZoneView* getmatchZoneView() { return _matchZoneView; };
private :
    static void creatView(Node* rootNode);

    static MatchZoneView* _matchZoneView;
    
};