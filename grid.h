#include "location.h"
#include "WS2801.h"
#include <vector>
#include <queue>



class Grid : public Adafruit_WS2801 {

    private:
    location goal;
    location grid_bounds;

    uint32_t default_pixel       = 0xAAAAAA;     // WHITE (NOT THAT BRIGHT)
    uint32_t default_goal_pixel  = 0x0000AA;     // BLUE  (DIMMER)
    uint32_t default_blank_pixel = 0x000000;     // BLACK
    int grid_map(int x, int y);


    public:

    Grid();
    Grid(location &new_grid_bounds);
    Grid(int new_grid_width, int new_grid_length);
    void set_bounds(location &new_grid_bounds);
    void set_goal(int x, int y);
    void clear();
    void configure(char new_blank_pixel_symbol, char new_pixel_symbol, char new_goal_pixel);
    void draw_path(vector<location> &path);
    void draw_paths( queue < vector<location> > paths);
    void set_pixel(int x, int y);
    void set_goal_pixel(int x, int y);
    void unset_pixel(int x, int y);


};
