#pragma once
#include "cocos2d.h"

USING_NS_CC;

// 根据 int 参数创建一个对应的关卡选择按钮，点击时触发回调函数
class LevelButtonView : public Node {
public:
    static LevelButtonView* create(int levelNumber, std::function<void(std::string)> callback);
    virtual bool init(int levelNumber, std::function<void(std::string)> callback);

    void setView(int levelNumber);
    void bindEvent();

private:
    DrawNode* _background;
    Label* _label;

    std::function<void(std::string)> _callback;
};
