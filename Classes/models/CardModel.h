#pragma once

#include"cocos2d.h"
USING_NS_CC;

class CardModel :public Ref {
public:
	static CardModel* create(int face, int suit, int x, int y);
	virtual bool init(int face, int suit, int x, int y);

	void updateOriginPosition(Vec2 pos) { _originPos = pos; }
	void updateSeclected(bool state) { _seclected = state; }
	void updateClickEnabled(bool state) { _clickEnabled = state; }

	int getFace() const { return _face; }
	int getSuit() const { return _suit; }
	Vec2 getOriginPosition() const { return _originPos; }
	bool getClickEnabled()const { return _clickEnabled; }

private:
	int _id;
	int _face;
	int _suit;
	Vec2 _originPos;

	bool _seclected = false;
	bool _clickEnabled = true;

	static int _cardCnt;
};