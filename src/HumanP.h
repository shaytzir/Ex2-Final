//
// Shay Tzirin
// ID: 315314930
//

#ifndef EX2_HUMANP_H
#define EX2_HUMANP_H


#include "GeneralPlayer.h"

class HumanP : public GeneralPlayer {
public:
    /**
     * constructor
     * @param playerSign sets the player sign, and sets 2 disks for player
     */
    HumanP(char playerSign);
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
};


#endif //EX2_HUMANP_H
