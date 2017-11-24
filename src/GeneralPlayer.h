//
// Shay Tzirin
// ID: 315314930
//

#ifndef EX2_GENERALPLAYER_H
#define EX2_GENERALPLAYER_H

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
protected:
    char sign_;
    int disksNum_;
};


#endif //EX2_GENERALPLAYER_H
