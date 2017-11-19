//
// Shay Tzirin
// ID: 315314930
//

#ifndef EX2_VISUALIZATION_H
#define EX2_VISUALIZATION_H
using namespace std;
#include <iostream>
#include <string>


class Visualization {
public:
    /**
     *
     * @param toShow the function gets a string and prints it into concole.
     */
    virtual void show(string toShow) const = 0;
};


#endif //EX2_VISUALIZATION_H
