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

// ostream& operator<<(std::ostream& os, const Search_state& state)
// {
//
//     queue<vector<location> > paths = state.paths;
//     int paths_size = (int)paths.size();
//
//     os << "Paths Size: "<< paths_size << "\n";
//
//     os << "Paths: \n";
//     for (int path=0; path < paths_size; path++) {
//         vector<location> a_path = paths.front();
//         os << "Path[" << path << "]: ";
//         for(auto step: a_path){
//             os << " " << step;
//         }
//         paths.pop();
//         os << "\n";
//     }
//     os << "\n";
//
//     os << "History: ";
//     for (auto step: state.history) {
//         os << step << " ";
//     }
//     os << "\n";
//
//     int suc_no = 0;
//     os << "Search Tree: ";
//     for (auto successors : state.search_tree) {
//         cout << "Set[" << suc_no << "]: " ;
//         for(auto successor: successors){
//         os <<  successor << " ";
//         }
//         cout << "\n";
//         suc_no++;
//     }
//     os << "\n";
//
//     os << "Final Path: ";
//     for (auto step: state.final_path) {
//         os << step << " ";
//     }
//     os << "\n";
//
//
//     os << "Start Point: " << state.start_point << "\n\n";
//
//     return os;
// }

// resets the start point and all state
void Search_state::set_start_point(location &start_point){
    clear();
    paths.push(vector<location>());
    paths.back().push_back(start_point);

}
