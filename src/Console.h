//
// Shay Tzirin
// ID: 315314930
// YUval Hoch
// 204468474
//

#ifndef EX2_CONSOLE_H
#define EX2_CONSOLE_H

#include "Visualization.h"
#include "Board.h"

class Console : public Visualization {
public:
    virtual void printOut(Board* b) const;
    virtual void printError() const;
    virtual void printNoMoreMoves(char player) const;
    virtual void printOptions(char player, vector <cell_t> moves) const;
    virtual void printScore(GeneralPlayer* player1, GeneralPlayer* player2) const;
    virtual void printWinner(char winner) const;
    virtual void openScreen();
private:
    void options(vector <cell_t> moves) const;
    bool isAlreadyIn(vector <cell_t*> print, cell_t c) const;
};

#endif //EX2_CONSOLE_H
