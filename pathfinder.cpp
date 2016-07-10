//
//  pathfinder.cpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/4/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#include "pathfinder.h"

pathfinder::pathfinder(){
    goal = location(); // sets (0,0) location default
    grid_bounds = location();
}

pathfinder::pathfinder(location &new_goal, location &new_grid_bounds){
    goal = new_goal;
    grid_bounds = new_grid_bounds;
    test_display = Grid(new_grid_bounds);
    test_display.begin();
}

pathfinder::~pathfinder(){
    //delete test_display;
}

void pathfinder::set_goal(location &new_goal){
   goal = new_goal;
}

// void pathfinder::set_start_point(location &new_start_point){
//   start_point = new_start_point;
// }

void pathfinder::set_bounds(location &new_grid_bounds){
    grid_bounds = new_grid_bounds;
    test_display.set_bounds(grid_bounds);
    test_display.begin();
}





void pathfinder::find_path(location &start_point){
    // Use DFS with random walk for pathing order
    vector<vector<location> > successors_array;
    vector<location> potential_path;

    location *current_location = &start_point;
    vector<location> history; // holds all path references and any places where backtracking took place
    history.push_back(start_point);

    potential_path.push_back(*current_location);

    successors_array.push_back(current_location->get_successors(grid_bounds));
    vector<location> *current_successors = &successors_array.back();

    test_display.set_goal(goal.x, goal.y);

    while(*current_location != goal) {

      test_display.draw_path(potential_path);
      delay(50); 

        bool repeat_visit = false;

        if (!current_successors->empty()) {


            // make sure that each selection from the current_successors vector is random
            random_shuffle(current_successors->begin(), current_successors->end());

            // Check the entire path to see if the next potential path
            // component has been visited before
            for(int i = 0; i < history.size(); i++) {
                if (current_successors->back() == history[i]) {

                    repeat_visit = true;
                }

            }

            if (!repeat_visit) {

                // if this successor has not been visited before it now becomes
                // the new current location
                current_location = &current_successors->back();

                // current_location successors are the new current successors
                successors_array.push_back(current_location->get_successors(grid_bounds));
                current_successors = &successors_array.back();

                // potential path and successors array are both updated
                // with *current* varables
                //
                potential_path.push_back(*current_location);
                history.push_back(*current_location);

            } else {

                // pop repeat visit off the stack
                current_successors->pop_back();
            }

        }
        else {

            // if the current successors are exhausted then pop them off

            successors_array.pop_back();
            potential_path.pop_back();

            // current path was dead end
            // move on level back up the tree
            current_successors = &successors_array.back();
            current_location = &potential_path.back();

            // shuffle successors for random walk
            random_shuffle(current_successors->begin(), current_successors->end());

        }

    }

    // voided so that it would compile
    // return potential_path;
}
