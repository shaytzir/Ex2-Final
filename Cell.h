//
// Created by Yuval on 09/11/17.
//

#ifndef REVERSI_CELL_H
#define REVERSI_CELL_H

#include <vector>
#include "Point.h"

using namespace std;

//Cell_t.
//A struct for every cell in the board.
struct cell_t{
    //Column.
    int x;
    //Row.
    int y;
    //All the cells that the player flips if he choose this cell.
    vector <point_t> flip;
};

#endif //REVERSI_CELL_H