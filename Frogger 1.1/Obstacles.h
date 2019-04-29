#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "SDL_Plotter.h"
#include <string>

using namespace std;

class Obstacles
{
private:
    int obs_x,
        obs_y,
        dimen,
        numb,
        speed,
        red,
        green,
        blue;

public:
    Obstacles();
    Obstacles(int x, int y, int speed, int dimen, int num,
              int re, int gr, int bl);

    //set function
    void set_obs_x(int);
    void set_obs_y(int);
    void set_dimen(int);
    void set_numb(int);
    void set_speed(int);
    void set_red(int);
    void set_green(int);
    void set_blue(int);

    //get functions
    int get_obs_x();
    int get_obs_y();
    int get_dimen();
    int get_numb();
    int get_speed();
    int get_red();
    int get_green();
    int get_blue();

    void drawObstacle(SDL_Plotter& g);
};

#endif
