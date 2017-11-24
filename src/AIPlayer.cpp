//
// Created by yuval on 23/11/17.
//

#include <sstream>
#include "AIPlayer.h"

AIPlayer::AIPlayer(char playerSign) {
    sign_ = playerSign;
    disksNum_ = 2;
}

void AIPlayer::ScoreUp(int num) {
    disksNum_ = disksNum_ + num;
}

char AIPlayer::getSign() const {
    return sign_;
}

int AIPlayer::getScore() const {
    return disksNum_;
}

void AIPlayer::ScoreDown(int num) {
    disksNum_ = disksNum_ - num;
}

string AIPlayer::getNextMove(Board* gameBoard) {
    //char **firstMatrix, **checkMatrix;
    int bestChoice[4], score = 0, alreadyChecked = -1;
    string choice;
    //matrix_ = gameBoard->getMatrix();
    vector<cell_t> moves = getMovesForPlayer(gameBoard, this->sign_);
    //firstMatrix = checkMatrix = gameBoard->getMatrix();
    //Get the first choice score.
    bestChoice[0] = moves[0].x + 1;
    bestChoice[1] = moves[0].y + 1;
    bestChoice[2] = setPlayerDisk(moves[0], gameBoard);
    bestChoice[4] = 0;
    //Check the other scores for etch possible choice,
    // if that score is min - put it into bestChoice.
    for (int i = 1; i < moves.size(); i++) {
        if (moves[i].x == bestChoice[0] && moves[i].y == bestChoice[1] && alreadyChecked != i && i != bestChoice[4]) {
            score = setPlayerDisk(moves[i], gameBoard);
            bestChoice[2] += score;
            alreadyChecked = i;
            i = 0;
        } else if (bestChoice[2] > (score = setPlayerDisk(moves[i], gameBoard))) {
            bestChoice[0] = moves[i].x + 1;
            bestChoice[1] = moves[i].y + 1;
            bestChoice[2] = score;
            bestChoice[4] = i;
        }
    }
    stringstream c;
    c << bestChoice[0] << "," << bestChoice[1];
    choice = c.str();
    return choice;
}
vector<cell_t> AIPlayer::getMovesForPlayer(Board* gameBoard, char sign) const {
    vector<cell_t> movesForCurrentPlayer;
    //finding out all locations of the current player on the board
    vector<point_t> locations = getLocationsOfPlayerOnBoard(sign, gameBoard);
    //for each location of the current player -
    for (int i = 0; i < locations.size(); i++) {
        //look for optional moves
        vector<cell_t> possibleMoves = possibleMovesForOneDisk(sign, locations[i], gameBoard);
        //add for the general list of the player
        for (int move = 0; move < possibleMoves.size(); move++) {
            movesForCurrentPlayer.push_back(possibleMoves.at(move));
        }
    }
    return movesForCurrentPlayer;
}
vector<point_t> AIPlayer::getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const {
    vector<point_t> locations;
    //for each row and col in the board
    for (int i = 0; i < gameBoard->getWidth(); i++) {
        for (int j = 0; j < gameBoard->getHeight(); j++) {
            //if its the same sign as we're looking for, add to the vector
            if (gameBoard->getMatrix()[i][j] == sign) {
                struct point_t p;
                p.x = i;
                p.y = j;
                locations.push_back(p);
            }
        }
    }
    return locations;
}

//wanted: returning cell holding vector of possible fliping
vector<cell_t> AIPlayer::possibleMovesForOneDisk(char current, point_t point, Board* &gameBoard) const {
    vector<cell_t> possibleMoves;
    vector<point_t> flippingPoints;
    //first checking the upper row left to right,
    // mid row left and right, lower row left to right
    for (int vertical = -1; vertical < 2; vertical++) {
        for (int horizontal = -1; horizontal < 2; horizontal++) {
            //keeping the intial values
            int verBackUp = vertical;
            int horBackUp = horizontal;
            //if the disk next to me is in another color
            // keep going that direction until its not in another color
            while (gameBoard->isInBorders(point.x + vertical, point.y + horizontal) &&
                   (gameBoard->getMatrix()[point.x + vertical][point.y + horizontal] != current) &&
                   (gameBoard->getMatrix()[point.x + vertical][point.y + horizontal] != ' ')) {
                //add this location as a flipping point for input point
                struct point_t flip;
                flip.x = point.x + vertical;
                flip.y = point.y + horizontal;
                flippingPoints.push_back(flip);

                vertical = vertical + verBackUp;
                horizontal = horizontal + horBackUp;
            }
            //if its empty and i moved more than one step -
            // its an optional move for the player
            if (gameBoard->isInBorders(point.x+ vertical, point.y + horizontal)) {
                if ((gameBoard->getMatrix()[point.x + vertical][point.y + horizontal] == ' ') &&
                    ((horBackUp != horizontal) ||
                     (verBackUp != vertical))) {
                    struct cell_t possibleMove;
                    possibleMove.x = point.x +vertical;
                    possibleMove.y = point.y + horizontal;
                    possibleMove.flip = flippingPoints;
                    flippingPoints.clear();
                    possibleMoves.push_back(possibleMove);
                }
            }
            //use the back ups to set them back to original,
            //so the changes wont harm the loop
            vertical = verBackUp;
            horizontal = horBackUp;
        }
    }
    return possibleMoves;
}
int AIPlayer::setPlayerDisk(cell_t cell, Board* gameBoard) const {
    int otherScore, i, maxScore = 0;
    vector<cell_t> movesForOtherPlayer;
    char otherSign;
    Board boardCopy = new Board(gameBoard);
    boardCopy.getMatrix()[cell.x][cell.y] = this->sign_;
    for (i = 0; i < cell.flip.size(); i ++) {
        boardCopy.getMatrix()[cell.flip[i].x][cell.flip[i].y] = this->sign_;
    }
    //Check the other player sign.
    for (i = 0; i < boardCopy.getHeight(); i++) {
        for (int j = 0; j < boardCopy.getWidth(); j++) {
            if (boardCopy.getMatrix()[i][j] != this->sign_ && boardCopy.getMatrix()[i][j] != ' ') {
                otherSign = boardCopy.getMatrix()[i][j];
                break;
            }
        }
    }
    movesForOtherPlayer = getMovesForPlayer(&boardCopy, otherSign);
    otherScore = 1 + movesForOtherPlayer[0].flip.size();
    for (i = 1; i < movesForOtherPlayer.size(); i++) {
        if (otherScore < (maxScore = movesForOtherPlayer[i].flip.size())) {
            otherScore = maxScore;
        }
    }
    return otherScore;
}