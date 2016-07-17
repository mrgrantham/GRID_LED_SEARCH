//
//  location.cpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/4/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#include "location.h"
#include "application.h"

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

    Serial.print("grid_bounds: ( ");
    Serial.print(grid_bounds.x);
    Serial.print(", ");
    Serial.print(grid_bounds.y);
    Serial.print(")\n");

    Serial.print("Original Point: ( ");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
    Serial.print(")\n");

    for (int x_inc =-1; x_inc <= 1; x_inc++) {
      Serial.print("Outer X For loop if for making successors\n");

        for (int y_inc = -1 ; y_inc <= 1; y_inc++) {
          Serial.print("Inner y For loop if for making successors\n");

            // only add as successor if location
            // is not the same as the original
            // and if only one location (x or y)
            // increments at a time
            if ( ( (y_inc == 0) && (x_inc != 0) ) ||
                 ( (y_inc != 0) && (x_inc == 0) ) ){

              Serial.print("Outer if for making successors\n");

                int new_x = this->x + x_inc;
                int new_y = this->y + y_inc;

                if (new_x >= 0 && new_x < grid_bounds.x &&
                    new_y >= 0 && new_y < grid_bounds.y ) {
                    Serial.print("Inner if for making successors\n");
                    location new_successor(new_x,new_y);

                    Serial.print("Current Successor Made: ( ");
                    Serial.print(new_successor.x);
                    Serial.print(", ");
                    Serial.print(new_successor.y);
                    Serial.print(")\n");

                    successor_array.push_back(new_successor);
                }
            }
        }
    }

    Serial.print("successor_array.size(): ");
    Serial.print(successor_array.size());
    Serial.print("\n");
    Serial.print("successor_array: ");

    for(auto item: successor_array) {

      Serial.print(" (");

      Serial.print(item.x);
      Serial.print(", ");

      Serial.print(item.y);
      Serial.print(")  ");

    }
    Serial.print(")\n");


    return successor_array;
}
