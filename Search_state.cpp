//
//  Search_state.cpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/8/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#include "Search_state.h"


Search_state::Search_state(){
    paths.push(vector<location>());
    search_tree.push_back(vector<location>());
}

Search_state::Search_state(location &start_point){
    paths.push(vector<location>());
    search_tree.push_back(vector<location>());
    paths.back().push_back(start_point);
}

void Search_state::clear(){

    while (!paths.empty()) {
        paths.pop();
    }

    history.clear();
    search_tree.clear();
    final_path.clear();
}

// resets the start point and all state
void Search_state::set_start_point(location &start_point){
    clear();
    paths.push(vector<location>());
    paths.back().push_back(start_point);

}
