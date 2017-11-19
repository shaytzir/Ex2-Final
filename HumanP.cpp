//
// Shay Tzirin
// ID: 315314930
//

#include "HumanP.h"

HumanP::HumanP(char playerSign) {
    sign_ = playerSign;
    disksNum_ = 2;
}

void HumanP::ScoreUp(int num) {
    disksNum_ = disksNum_ + num;
}

char HumanP::getSign() const {
    return sign_;
}

int HumanP::getScore() const {
    return disksNum_;
}

void HumanP::ScoreDown(int num) {
    disksNum_ = disksNum_ - num;
}
