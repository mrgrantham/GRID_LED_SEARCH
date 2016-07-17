

#include "Grid.h"


Grid::Grid(){

}

Grid::Grid(location new_grid_bounds){
    grid_bounds = new_grid_bounds;

    Serial.print("Display Grid Bounds: ( ");
    Serial.print(grid_bounds.x);
    Serial.print(", ");
    Serial.print(grid_bounds.y);
    Serial.print(")");

    Serial.print("===BEFORE UPDATE LENGTH===");
    Serial.print("Bytes: ");
    Serial.print(sizeof(pixels));
    Serial.print("\n");
    Serial.print("numLEDs: ");
      Serial.print(numLEDs);
      Serial.print("\n");

    uint16_t new_length = grid_bounds.x * grid_bounds.y;
    updateLength(new_length);

    Serial.print("Bytes: ");
    Serial.print(sizeof(pixels));
    Serial.print("\n");
    Serial.print("numLEDs: ");
      Serial.print(numLEDs);
      Serial.print("\n");

      Serial.print("===AFTER UPDATE LENGTH===");


}

Grid::Grid(int new_grid_width, int new_grid_length){
  grid_bounds.set(new_grid_width,new_grid_length);
  updateLength(grid_bounds.x * grid_bounds.y);

}

void Grid::print_pixels(){

  enum colors {RED, GREEN, BLUE};

  for(int i = 0; i < numLEDs; i++){

    Serial.print("Pixel [");
    Serial.print(i);
    Serial.print("]-> ");

    for(int color = 0; color < 3; color++)  {// to print for each color
      if (color == RED) {
        Serial.print(" R: ");
      }
      else if (color == GREEN) {
        Serial.print(" G: ");

      }
      else if (color == BLUE) {
        Serial.print(" B: ");

      }
      Serial.print(pixels[( i * 3 ) + color]);
    }
    Serial.print("\n");
  }
}

void Grid::set_bounds(location new_grid_bounds){
  Serial.print("Display Grid Bounds: ( ");
  Serial.print(grid_bounds.x);
  Serial.print(", ");
  Serial.print(grid_bounds.y);
  Serial.print(")");

  Serial.print("===BEFORE UPDATE LENGTH===");
  Serial.print("Bytes: ");
  Serial.print(sizeof(pixels));
  Serial.print("\n");
  Serial.print("numLEDs: ");
    Serial.print(numLEDs);
    Serial.print("\n");


    grid_bounds = new_grid_bounds;
    updateLength(grid_bounds.x * grid_bounds.y);

        Serial.print("Bytes: ");
        Serial.print(sizeof(pixels));
        Serial.print("\n");
        Serial.print("numLEDs: ");
          Serial.print(numLEDs);
          Serial.print("\n");

          Serial.print("===AFTER UPDATE LENGTH===");

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

void Grid::draw_path(const vector<location> &path){
  for (auto step: path) {
    Serial.print("Path Step: ( ");
    Serial.print(step.x);
    Serial.print(", ");
    Serial.print(step.y);
    Serial.print(")");
    this->set_pixel(step.x,step.y);
  }
  Serial.print("\n");
}

void Grid::draw_paths(const deque< vector <location> > &paths){

    for (auto path: paths) {
        draw_path(path);
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
