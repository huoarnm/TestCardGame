#pragma once
#include "cocos2d.h"
#include "CardModel.h"
#include "CardAreaEnum.h"
USING_NS_CC;


class CardStateModel : public cocos2d::Ref {
public:
    static CardStateModel* getInstance();
   

    void addToStack(int face, int suit, int x, int y);
    void addToPlayfield(int face, int suit, int x, int y);

    void pushbackUndoStack(CardArea);
    void popUndoStack();

    const Vector<CardModel*>& getStackCards() const { return _stackCards; }
    const Vector<CardModel*>& getPlayfieldCards() const { return _playfieldCards; }
    const CardArea getUndoStackBack();

    void updateTopCardFace(const int& face) { topCardFace = face; }
    const int getTopCardFace() const { return topCardFace; }

private:
    Vector<CardModel*> _stackCards;//¶ÑÅÆ
    Vector<CardModel*> _playfieldCards;//×ÀÅÆ

    int topCardFace = -1;//µ±Ç° ¶¥ÅÆ

    std::vector<CardArea> _undoStack;

    static CardStateModel* _instance;

};
