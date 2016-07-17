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
Grid aGrid;

bool DFS = false;

void setup() {

  Serial.begin(9600);
  aGrid.set_bounds(grid_bounds);
  Serial.print("grid_bounds in Setup(): (");
  Serial.print(grid_bounds.x);
  Serial.print(", ");
  Serial.print(grid_bounds.y);
  Serial.print(")\n");

  aGrid.begin();


  srand ( unsigned ( time(0) ) );
  p_finder.set_bounds(grid_bounds);

}

void loop() {
    // Set the goal for this loop
    goal.set(random(7),random(7));

    // Configure the grid layout to be able to display that goal
    aGrid.set_goal(goal.x, goal.y);

    // Configure the pathfinder object with the new goal and the grid bounds
    // established
    p_finder.set(goal, grid_bounds);

    // Set a new start point for this round from which to find the goal
    location start_point(random(7),random(7));

    // Create a search state object to hold the relevant working and final data
    Search_state search_state(start_point);

    bool found_path = false;

    if(DFS) {
      Serial.print("\n\nDFS Starting\n");
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
        Serial.print("\n\nBFS Starting\n");
        // BREADTH FIRST SEARCH
        while (found_path == false) {

            found_path = p_finder.search_w_BFS(search_state);
            Serial.print("End Search Round\n");
            Serial.print("No. Paths: ");
            Serial.print(search_state.paths.size());
            Serial.print("\n");
            aGrid.draw_paths(search_state.paths);
            Serial.print("End Draw\n");
            Serial.print("Print Pixels BEFORE Show\n");
            aGrid.print_pixels();
            aGrid.show();
            Serial.print("Print Pixels AFTER Show\n");
            aGrid.print_pixels();
            Serial.print("End Show\n");
            aGrid.clear();
            Serial.print("End Clear\n");

            delay(500);
        }
        Serial.print("BFS Ending\n");

        DFS = true;
    }
}
