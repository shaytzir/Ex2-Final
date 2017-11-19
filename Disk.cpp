//
// Shay Tzirin
// ID: 315314930
//

#include "Disk.h"


Disk::Disk() {
    sign_ = ' ';
}


Disk::Disk(char newSign, int diskRow, int diskCol) {
    sign_ = newSign;
    row_ = diskRow;
    col_ = diskCol;
}


void Disk::setSign(char newSign) {
    sign_ = newSign;
}


char Disk::getSign() {
    return sign_;
}
