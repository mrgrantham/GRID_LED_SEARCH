//
//  location.hpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/4/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#ifndef location_h
#define location_h

#include <vector>

using namespace std;

class  location{

public:

    int x;
    int y;

    location();
    location(int x_init, int y_init);
    void set(int new_x,int new_y);

    // friend ostream& operator<<(std::ostream& os, const location& obj);
    bool operator==(const location &right) const;
    bool operator!=(const location &right) const;

    vector<location> get_successors(location &grid_bounds);

};

#endif /* location_h */
