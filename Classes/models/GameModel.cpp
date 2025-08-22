#include"GameModel.h"

GameModel* GameModel::getInstance() {
    static GameModel instance;
    return &instance;
}

void GameModel::setSelectedLevel(std::string level) {
    _selectedLevel = level;
}

std::string GameModel::getSelectedLevel() const {
    return _selectedLevel;
}