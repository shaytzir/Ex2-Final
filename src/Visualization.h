//
// Shay Tzirin
// ID: 315314930
//

#ifndef EX2_VISUALIZATION_H
#define EX2_VISUALIZATION_H
using namespace std;
#include <iostream>
#include <string>
#include "GeneralPlayer.h"
#include "Cell.h"
#include "Board.h"

class Visualization {
public:
    /**
     *
     * @param toShow the function gets a string and prints it into concole.
     */
    //virtual void show(string toShow) const = 0;
    virtual void printScore(GeneralPlayer* player1, GeneralPlayer* player2) const = 0;
    Visualization() {};
    //Visualization(Board* b) {};
    virtual void printOut(Board* gameBoard) const = 0;
    virtual void printError() const = 0;
    virtual void printNoMoreMoves(char player) const = 0;
    virtual void printOptions(char player, std::vector <cell_t> moves) const = 0;
    virtual void printWinner(char winner) const = 0;
private:
    //Board* gameBoard;

};


#endif //EX2_VISUALIZATION_H
