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
    matrix_ = new char*[width_];
    //which holds arrays
    for (int i = 0; i < width_; i++) {
        matrix_[i] = new char[length_];
    }
    //setting all board to be empty disks
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < length_; j++) {
            matrix_[i][j] = ' ';
        }
    }
    //setting start of the game
    int midRow = width_ / 2;
    int midCol = length_ / 2;
    matrix_[midRow - 1][midCol - 1] = 'O';
    matrix_[midRow + 1 - 1 ][midCol + 1 -1] = 'O';
    matrix_[midRow - 1][midCol + 1 - 1] = 'X';
    matrix_[midRow + 1 - 1][midCol - 1] = 'X';
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
            if (matrix_[i][c] != ' ') {
                boardToShow << ' ' << matrix_[i][c]
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


char Board::getSign(int row, int col) {
    return matrix_[row][col];
}


void Board::setSign(int row, int col, char sign) {
    matrix_[row][col] = sign;
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
            if (matrix_[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


//printBoard.
//Prints the board details - numbers of rows and columns.
void Board::printBoard() {
    int i, j, t;
    cout << "Current board:\n" << endl;
    //For the rows.
    for (j = 0; j < size + 1; j++) {
        if (j == 0) {
            cout << "  ";
        } else { //Print the numbers.
            cout << " " << j;
        }
        //For the columns.
        for (i = 0; i < size + 1; i++) {
            if (j == 0 || i == 0) {
                cout << " | ";
            }
            //Print the numbers.
            if (j == 0 && i != size) {
                cout << i + 1;
            }
            if (j != 0 && i != size) {
                this->printPositions(i, j);
                cout << " | ";
            }
        }//End of second for.
        cout << "" << endl;
        for (t = 0; t < (size + 1) * 4; t++) {
            cout << ".";
        }
        cout << '\n';
    }//End of first for.
}


//printPositions.
//Get i, j variable and prints the matrix[i][j] value.
void Board::printPositions(int i, int j) {
    cout << this->matrix_[i][j] << flush;
}

//freeMatrix.
//Free the memory of the matrix.
void Board::freeMatrix() {
    for (int i = 0; i < size + 1; i++) {
        delete [] this->matrix_[i];
    }
    delete [] this->matrix_;
}

//getMatrix.
char** Board::getMatrix() {
    return this->matrix_;
}

//getSize.
int Board::getSize() {
    return this->size;
}
