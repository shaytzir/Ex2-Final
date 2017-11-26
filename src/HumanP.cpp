//
// Shay Tzirin
// ID: 315314930
//

#include <iostream>
#include "HumanP.h"

HumanP::HumanP(char playerSign) {
    sign_ = playerSign;
    disksNum_ = 2;
}

void HumanP::ScoreUp(int num) {
    disksNum_ = disksNum_ + num;
}

char HumanP::getSign() const {
    return sign_;
}

int HumanP::getScore() const {
    return disksNum_;
}

void HumanP::ScoreDown(int num) {
    disksNum_ = disksNum_ - num;
}
vector<cell_t> HumanP::getMovesForPlayer(Board* gameBoard, char sign) const {
    vector<cell_t> movesForCurrentPlayer;
    //finding out all locations of the current player on the board
    vector<point_t> locations = getLocationsOfPlayerOnBoard(this->sign_, gameBoard);
    //for each location of the current player -
    for (int i = 0; i < locations.size(); i++) {
        //look for optional moves
        vector<cell_t> possibleMoves = possibleMovesForOneDisk(this->sign_, locations[i], gameBoard);
        //add for the general list of the player
        for (int move = 0; move < possibleMoves.size(); move++) {
            movesForCurrentPlayer.push_back(possibleMoves.at(move));
        }
    }
    return movesForCurrentPlayer;
}
vector<point_t> HumanP::getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const {
    vector<point_t> locations;
    //for each row and col in the board
    for (int i = 0; i < gameBoard->getWidth(); i++) {
        for (int j = 0; j < gameBoard->getHeight(); j++) {
            //if its the same sign as we're looking for, add to the vector
            if (gameBoard->getSign(i,j) == sign) {
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
vector<cell_t> HumanP::possibleMovesForOneDisk(char current, point_t point, Board* gameBoard) const {
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
                   (gameBoard->getSign(point.x + vertical, point.y + horizontal) != current) &&
                   (gameBoard->getSign(point.x + vertical, point.y + horizontal) != ' ')) {
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
                if ((gameBoard->getSign(point.x + vertical,
                                     point.y + horizontal) == ' ') &&
                    ((horBackUp != horizontal) ||
                     (verBackUp != vertical))) {
                    struct cell_t possibleMove;
                    possibleMove.x = point.x +vertical;
                    possibleMove.y = point.y + horizontal;
                    possibleMove.flip = flippingPoints;
                   // flippingPoints.clear();
                    possibleMoves.push_back(possibleMove);
                }
            }
            flippingPoints.clear();
            //use the back ups to set them back to original,
            //so the changes wont harm the loop
            vertical = verBackUp;
            horizontal = horBackUp;
        }
    }
    return possibleMoves;
}
string HumanP::getNextMove(Board* b) {
    string choice;
    cin >> choice;
    return choice;
}