#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "GameModel.h"
#include "GameView.h"


class GameController {
public:
    GameController();
    void startGame(int levelId);

private:
    GameModel _model;
    GameView* _view;
};

#endif    