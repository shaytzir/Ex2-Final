//
// Shay Tzirin
// ID: 315314930
//
#include "GameFlow.h"
#include <iostream>
#include <sstream>


void GameFlow::run() {
    //stringstream toShow;
    //as long as the game isnt over, keep switching turns
    do {
        currentGame_->nextTurn();
    } while (!currentGame_->gameover());
    //when the game is over show who won
    //toShow<< "game is over" << endl;
    //this->screen_->show(toShow.str());

    currentGame_->whoWon();
}

GameFlow::GameFlow(GeneralPlayer* black,
                   GeneralPlayer* white, Visualization* screen) {
    currentGame_ = new ReversiRules(black, white, screen);
    this->screen_ = screen;
}

GameFlow::~GameFlow() {
    delete currentGame_;
}
