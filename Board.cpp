//
// Shay Tzirin
// ID: 315314930
//
#include "Board.h"
#include <iostream>
#include <sstream>

using namespace std;


Board::Board(int wid, int len) {
    width_ = wid;
    length_ = len;
    verticalSep_ = '|';
    horizontalSep_ = '-';
    //creating a dynamic array
    matrix_ = new Disk*[width_];
    //which holds arrays
    for (int i = 0; i < width_; i++) {
        matrix_[i] = new Disk[length_];
    }
    //setting all board to be empty disks
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < length_; j++) {
            matrix_[i][j] = Disk();
        }
    }
    //setting start of the game
    int midRow = width_ / 2;
    int midCol = length_ / 2;
    matrix_[midRow - 1][midCol - 1] = Disk('O', midRow-1, midCol-1);
    matrix_[midRow + 1 - 1 ][midCol + 1 -1] =
            Disk('O', midRow + 1 - 1, midCol + 1 - 1);
    matrix_[midRow - 1][midCol + 1 - 1] =
            Disk('X', midRow - 1, midCol + 1 - 1);
    matrix_[midRow + 1 - 1][midCol - 1] =
            Disk('X', midRow + 1 - 1, midCol - 1);
}

void Board::print(Visualization* screen) {
    //creating the upper border of the table
    stringstream boardToShow;
    boardToShow << endl;
    boardToShow << " curent board is: " << endl;
    for (int i = 0; i < width_; i++) {
        boardToShow << " | " << i+1;
    }
    boardToShow << " " << verticalSep_ << endl;
    for (int i = 0; i < width_; i++) {
        //creating a seperator line of '-'
        for (int j = 0; j < ((width_ * 2) + 1) * 2; j++) {
            boardToShow << horizontalSep_;
        }
        boardToShow << endl;
        for (int c = 0; c < length_; c++) {
            //mark which line it is
            if (c == 0) {
                boardToShow << i + 1 << verticalSep_;
                //if the table hold a player - print it's mark
            }
            if (matrix_[i][c].getSign() != ' ') {
                boardToShow << ' ' << matrix_[i][c].getSign()
                            << ' ' << verticalSep_;
            } else { //keep clear
                boardToShow << "   " << verticalSep_;
            }
        }
        boardToShow << endl;
    }
    //adds the last line of '-'
    for (int j = 0; j < ((width_ * 2) + 1) * 2; j++) {
        boardToShow << horizontalSep_;
    }
    boardToShow << endl;
    screen->show(boardToShow.str());
}


Board::~Board() {
    //frees all arrays kept in the main array
    for (int i = 0; i < width_; i++)
        delete [] matrix_[i];
    //deletes main array
    delete [] matrix_;
}


int Board::getWidth() {
    return this->width_;
}


int Board::getHeight() {
    return this->length_;
}


char Board::whichDiskSign(int row, int col) {
    return getDisk(row,col).getSign();
}

Disk Board::getDisk(int row, int col) {
    return matrix_[row][col];
}


void Board::SetDisk(int row, int col, char sign) {
    matrix_[row][col].setSign(sign);
}


bool Board::isInBorders(int row, int col) {
    if ((!(row < 0)) && (!(row > getHeight() - 1)) && (!(col < 0)) &&
        (!(col > getWidth() - 1))) {
        return true;
    }
    return false;
}


bool Board::fullBoard() {
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < length_; j++) {
            if (matrix_[i][j].getSign() == ' ') {
                return false;
            }
        }
    }
    return true;
}
