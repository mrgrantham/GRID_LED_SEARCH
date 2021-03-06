//
//  pathfinder.cpp
//  GRID_TEST_X_CODE
//
//  Created by James Grantham on 7/4/16.
//  Copyright © 2016 TESTING. All rights reserved.
//

#include <algorithm>    // random_shuffle
#include "pathfinder.h"
#include "application.h"



void pathfinder::remove_priors(vector<location> &history, vector<location> &successors){

    for (int prev_visit = 0; prev_visit < (int)history.size(); prev_visit++){
        // remove returns an iterator to the new end of the vector
        // then the erase() function deletes the items that were found
        successors.erase(remove(successors.begin(), successors.end(), history[prev_visit]), successors.end());
    }
}

pathfinder::pathfinder(){
    goal = location(); // sets (0,0) location default
    grid_bounds = location();
}

pathfinder::pathfinder(location &new_goal, location &new_grid_bounds){
    goal = new_goal;
    grid_bounds = new_grid_bounds;

}

pathfinder::~pathfinder(){
    //delete test_display;
}

void pathfinder::set(location &new_goal, location &new_grid_bounds){
  goal = new_goal;
  grid_bounds = new_grid_bounds;
}


void pathfinder::set_goal(location &new_goal){
   goal = new_goal;
}

void pathfinder::set_bounds(location &new_grid_bounds){
    grid_bounds = new_grid_bounds;
}



bool pathfinder::search_w_DFS(Search_state &search_state){

    vector<location> &path      = search_state.paths.front();
    vector<location> &history   = search_state.history;

    vector< vector<location> > &tree      = search_state.search_tree;

    tree.push_back(path.back().get_successors(grid_bounds));

    vector<location> &current_successors = tree.back();

    //cout << "STATE **BEFORE** HISTORY REMOVAL\n" << search_state;

    remove_priors(history, current_successors);

    //cout << "STATE **AFTER** HISTORY REMOVAL\n" << search_state;


    if (current_successors.empty()) {
        tree.pop_back(); // no more successors so move back up tree
        path.pop_back(); // this location was not the end goal and its successors were a dead end so pop off
    } else {
        random_shuffle(current_successors.begin(), current_successors.end());
        path.push_back(current_successors.back());
        history.push_back(current_successors.back());

        // now that successor is copied to path it can be removed from the tree of untraversed successors
        current_successors.pop_back();
    }

    location end_of_path = path.back(); // copies location to end_of_path

    return goal == end_of_path; // is the last location in the path the goal?
}







bool pathfinder::search_w_BFS(Search_state &search_state){

    //  Serial.print("Initialize BFS data structures\n");

    vector<location> &path              = search_state.paths.front();
    deque<vector <location>> &paths     = search_state.paths;
    vector<location> &history           = search_state.history;
    //  Serial.print("==DONE==\n");

    //  Serial.print("No. PATHS: ");
    //  Serial.print(paths.size());
    //  Serial.print("\n");

    //  Serial.print("Fetch Successors of Curent\n");
    // maybe use the "tree" vector for storage of the successors to reuse memory
    vector<location> current_successors(path.back().get_successors(grid_bounds));

    //  Serial.print("==DONE==\n");
    //  Serial.print("No. Successors: ");
    //  Serial.print(current_successors.size());
    //  Serial.print("\n");

    //  Serial.print("Remove Prior\n");

    // remove locations already visited by each specific path
    remove_priors(history, current_successors);

    random_shuffle(current_successors.begin(), current_successors.end());

    //  Serial.print("==DONE==\n");

    //  Serial.print("No. Successors: ");
    //  Serial.print(current_successors.size());
    //  Serial.print("\n");

    bool goal_reached = false;

    //  Serial.print("Create New Path Branches\n");

    // split off path into as many new paths as there are successors
    for (vector<location>::iterator new_step = current_successors.begin(); new_step != current_successors.end(); new_step++) {

      //  Serial.print("Iterating through successor\n");


      //  Serial.print("Push Successor onto list of Prior Visits\n");
      //  Serial.print("Size of Prior visit list BEFORE: ");
      //  Serial.print(history.size());
      //  Serial.print("\n");
        // add to list of prior visits
        history.push_back(*new_step);

      //  Serial.print("Size of Prior visit list AFTER: ");
      //  Serial.print(history.size());
      //  Serial.print("\n");


      //  Serial.print("Create new vector based on original path to add this successor to\n");
        vector<location> temp_path(path);
        //  Serial.print("Size of new vector: ");
        //  Serial.print(temp_path.size());
        //  Serial.print("\n");


        //  Serial.print("Add successor to new path\n");

        temp_path.push_back(*new_step);

        //  Serial.print("Size of modified PATH vector: ");
        //  Serial.print(temp_path.size());
        //  Serial.print("\n");


        //  Serial.print("Add new path to vector of paths\n");

        paths.push_back(temp_path);

        //  Serial.print("Size of modified PATHS vector: ");
        //  Serial.print(paths.size());
        //  Serial.print("\n");


        //  Serial.print("Check if current successor matchs the saught\nafter goal state");

        if(*new_step == goal) {
            search_state.final_path = temp_path;
            goal_reached = true;
            //  Serial.print("==GOAL FOUND==\n");

        }

        //  Serial.print("End of Successor loop iteration\n");

    }
    //  Serial.print("==DONE==\n");

    //  Serial.print("Remove the Original Path\n");

    paths.pop_front();

    //  Serial.print("==DONE==\n");

    return goal_reached;

}
