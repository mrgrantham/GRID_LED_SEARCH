#include "location.h"
#include "pathfinder.h"
#include "Grid.h"
#include "Search_state.h"

/*#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand*/


location grid_bounds(7,7);
location goal;
location start_point;
pathfinder p_finder;
Grid aGrid(grid_bounds.x,grid_bounds.y);

bool DFS = false;

void setup() {


  srand ( unsigned ( time(0) ) );
  p_finder.set_bounds(grid_bounds);

}

void loop() {


    goal.set(random(7),random(7));
    aGrid.set_goal(goal.x, goal.y);
    p_finder.set(goal, grid_bounds);
    location start_point(random(7),random(7));

    Search_state search_state(start_point);

    bool found_path = false;

    if(DFS) {

        // DEPTH FIRST SEARCH
        while (found_path == false) {

            found_path = p_finder.search_w_DFS(search_state);
            aGrid.draw_paths(search_state.paths);
            aGrid.show();
            aGrid.clear();
            delay(500);
        }
        DFS = false;
    } else {

        // BREADTH FIRST SEARCH
        while (found_path == false) {

            found_path = p_finder.search_w_BFS(search_state);
            aGrid.draw_paths(search_state.paths);
            aGrid.show();
            aGrid.clear();
            delay(500);
        }

        DFS = true;
    }
}
