//
// Shay Tzirin
// ID: 315314930
//

#ifndef EX2_BOARD_H
#define EX2_BOARD_H


#include "Visualization.h"

class Board {
public:
    /**
     * a constructor.
     * @param wid width of table
     * @param len length of table
     */
    Board(int width, int length);
    Board();
    /**
     * a destructor.
     */
    ~Board();
    /**
     * this function print the table of the game with the players set.
     */
    void print(Visualization* screen);
    /**
     *
     * @param row row of cell to check
     * @param col  col of cell to check
     * @return sign of the cell row,col
     */
   // char whichDiskSign(int row, int col);
    /**
     *
     * @param row
     * @param col
     * @return yes if row,col if part of the matrix
     */
    bool isInBorders(int row, int col);
    /**
     *
     * @return true if of all cells are set, otherwise false
     */
    bool fullBoard();
    /**
     *
     * @param row
     * @param col
     * @return  the disk which is in row,col cell
     */
    char getSign(int row, int col);
    /**
     *
     * @param row
     * @param col
     * @param sign setting the disk at the row,col cell to have another sign
     */
    void setSign(int row, int col, char sign);
    /**
     *
     * @return width of matrix
     */
    int getWidth();
    /**
     *
     * @return length of matrix
     */
    int getHeight();

    Board(int size, char player1, char player2);
    void printBoard();
    void printPositions(int i, int j);
  //  void setStartPositions();
    void freeMatrix();
    char** getMatrix();
    int getSize();

private:
    int width_;
    int length_;
    char verticalSep_; //vertical seperator
    char horizontalSep_; //horizontal
   // Disk** matrix_;

    char **matrix_;
    int size;
    char p1;
    char p2;
};


#endif //EX2_BOARD_H
