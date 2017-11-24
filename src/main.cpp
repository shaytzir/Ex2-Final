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
    //creates two players
    GeneralPlayer* black = new HumanP('X');
    GeneralPlayer* white = new AIPlayer('O');
    //creates specific visualization for the current game
    Visualization* screen = new Console();
    //creates new game
    GameFlow game(black, white, screen);
    //runs the game
    game.run();
    delete black;
    delete white;
    delete screen;
    return 0;
}