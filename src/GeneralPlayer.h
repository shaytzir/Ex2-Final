//
// Shay Tzirin
// ID: 315314930
// YUval Hoch
// 204468474
//

#ifndef EX2_GENERALPLAYER_H
#define EX2_GENERALPLAYER_H

#include <string>
#include "Board.h"
#include "Cell.h"
using namespace std;

class GeneralPlayer {
public:
    /**
     *
     * @param num number of disks to add to the player's score
     */
    virtual void ScoreUp(int num) = 0;
    /**
     * setter
     * @param num a number to reduce from this player score
     */
    virtual void ScoreDown(int num) = 0;
    /**
     * getter
     * @return the sign of this player
     */
    virtual char getSign() const = 0;
    /**
     * getter
     * @return the score of this player
     */
    virtual int getScore() const = 0;

    virtual string getNextMove(Board* b) = 0;
    virtual vector<cell_t> getMovesForPlayer(Board* gameBoard, char sign) const = 0;
protected:
    char sign_;
    int disksNum_;
};

#endif //EX2_GENERALPLAYER_H
