//
// Shay Tzirin
// ID: 315314930
//
#include <cstdlib>
#include "Console.h"

//Default constructor.
//Console::Console() {}

/*void Console::show(string toShow) const {
    cout << toShow;
}*/

void Console::printScore(GeneralPlayer *player1, GeneralPlayer *player2) const {
    cout << "----------------------" << '\n' << "    Current score:" << endl;
    cout << "      " << player1->getSign() << ":" << player1->getScore() << "    "
         << player2->getSign() << ":" << player2->getScore() << '\n' << "----------------------" << endl;
}

//printOut.
//Print out the board.
void Console::printOut(Board* gameBoard) const {
    cout << gameBoard->printBoard();
}

//printError.
//Print this massage if the input from the player is not from the options.
void Console::printError() const {
    cout << "Your input is not from the options." << endl;
}

//printNoMoreMoves.
//Print this massage if ther are no more move possible moves.
void Console::printNoMoreMoves(char player) const {
    cout << player << " played his move." << '\n'
         << "No possible moves. Play passes back to the other player. Press eny key to continue.";
}

//printOptions.
//Print out all the player possible moves.
void Console::printOptions(char player, vector <cell_t> moves) const {
    cout << player << ": It's your move." << '\n' << "Your possible moves: " << flush;
    this->options(moves);
    cout << '\n' << "Please enter your move row,col: ";
}


//options.
//Print out the player possible moves.
void Console::options(vector <cell_t> moves) const {
    //print - a vector without duplication options.
    vector < cell_t * > print;
    print.push_back(&moves.at(0));
    //For all the possible moves, check if there are to cells the same.
    for (int i = 0; i < moves.size(); i++) {
        if (!isAlreadyIn(print, moves.at(i))) {
            //If the option does'nt already in print, push back into print.
            print.push_back(&moves.at(i));
        }
    }
    //For all the non-duplicate options - print them out.
    for (int i = 0; i < print.size(); i++) {
        cout << "(" << print.at(i)->x + 1 << "," << print.at(i)->y + 1 << ")";
    }
}

//isAlreadyIn.
//Check duplicate options.
bool Console::isAlreadyIn(vector <cell_t*> print, cell_t c) const {
//For teh option in print - if c is already in - return false, else return true.
    for (int i = 0; i < print.size(); i++) {
        if (c.x == print.at(i)->x && c.y == print.at(i)->y) {
            return true;
        }
    }
    return false;
}

//printWinner.
//Print out the winner of this game.
void Console::printWinner(char winner) const {
    cout << "Game over!" << endl;
    if (winner == 'T') {
        cout << "It's a tie!" << endl;
        return;
    }
    cout << winner << " is the winner!!!" << endl;
}