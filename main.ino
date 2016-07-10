#include "location.h"
#include "pathfinder.h"

/*#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand*/

int myrandom (int i) { return std::rand()%i;};

location grid_bounds(7,7);
location goal;
location start_point;
pathfinder p_finder;

/*Grid aGrid;*/

void setup() {



  /*Serial.begin(9600);*/

  srand ( unsigned ( time(0) ) );
  p_finder.set_bounds(grid_bounds);


}

void loop() {

  goal.set( myrandom(6), myrandom(6));
  start_point.set( myrandom(6), myrandom(6));
  p_finder.set_goal(goal);
  p_finder.find_path(start_point);

}
