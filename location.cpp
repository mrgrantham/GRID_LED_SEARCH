//
//  location.cpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/4/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#include "location.h"


location::location() {
    x=0;
    y=0;
}

location::location(int x_init, int y_init){
    x = x_init;
    y = y_init;
}

void location::set(int new_x,int new_y){
  x = new_x;
  y = new_y;
}


bool location::operator==(const location &right) const {
    return (this->x == right.x && this->y == right.y);
}

bool location::operator!=(const location &right) const {
    return (this->x != right.x || this->y != right.y);
}

vector<location> location::get_successors(location &grid_bounds) {

    vector<location> successor_array;

    for (int x_inc =-1; x_inc <= 1; x_inc++) {

        for (int y_inc = -1 ; y_inc <= 1; y_inc++) {

            // only add as successor if location
            // is not the same as the original
            // and if only one location (x or y)
            // increments at a time
            if ( (!y_inc && x_inc) || (y_inc && !x_inc)){

                int new_x = this->x + x_inc;
                int new_y = this->y + y_inc;

                if (new_x >= 0 && new_x < grid_bounds.x &&
                    new_y >= 0 && new_y < grid_bounds.y ) {

                    location new_successor(new_x,new_y);
                    successor_array.push_back(new_successor);
                }
            }
        }
    }

    return successor_array;
}
