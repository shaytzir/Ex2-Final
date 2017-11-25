//
// Created by shay on 11/9/17.
//

#ifndef EX2_CONSOLE_H
#define EX2_CONSOLE_H


#include "Visualization.h"
#include "Board.h"

class Console : public Visualization {
public:
    /**
     *
     * @param toShow the function gets a string and prints it into concole.
     */
    //virtual void show(string toShow) const;

    //Console(Board* b);
    virtual void printOut(Board* b) const;
    virtual void printError() const;
    virtual void printNoMoreMoves(char player) const;
    virtual void printOptions(char player, vector <cell_t> moves) const;
    virtual void printScore(GeneralPlayer* player1, GeneralPlayer* player2) const;
    virtual void printWinner(char winner) const;
private:
    void options(vector <cell_t> moves) const;
    bool isAlreadyIn(vector <cell_t*> print, cell_t c) const;
    //Board* gameBoard;
};


#endif //EX2_CONSOLE_H
