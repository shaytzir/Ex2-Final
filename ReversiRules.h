//
// Shay Tzirin
// ID: 315314930
//
#ifndef EX2_REVERSIRULES_H
#define EX2_REVERSIRULES_H

#include "Cell.h"
#include "Board.h"
#include "GeneralPlayer.h"
#include "Visualization.h"

using namespace std;
#include <iostream>
#include <vector>
#include <string>
class ReversiRules {
public:
    /**
     *  constructor.
     * @param black first player
     * @param white  secone player
     * @param screen a screen to show the game on
     */
    ReversiRules(GeneralPlayer* black, GeneralPlayer* white, Visualization* screen);
    /**
     * destructor
     */
    ~ReversiRules();
    /**
     * responsible for the next turn for each player
     */
    void nextTurn();
    /**
     * check if the game is over
     * @return true if there no more moves
     * for both/or the board is full, false otherwise
     */
    bool gameover();
    /**
     *after a disk was set, the func checks which other disk next to it to flip
     * @param row the new disk row in board
     * @param col the new disk col in board
     */
    void flipFrom(int row, int col);
    /**
     *
     * @param choice the string the user typed as a choice
     * @return true if its a valid choice, false otherwise
     */
    bool isThatAnOption(string choice);

    /**
     * set the board to have the current player sign at the
     * desired position, updated scores of players according to the history
     * of the disk
     * @param row wanted row in board
     * @param col wanted col in board
     */
    void setPlayerDisk(int row, int col);

    /**
     * print the moves the player can choose from
     */
    //void printMovesForPlayer();
    /**
     * finds possible moves for current player turn
     * @return a vector containing strings of optional moves
     */
    //void getMovesForPlayer();
    /**
     *
     * @param sign char sign of a specific player
     * @return all locations of that sign in the board
     */
    //vector<point_t> getLocationsOfPlayerOnBoard(char sign);
    /**
     * return possible moves of a specific disk
     * @param current sign of the current player
     * @param i current row of the disk
     * @param j current col of the disk
     * @param another the sign of the other player
     * @return vector of possible moves for a specific disk
     */
    //vector<cell_t> possibleMovesForOneDisk(char current, point_t point, char another);
    /**
     * comparing scores and declaring
     * who won after showing the last board
     */
    void whoWon();
private:
    Board* board_;
    GeneralPlayer* whiteP_;
    GeneralPlayer* blackP_;
    GeneralPlayer* now_;
    GeneralPlayer* later_;
    vector<cell_t> movesForCurrentPlayer;
    Visualization* screen_;
};


#endif //EX2_REVERSIRULES_H
