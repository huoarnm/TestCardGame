#pragma once
#include "cocos2d.h"
#include"GameConfig.h"
#include"CardView.h"
USING_NS_CC;

class MatchZoneView :public Sprite {
public:
    virtual bool init() override;
    CREATE_FUNC(MatchZoneView);

    void setCard(CardView* card);  // 设置匹配区当前卡牌
    CardView* getCard() const;     // 获取当前卡牌
    void clearCard();              // 清空匹配区卡牌（比如卡牌被移走了）

private:
    CardView* _topCard = nullptr;
};