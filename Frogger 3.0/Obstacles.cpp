/*
Author:                 My Nguyen
Assignment Title:       Obstacles.h
Assignment Description: IMPLEMENTATION file for Obstacles library
Due Date:               5/1/19
Date Created:           4/25/19
Date Last Modified:     4/28/19
*/

#include "SDL_Plotter.h"
#include "Obstacles.h"

Obstacles::Obstacles(SDL_Plotter &g, int a, int b, int sp, int dimen, int numb)
{
    dim = 32;
    if (dimen > 0)
        dim = dimen;

    max_x = g.getRow();
    max_y = g.getCol();

    if (a <= max_x - dim || a >= dim
        || b <= max_y - dim || b >= dim)
    {
        x = a;
        y = b;
    }

    speed = sp;

    num = 1;
    if (numb > 0 && numb <= 3)
        num = numb;
}

//set function
void Obstacles::set_x(int a)
{
    x = max_x - dim;

    if (a <= max_x - dim || a >= dim)
        x = a;
}

void Obstacles::set_y(int b)
{
    y = max_y - dim;

    if (b <= max_y - dim || b >= dim)
        y = b;

}

void Obstacles::set_dim(int dimen)
{
    dim = 32;
    if (dimen > 0)
        dim = dimen;
}

void Obstacles::set_num(int numb)
{
    num = 1;
    if (numb > 0 && numb <= 3)
        num = numb;
}

void Obstacles::set_speed(int sp)
{
    speed = sp;
}

//get functions
int Obstacles::get_x()
{
    return x;
}

int Obstacles::get_y()
{
    return y;
}

int Obstacles::get_dim()
{
    return dim;
}

int Obstacles::get_num()
{
    return num;
}

int Obstacles::get_speed()
{
    return speed;
}

void Obstacles::drawObstacle(SDL_Plotter& g)
{
    for (int c = 0; c < num; c++)
        draw("car.txt", g, x + -48*c + speed, y);
}
