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
    getMovesForPlayer();
}

ReversiRules::~ReversiRules() {
    delete board_;
    //delete whiteP;
    //delete blackP;
}

void ReversiRules::getMovesForPlayer() {
    //knowing for which player were looking for moves
    char sign = now_->getSign();
    //finding out all locations of the current player on the board
    vector<point_t> locations = getLocationsOfPlayerOnBoard(sign);

    //for each location of the current player -
    for (int i = 0; i < locations.size(); i++) {
        //look for optional moves
        vector<cell_t> possibleMoves = possibleMovesForOneDisk(now_->getSign(), locations[i],
                                                                         later_->getSign());
        //add for the general list of the player
        for (int move = 0; move < possibleMoves.size(); move++) {
            movesForCurrentPlayer.push_back(possibleMoves.at(move));
        }
    }
}

vector<point_t> ReversiRules::getLocationsOfPlayerOnBoard(char sign) {
    vector<point_t> locations;
    //for each row and col in the board
    for (int i = 0; i < board_->getWidth(); i++) {
        for (int j = 0; j < board_->getHeight(); j++) {
            //if its the same sign as we're looking for, add to the vector
            if (board_->getSign(i,j) == sign) {
                struct point_t p;
                p.x = i;
                p.y = j;
                locations.push_back(p);
            }
        }
    }
    return locations;
}


vector<cell_t> ReversiRules::possibleMovesForOneDisk(char current,
                                                     point_t point, char another) { //wanted: returning cell holding vector of possible fliping
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
            while (board_->isInBorders(point.x + vertical, point.y + horizontal) &&
                   (board_->getSign(point.x + vertical,
                                          point.y + horizontal) == another)) {
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
            if (board_->isInBorders(point.x+ vertical, point.y + horizontal)) {
                if ((board_->getSign(point.x + vertical,
                                           point.y + horizontal) == ' ') &&
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


void ReversiRules::nextTurn() {
    stringstream print;
    //prints the updated board
    this->screen_->printOut(this->board_);
    this->screen_->printScore(blackP_,whiteP_);
    //if the current player has no optional moves
    // he presses any key and the turn goes for the other player
    if (this->movesForCurrentPlayer.size() == 0) {
        print<< "no moves for player " << now_->getSign()
             <<" please press any key to pass your turn: ";
        this->screen_->show(print.str());
        string key;
        cin >> key;
        //switching between players
        GeneralPlayer* temp = now_;
        now_ = later_;
        later_ = temp;
        return;
        //if he has moves, let him choose one of them
    } else {
        printMovesForPlayer();
        print << endl << "please choose a cell row,col: ";
        this->screen_->show(print.str());

    }
    string choice;
    cin >> choice;
    //if he didnt type a valid choice, make him choose again
    while (!isThatAnOption(choice)) {
        print.str("");
        print << "you didn't type one of the "
                "option/ you didn't type as pattern 'row,col'"<< endl;
        print << "enter again: 'row,col': ";
        this->screen_->show(print.str());
        cin >> choice;
    }
    //keeps his choice to be sync with matrix
    //(0 to width_-1)(0 to length_-1)
    int row = choice.at(0) -'0' - 1;
    int col = choice.at(2) - '0' - 1;
    //set his choice to have his sign
    setPlayerDisk(row, col);
    //flip any disks standing in the way according to rules
    flipFrom(row, col);
    this->movesForCurrentPlayer.clear();
    //switch between players
    GeneralPlayer* temp = now_;
    now_ = later_;
    later_ = temp;
    getMovesForPlayer();
}

void ReversiRules::printMovesForPlayer() {
    stringstream toShow;
    //gets the optional moves

    vector<string> movesToPrint;
    toShow << "player " << now_->getSign() << " it's your turn " <<endl;
    toShow << "your optional choices are: ";
    this->screen_->show(toShow.str());

    for (int i = 0; i < movesForCurrentPlayer.size(); i++) {
        stringstream location;
        location << "(" << movesForCurrentPlayer[i].x + 1 << "," << movesForCurrentPlayer[i].y + 1 << ")";

         movesToPrint.push_back(location.str());
    }
    sort(movesToPrint.begin(), movesToPrint.end());
    movesToPrint.erase(unique(movesToPrint.begin(), movesToPrint.end()), movesToPrint.end());
    //print any choice from the choices vector
    for (int i = 0; i < movesToPrint.size(); i++) {
        this->screen_->show(movesToPrint[i]);
    }
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
        //print << " player " <<blackP_->getSign() << " won." << endl;
    } else if (scoreWhiteP > scoreBlackP) {
        winner = whiteP_->getSign();
        //print << "player " << whiteP_->getSign() << " won." << endl;
    } else {
        winner = 'T';
        //print << "it's a tie." << endl;
    }
    //print << blackP_->getSign() << ": " << scoreBlackP
          //<< "  " << whiteP_->getSign() << ": " << scoreWhiteP << endl;
    this->screen_->printWinner(winner);
}