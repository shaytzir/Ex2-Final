//
// Created by shay on 11/9/17.
//

#ifndef EX2_CONSOLE_H
#define EX2_CONSOLE_H


#include "Visualization.h"

class Console : public Visualization {
public:
    /**
     *
     * @param toShow the function gets a string and prints it into concole.
     */
    virtual void show(string toShow) const;

};


#endif //EX2_CONSOLE_H
