

#include "Grid.h"


Grid::Grid(){

}

Grid::Grid(location &new_grid_bounds){
    grid_bounds = new_grid_bounds;
    updateLength(grid_bounds.x * grid_bounds.y);
}

Grid::Grid(int new_grid_width, int new_grid_length){
  grid_bounds.set(new_grid_width,new_grid_length);
}

void Grid::set_bounds(location &new_grid_bounds){
    grid_bounds = new_grid_bounds;
    updateLength(grid_bounds.x * grid_bounds.y);
}

void Grid::set_goal(int x, int y) {
  goal.x = x;
  goal.y = y;
}


void Grid::clear() {
  for (int i = 0; i < this->numPixels(); i++){
    setPixelColor(i,default_blank_pixel);
  }
}
void Grid::configure(char new_blank_pixel_symbol, char new_pixel_symbol, char new_goal_pixel){
    default_blank_pixel = new_blank_pixel_symbol;
    default_pixel     = new_pixel_symbol;
    default_goal_pixel  = new_goal_pixel;
}

void Grid::draw_path(vector<location> &path){
  for (uint32_t i = 0; i < path.size(); i++) {
    this->set_pixel(path[i].x,path[i].y);
  }
}

void Grid::draw_paths(queue< vector <location> > paths){

    int size = (int)paths.size();
    vector<location> temp;

    for (int i = 0; i < size; i++) {
        temp = paths.front();
        draw_path(temp);
        paths.pop();
    }
}

// This grid map is only for a strand arranged
// in a sqaure grid that started int top right corner and
// moves horizontally
void Grid::set_pixel(int x, int y) {

       setPixelColor(grid_map(x,y),default_pixel);
}

void Grid::set_goal_pixel(int x, int y) {

       setPixelColor(grid_map(x,y),default_goal_pixel);
}

void Grid::unset_pixel(int x, int y) {

       setPixelColor(grid_map(x,y),default_blank_pixel);

}

int Grid::grid_map(int x, int y) {

         int max_row_address = grid_bounds.x - 1;
         int column_offset;
         int row_offset;

         if (y % 2 == 0)  {
             column_offset = max_row_address - x;
         } else {
             column_offset = x;
         }

         row_offset = y * grid_bounds.y;

         return row_offset+column_offset;
}
