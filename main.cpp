//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <cstdlib>
#include "GeneralPlayer.h"
#include "HumanP.h"
#include "AIPlayer.h"
#include "Visualization.h"
#include "GameFlow.h"
#include "Console.h"
#include "Client.h"

int main() {

    Client client("127.0.0.1", 8000);
    //Client client2("127.0.0.1", 8001);
    try {
        client.connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
    }
    int num1, num2;
    char op;
    while (true) {
        cout << "Enter an exercise (e.g., 15*19):";
        cin >> num1 >> op >> num2;
        cout << "Sending exercise: " << num1 << op << num2 << endl;
        try {
            int result = client.sendExercise(num1, op, num2);
            cout << "Result: " << result << endl;
        } catch (const char *msg) {
            cout << "Failed to send exercise to server. Reason: " << msg << endl;
        }
    }
    /*int num1, num2;
    char op;
    GeneralPlayer *black, *white;
    //creates specific visualization for the current game
    Visualization* screen = new Console();
    int choice;
    screen->openScreen();
    cin >> choice;
    //create two players
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
    return 0;*/
}