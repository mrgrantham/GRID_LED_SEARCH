//
//  pathfinder.hpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/4/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#ifndef pathfinder_h
#define pathfinder_h

#include <vector>
#include <algorithm>    // random_shuffle
#include "location.h"
#include "Search_state.h"



class pathfinder{
    location goal;
    location grid_bounds;
    void remove_priors(vector<location> &history, vector<location> &successors);


public:

    pathfinder();

    pathfinder(location &new_goal, location &new_grid_bounds);
    void set(location &new_goal, location &new_grid_bounds);

    ~pathfinder();

    void set_goal(location &new_goal);

    void set_start_point(location &new_start_point);

    void set_bounds(location &new_grid_bounds);

    bool search_w_DFS(Search_state &search_state); // returns

    bool search_w_BFS(Search_state &search_state);

};

#endif /* pathfinder_h */
