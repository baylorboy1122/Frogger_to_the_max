/*
Author:                 Darren Carter
Assignment Title:       Frogger
Assignment Description: implementation of general frogger classes and functions
Due Date:               5/1/19
Date Created:           4/20/19
Date Last Modified:     4/28/19
*/

#include "general.h"
#include <fstream>


void draw(string file, SDL_Plotter& graph, double x, double y)
{
    int r, g, b, j = 0;
    string line;
    ifstream in;

    in.open(file.c_str());

    while(getline(in,line))
    {
        for(int i = 0; (unsigned)i < line.length(); i++)
        {
            r = g = b = 0;
            if(line[i] == 'r')
                r = 255;
            if(line[i] == 'g')
                g = 255;
            if(line[i] == 'b')
                b = 255;
            if(line[i] == 'y')
                r = g = 255;
            if(line[i] == 'p')
                r = b = 255;
            if (line[i] == 'k')
                r = g = b = 0;
            if(line[i] == ' ' || line[i] == '#')
                r = g = b = 255;

            graph.plotPixel(x+i,y+j,r,g,b);
        }
        j++;
    }

    graph.update();
    in.close();
}

Frog::Frog(SDL_Plotter& g, double a, double b)
{
    x = a;
    y = b;
    draw("frogger.txt", g, x, y);
}

void Frog::setX(double a)
{
    x = a;
}

void Frog::setY(double b)
{
    y = b;
}

double Frog::getX()
{
    return x;
}

double Frog::getY()
{
    return y;
}

void Frog::moveRight(SDL_Plotter& g)
{
    if(x + speed <= g.getCol() - 1)
        x += speed;
    draw("frogger.txt", g, x, y);
}

void Frog::moveLeft(SDL_Plotter& g)
{
    if(x - speed >= 0)
        x -= speed;
    draw("frogger.txt", g, x, y);
}

void Frog::moveUp(SDL_Plotter& g)
{
    if(y - speed >= 0)
        y -= speed;
    draw("frogger.txt", g, x, y);
}

void Frog::moveDown(SDL_Plotter& g)
{
    if(y + speed <= g.getRow() - 1)
        y += speed;
    draw("frogger.txt", g, x, y);
}
