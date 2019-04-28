/*
Author:                 Darren Carter
Assignment Title:       Frogger
Assignment Description: main file that runs code for frogger
Due Date:               5/1/19
Date Created:           4/20/19
Date Last Modified:     4/28/19
*/

/*
Data Abstraction:   SDL_Plotter g is the display source for everything
                    doubles x and y
                    char key holds the value of the last key pressed by player
                    Frog f is the frog controlled by player

Input:              user inputs arrow keys to control movement of frog

Process:            tests for input in continuous loop and responds accordingly
                        using movement functions from frog class

Output:             displays frog on screen that moves based on user input

Assumptions:        uses SDL_Plotter and general.h
                    all pixels displayed on SDL plotter window
                    user controls frog with arrow keys
*/

#include <iostream>
#include "SDL_Plotter.h"
#include "general.h"
#include <string>

using namespace std;

int main(int argc, char ** argv)
{
    //data abstraction
    SDL_Plotter g(500,500);
    char key;
    Frog f(g, 250, 250);

    //process, input, and output
    while (!g.getQuit())
    {
        g.clear();
        if(g.kbhit())
        {
    	    key = g.getKey();
            switch(key)
            {
                case RIGHT_ARROW: f.moveRight(g);
                                  break;
                case LEFT_ARROW:  f.moveLeft(g);
                                  break;
                case UP_ARROW:    f.moveUp(g);
                                  break;
                case DOWN_ARROW:  f.moveDown(g);
                                  break;
            }
    	}
    }

    return 0;
}
