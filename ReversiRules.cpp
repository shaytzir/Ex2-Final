//
// Shay Tzirin
// ID: 315314930
//

#include "ReversiRules.h"
#include <algorithm>
#include <sstream>


ReversiRules::ReversiRules(GeneralPlayer* black, GeneralPlayer* white, Visualization* screen) {
    this->board_ = new Board(8, 8);
    this->whiteP_ = white;
    this->blackP_ = black;
    now_ = blackP_;
    later_ = whiteP_;
    this->screen_ = screen;
}

ReversiRules::~ReversiRules() {
    delete board_;
    //delete whiteP;
    //delete blackP;
}

vector<string> ReversiRules::getMovesForPlayer() {
    //knowing for which player were looking for moves
    char sign = now_->getSign();
    //finding out all locations of the current player on the board
    vector<string> locations = getAllLocations(sign);

    vector<string> movesForPlayer;
    //for each location of the current player -
    for (int i = 0; i < locations.size(); i++) {
        int row = locations.at(i).at(1) - '0'; //at 1 place "(i,j)"
        int col = locations.at(i).at(3) - '0';//at 3 place "(i,j)"
        //look for optional moves
        vector<string> possibleMovesForOneDisk = possibleLocation(now_->getSign(), row, col, later_->getSign());
        //add for the general list of the player
        for (int move = 0; move < possibleMovesForOneDisk.size(); move++) {
            movesForPlayer.push_back(possibleMovesForOneDisk.at(move));
        }
    }
    //sorts the list and checks there are no duplicates
    sort(movesForPlayer.begin(), movesForPlayer.end());
    movesForPlayer.erase(unique(movesForPlayer.begin(), movesForPlayer.end()), movesForPlayer.end());
    return movesForPlayer;
}

vector<string> ReversiRules::getAllLocations(char sign) {
    vector<string> locations;
    //for each row and col in the board
    for (int i = 0; i < board_->getWidth(); i++) {
        for (int j = 0; j < board_->getHeight(); j++) {
            //if its the same sign as we're looking for, add to the vector
            if (board_->whichDiskSign(i, j) == sign) {
                stringstream ss;
                ss << "(" << i << "," << j << ")";
                locations.push_back(ss.str());
            }
        }
    }
    return locations;
}


vector<string> ReversiRules::possibleLocation(char current,
                                              int i, int j, char another) {
    vector<string> possibleMoves;

    //first checking the upper row left to right,
    // mid row left and right, lower row left to right
    for (int vertical = -1; vertical < 2; vertical++) {
        for (int horizontal = -1; horizontal < 2; horizontal++) {
            //keeping the intial values
            int verBackUp = vertical;
            int horBackUp = horizontal;
            //if the disk next to me is in another color
            // keep going that direction until its not in another color
            while (board_->isInBorders(i + vertical, j + horizontal) &&
                   (board_->whichDiskSign(i + vertical,
                                         j + horizontal) == another)) {
                vertical = vertical + verBackUp;
                horizontal = horizontal + horBackUp;
            }
            //if its empty and i moved more than one step -
            // its an optional move for the player
            if (board_->isInBorders(i + vertical, j + horizontal)) {
                if ((board_->whichDiskSign(i + vertical,
                                          j + horizontal) == ' ') &&
                        ((horBackUp != horizontal) ||
                                (verBackUp != vertical))) {
                    stringstream ss;
                    ss << "(" << i + vertical << "," << j + horizontal << ")";
                    possibleMoves.push_back(ss.str());
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
    this->board_->print(this->screen_);
    //if the current player has no optional moves
    // he presses any key and the turn goes for the other player
    if (getMovesForPlayer().size() == 0) {
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

    //switch between players
    GeneralPlayer* temp = now_;
    now_ = later_;
    later_ = temp;
}

void ReversiRules::printMovesForPlayer() {
    stringstream toShow;
    //gets the optional moves
    vector<string> moves = getMovesForPlayer();
    toShow << "player " << now_->getSign() << " it's your turn " <<endl;
    toShow << "your optional choices are: ";
    this->screen_->show(toShow.str());
    //print any choice from the choices vector
    for (int i = 0; i < moves.size(); i++) {

        char row =  moves.at(i).at(1) + 1;
        char col = moves.at(i).at(3) + 1;
        stringstream ss;
        ss << "(" << row << "," << col << ")";
        this->screen_->show(ss.str());
    }
}


bool ReversiRules::gameover() {
    GeneralPlayer* temp = now_;
    if (board_->fullBoard()) {
        return true;
    }
    if ((getMovesForPlayer().size() == 0)) {
        now_ = later_;
        later_ = temp;
        if (getMovesForPlayer().size() == 0) {
            return true;
        }
        temp = later_;
        later_ = now_;
        now_ = temp;
    }
    return false;
}

bool ReversiRules::isThatAnOption(string choice) {
    vector<string> option = getMovesForPlayer();
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
    for (int i = 0; i < option.size(); i++) {
        int optionRow = option.at(i).at(1) - '0';
        int optionCol = option.at(i).at(3) - '0';
        if ((row == optionRow) && (col == optionCol)) {
            return true;
        }
    }
    return false;
}

void ReversiRules::setPlayerDisk(int row, int col) {
    //if we set it on the other player existing disk, we need to
    //reduce the other player score in 1
    if (board_->getDisk(row,col).getSign() == later_->getSign()) {
        later_->ScoreDown(1);
    }
    //if the desired place wasnt of the current player - add 1 to his score
    if (board_->getDisk(row, col).getSign() != now_->getSign()) {
        now_->ScoreUp(1);
    }
    //set the board to have this player disk in the desired position
    board_->SetDisk(row, col, now_->getSign());
}


void ReversiRules::flipFrom(int row, int col) {
    //scaning the area of the new disk, going from the upper row to the lower
    //scanning each row from left to right
    for (int vertical = -1; vertical < 2; vertical++) {
        for (int horizontal = -1; horizontal < 2; horizontal++) {
            //keeping the intial values
            int verBackUp = vertical;
            int horBackUp = horizontal;
            //counting how many disk in a row to flip and change.
            int count = 0;
            //keep going in that direction only if its part of board borders
            if (board_->isInBorders(row + vertical, col + horizontal)) {
                //if the disk next to me is in another color
                // keep going that direction until its not in another color
                while (board_->whichDiskSign
                        (row + vertical, col + horizontal)
                       == later_->getSign()) {
                    vertical = vertical + verBackUp;
                    horizontal = horizontal + horBackUp;
                    //add to the flipping counter
                    count++;
                    //check if the next cell in that
                    // direction is part of the board
                    if (!board_->isInBorders(row + vertical,
                                            col + horizontal)) {
                        break;
                    }
                }
                //if its stops and were stiil in the boad border it means this
                //cell is not in the other color anymore
                if (board_->isInBorders(row + vertical, col + horizontal)) {
                    //it its not empty and
                    // in this player sign- goes back
                    // "count" steps and flip all of other player disks
                    if (board_->whichDiskSign
                            (row +vertical,col +
                                    horizontal)==now_->getSign()) {
                        //goes back the steps
                        for (int c = 0; c < count; c++) {
                            vertical = vertical - verBackUp;
                            horizontal = horizontal - horBackUp;
                            setPlayerDisk(row + vertical, col + horizontal);
                        }
                    }
                }
                vertical = verBackUp;
                horizontal = horBackUp;
            }

        }
    }
}


void ReversiRules::whoWon() {
    stringstream print;
    int scoreBlackP = blackP_->getScore();
    int scoreWhiteP = whiteP_->getScore();
    this->board_->print(this->screen_);
    if (scoreBlackP > scoreWhiteP) {
        print << " player " <<blackP_->getSign() << " won." << endl;
    } else if (scoreWhiteP > scoreBlackP) {
        print << "player " << whiteP_->getSign() << " won." << endl;
    } else {
        print << "it's a tie." << endl;
    }
    print << blackP_->getSign() << ": " << scoreBlackP
          << "  " << whiteP_->getSign() << ": " << scoreWhiteP << endl;
    this->screen_->show(print.str());
}