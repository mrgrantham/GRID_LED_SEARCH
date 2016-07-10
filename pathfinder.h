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
#include "grid.h"



class pathfinder{
    location goal;
    location grid_bounds;
    Grid test_display;


public:

    pathfinder();

    pathfinder(location &new_goal, location &new_grid_bounds);

    ~pathfinder();

    void set_goal(location &new_goal);

    void set_start_point(location &new_start_point);

    void set_bounds(location &new_grid_bounds);

    void find_path(location &start_point);


};

#endif /* pathfinder_h */
