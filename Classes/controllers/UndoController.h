#pragma once
#include"cocos2d.h"
#include"CardAreaEnum.h"
#include"UndoView.h"
#include"CardView.h"
USING_NS_CC;

class UndoController {
public:
    static void init();
    static void initView(Node* rootNode);
    
    static void pushCard(CardView* card);
    static void popCard();
private:
    static void handleWithdraw();
    static void getTheLeastTwo(CardView*& upCard, CardView*& underCard);


    static UndoView* _undoView;

    static Vector<CardView*> _undoCards;//´æ·ÅÒÑÆ¥ÅäµÄ¿¨ÅÆ
};
