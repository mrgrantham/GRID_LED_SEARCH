#include "application.h"

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
  Serial.begin(9600);

}

void loop() {


    goal.set(random(7),random(7));
    aGrid.set_goal(goal.x, goal.y);
    p_finder.set(goal, grid_bounds);
    location start_point(random(7),random(7));

    Search_state search_state(start_point);

    bool found_path = false;

    if(DFS) {
      Serial.print("\nDFS Starting\n");
        // DEPTH FIRST SEARCH
        while (found_path == false) {

            found_path = p_finder.search_w_DFS(search_state);
            Serial.print("End Search Round\n");
            aGrid.draw_paths(search_state.paths);
            Serial.print("End Draw\n");
            aGrid.show();
            Serial.print("End Show\n");
            aGrid.clear();
            Serial.print("End Clear\n");

            delay(500);
        }
        Serial.print("DFS Endign\n");

        DFS = false;
    } else {
        Serial.print("\nBFS Starting\n");
        // BREADTH FIRST SEARCH
        while (found_path == false) {

            found_path = p_finder.search_w_BFS(search_state);
            Serial.print("End Search Round\n");
            aGrid.draw_paths(search_state.paths);
            Serial.print("End Draw\n");
            aGrid.show();
            Serial.print("End Show\n");
            aGrid.clear();
            Serial.print("End Clear\n");

            delay(500);
        }
        Serial.print("BFS Ending\n");

        DFS = true;
    }
}
