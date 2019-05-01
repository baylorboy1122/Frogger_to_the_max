/*
Author:                 My Nguyen
Assignment Title:       Obstacles.h
Assignment Description: HEADER file for Obstacles library
Due Date:               5/1/19
Date Created:           4/25/19
Date Last Modified:     4/28/19
*/

#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "SDL_Plotter.h"
#include "general.h"
#include <string>

using namespace std;

class Obstacles
{
private:
    int x,
        y,
        max_x,
        max_y,
        dim,
        num,
        speed;

public:

/**
description:    default constructor for the Obstacles class
return:         none
precondition:   none
postcondition:  when the user's input is valid, change x, y, dimension, number
                of obstacles, and speed as the user's input
*/
    Obstacles(SDL_Plotter&, int, int, int , int, int);

    //set function
/**
description:    set x coordinate of the Obstacle object
return:         void
precondition:   valid input is entered
postcondition:  value of x coordinate is changed
*/
    void set_x(int);

/**
description:    set y coordinate of the Obstacle object
return:         void
precondition:   valid input is entered
postcondition:  value of y coordinate is changed
*/
    void set_y(int);

/**
description:    set dimension of the Obstacle object
return:         void
precondition:   valid input is entered
postcondition:  value of dimension is changed
*/
    void set_dim(int);

/**
description:    set the number the Obstacle object being shown at a time
return:         void
precondition:   valid input is entered
postcondition:  value of number of objects being shown is changed
*/
    void set_num(int);

/**
description:    set speed of the Obstacle object
return:         void
precondition:   valid input is entered
postcondition:  value of speed is changed
*/
    void set_speed(int);

    //get functions
/**
description:    get x coordinate of the Obstacle object
return:         int
precondition:   Obstacle object exists
postcondition:  value of x coordinate is unchanged
*/
    int get_x();

/**
description:    get y coordinate of the Obstacle object
return:         int
precondition:   Obstacle object exists
postcondition:  value of y coordinate is unchanged
*/
    int get_y();

/**
description:    get the dimension of the Obstacle object
return:         int
precondition:   Obstacle object exists
postcondition:  value of dimension is unchanged
*/
    int get_dim();

/**
description:    get the number of of the Obstacle object
return:         int
precondition:   Obstacle object exists
postcondition:  value of number of object being shown at a time is unchanged
*/
    int get_num();

/**
description:    get the speed of the Obstacle object
return:         int
precondition:   Obstacle object exists
postcondition:  value of speed is unchanged
*/
    int get_speed();

/**
description:    draw the Obstacle object using SDL Plotter
return:         void
precondition:   Obstacle object exists, SDL_Plotter object being passed by
                reference
postcondition:  values of the private member variables don't change
*/
    void drawObstacle(SDL_Plotter& g);
};

#endif //OBSTACLES_H
