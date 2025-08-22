#pragma once

#include"cocos2d.h"
USING_NS_CC;

class GameViewManager : public cocos2d::Ref {
public:
    static GameViewManager* create(cocos2d::Node* rootNode); // 外部传入场景/父节点
    bool init(cocos2d::Node* rootNode);

    void setView();
    void setBackground();//渲染背景

private:
    Node* _rootNode = nullptr; // 场景根节点，用于 addChild
};