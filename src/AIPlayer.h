//
// Created by yuval on 23/11/17.
//

#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include "GeneralPlayer.h"

class AIPlayer : public GeneralPlayer {
public:
    /**
    * constructor
    * @param playerSign sets the player sign, and sets 2 disks for player
    */
    AIPlayer(char playerSign);
    /**
    *
    * @param num number of disks to add to the player's score
    */
    void ScoreUp(int num);
    /**
     * setter
     * @param num a number to reduce from this player score
     */
    void ScoreDown(int num);
    /**
     * getter
     * @return the sign of this player
     */
    char getSign() const;
    /**
     * getter
     * @return the score of this player
     */
    int getScore() const;
    vector<cell_t> getMovesForPlayer(Board* gameBoard, char sign) const;

    string getNextMove(Board* b) ;
private:
    vector<point_t> getLocationsOfPlayerOnBoard(char sign, Board* gameBoard) const ;
    vector<cell_t> possibleMovesForOneDisk(char current, point_t point, Board* &gameBoard) const ;
    int setPlayerDisk(cell_t cell, Board* gameBoard) const ;
    char** matrix_;
};
#endif //EX2_AIPLAYER_H
