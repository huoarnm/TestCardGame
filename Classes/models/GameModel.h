#pragma once

#include"cocos2d.h"
#include"CardStateModel.h"
USING_NS_CC;

class GameModel {
public:
    static GameModel* getInstance();

    void setSelectedLevel(std::string);
    std::string getSelectedLevel() const;

private:
    std::string _selectedLevel = "";

};
