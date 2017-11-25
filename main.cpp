//
// Shay Tzirin
// ID: 315314930
//

#include "GeneralPlayer.h"
#include "HumanP.h"
#include "AIPlayer.h"
#include "Visualization.h"
#include "GameFlow.h"
#include "Console.h"
#include "Board.h"
int main() {
    GeneralPlayer *black, *white;
    //creates specific visualization for the current game
    Visualization* screen = new Console();
    int choice;
    screen->openScreen();
    cin >> choice;
    //creates two players
    if (choice == 1) {
        black = new HumanP('X');
        white = new HumanP('O');
    } else if (choice == 2) {
        black = new HumanP('X');
        white = new AIPlayer('O');
    }
    //creates new game
    GameFlow game(black, white, screen);
    //runs the game
    game.run();
    delete black;
    delete white;
    delete screen;
    return 0;
}