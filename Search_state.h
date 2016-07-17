//
//  Search_state.hpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/8/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#ifndef Search_state_h
#define Search_state_h

#include <vector>
#include <deque>
#include "location.h"

class Search_state {
public:
    deque<vector <location> >    paths;
    vector <location>           history;
    vector <vector <location> >  search_tree;
    vector <location>           final_path;
    location                    start_point;

    Search_state();
    Search_state(location &start_point);
    // friend ostream& operator<<(std::ostream& os, const Search_state& obj);
    void clear();
    void set_start_point(location &start_point);

};


#endif /* Search_state_hpp */
