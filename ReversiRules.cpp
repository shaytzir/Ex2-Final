//
// Shay Tzirin
// ID: 315314930
//

#include "ReversiRules.h"
#include "Cell.h"
#include <algorithm>
#include <sstream>
#include <cstring>


ReversiRules::ReversiRules(GeneralPlayer* black, GeneralPlayer* white, Visualization* screen) {
    this->board_ = new Board(8, 8);
    this->whiteP_ = white;
    this->blackP_ = black;
    now_ = blackP_;
    later_ = whiteP_;
    this->screen_ = screen;
    movesForCurrentPlayer = now_->getMovesForPlayer(this->board_, now_->getSign());
}

ReversiRules::~ReversiRules() {
    delete board_;
    //delete whiteP;
    //delete blackP;
}

void ReversiRules::nextTurn() {
    int row = 0, col = 0;
    string choice;
    this->screen_->printOut(this->board_);
    this->screen_->printScore(blackP_,whiteP_);
    //if the current player has no optional moves
    // he presses any key and the turn goes for the other player
    if (this->movesForCurrentPlayer.size() == 0) {
        this->screen_->printNoMoreMoves(now_->getSign());
        string key;
        cin >> key;
        //switching between players
        GeneralPlayer* temp = now_;
        now_ = later_;
        later_ = temp;
        return;
        //if he has moves, let him choose one of them
    } else {
        if (this->now_->getSign() == 'O') {//If the player is AI.
            choice = this->now_->getNextMove(this->board_);
        } else { //If the player is human.
            this->screen_->printOptions(now_->getSign(), this->movesForCurrentPlayer);
            cin >> choice;
            //if he didnt type a valid choice, make him choose again
            while (!isThatAnOption(choice)) {
                this->screen_->printError();
                cin >> choice;
            }
            //keeps his choice to be sync with matrix
            //(0 to width_-1)(0 to length_-1)
        }
    }
    row = choice.at(0) -'0' - 1;
    col = choice.at(2) - '0' - 1;
    //set his choice to have his sign
    setPlayerDisk(row, col);
    //flip any disks standing in the way according to rules
    flipFrom(row, col);
    this->movesForCurrentPlayer.clear();
    //switch between players
    GeneralPlayer* temp = now_;
    now_ = later_;
    later_ = temp;
    this->movesForCurrentPlayer = now_->getMovesForPlayer(this->board_, now_->getSign());
}


bool ReversiRules::gameover() {
    GeneralPlayer* temp = now_;
    if (board_->fullBoard()) {
        return true;
    }
    if ((movesForCurrentPlayer.size() == 0)) {
        now_ = later_;
        later_ = temp;
        if (movesForCurrentPlayer.size() == 0) {
            return true;
        }
        temp = later_;
        later_ = now_;
        now_ = temp;
    }
    return false;
}

bool ReversiRules::isThatAnOption(string choice) {
    //suppose to be of the pattern  "row,col", at least 3 chars
    if (choice.length() < 3) {
        return false;
    }
    if ((choice.at(1) != ',')) {
        return false;
    }
    int row = choice.at(0) -'0' - 1;
    int col = choice.at(2) - '0' - 1;
    //if the choice is part of the vector of choices return true
    for (int i = 0; i < movesForCurrentPlayer.size(); i++) {
        int optionRow = movesForCurrentPlayer.at(i).x;
        int optionCol = movesForCurrentPlayer.at(i).y;
        if ((row == optionRow) && (col == optionCol)) {
            return true;
        }
    }
    return false;
}

void ReversiRules::setPlayerDisk(int row, int col) {
    //if we set it on the other player existing disk, we need to
    //reduce the other player score in 1
    if (board_->getSign(row,col)== later_->getSign()) {
        later_->ScoreDown(1);
    }
    //if the desired place wasnt of the current player - add 1 to his score
    if (board_->getSign(row, col) != now_->getSign()) {
        now_->ScoreUp(1);
    }
    //set the board to have this player disk in the desired position
    board_->setSign(row, col, now_->getSign());
}


void ReversiRules::flipFrom(int row, int col) {

    for (int i = 0; i < movesForCurrentPlayer.size(); i++) {
        if ((movesForCurrentPlayer[i].x == row) && (movesForCurrentPlayer[i].y == col)) {
            for (int j = 0; j < movesForCurrentPlayer[i].flip.size(); j++) {
                setPlayerDisk(movesForCurrentPlayer[i].flip[j].x, movesForCurrentPlayer[i].flip[j].y);
            }
        }
        movesForCurrentPlayer[i].flip.clear();
    }
}


void ReversiRules::whoWon() {
    //stringstream print;
    int scoreBlackP = blackP_->getScore();
    int scoreWhiteP = whiteP_->getScore();
    char winner;
    this->screen_->printOut(this->board_);
    if (scoreBlackP > scoreWhiteP) {
        winner = blackP_->getSign();
    } else if (scoreWhiteP > scoreBlackP) {
        winner = whiteP_->getSign();
    } else {
        winner = 'T';
    }
    this->screen_->printWinner(winner);
}