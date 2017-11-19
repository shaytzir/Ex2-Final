//
// Shay Tzirin
// ID: 315314930
//
#include "Console.h"

void Console::show(string toShow) const {
    cout << toShow;
}

void Console::printScore(GeneralPlayer *player1, GeneralPlayer *player2) const {
    cout << "----------------------" << '\n' << "    Current score:" << endl;
    cout << "      " << player1->getSign() << ":" << player1->getScore() << "    "
         << player2->getSign() << ":" << player2->getScore() << '\n' << "----------------------" << endl;
}