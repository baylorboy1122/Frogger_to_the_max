/*
Author:                 Darren Carter
Assignment Title:       Frogger
Assignment Description: header file for general frogger classes and functions
Due Date:               5/1/19
Date Created:           4/20/19
Date Last Modified:     4/28/19
*/

#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

#include "SDL_Plotter.h"

/*
description:    draws a sprite from a text file
return:         void
precondition:   string (file name), SDL_Plotter (passed by reference),
                    and 2 doubles (x and y coordinates)
postcondition:  plots each pixel from the file starting with the top left
                    pixel at specified coordinates
*/
void draw(string, SDL_Plotter&, double, double);

class Frog
{
    private:
        double x, y;
        static const double speed = 25;

    public:
/*
description:    constructor for Frog class
return:         none
precondition:   SDL_Plotter passed by reference, 2 doubles for x and y
postcondition:  sets x and y coords of frog and draws frog on screen
*/
        Frog(SDL_Plotter&, double, double);

/*
description:    sets x coordinate of frog
return:         void
precondition:   double for x coord
postcondition:  sets x to passed double
*/
        void setX(double);

/*
description:    sets y coord of frog
return:         void
precondition:   double for y coord
postcondition:  sets y to passed double
*/
        void setY(double);

/*
description:    gets x coordinate of frog
return:         double
precondition:   none
postcondition:  returns value of x coord
*/
        double getX();

/*
description:    gets y coordinate of frog
return:         double
precondition:   none
postcondition:  returns value of y coord
*/
        double getY();

/*
description:    moves frog to the right
return:         void
precondition:   distance moved is constant speed
postcondition:  increases x by speed and redraws frog
*/
        void moveRight(SDL_Plotter&);

/*
description:    moves frog to the left
return:         void
precondition:   distance moved is constant speed
postcondition:  decreases x by speed and redraws frog
*/
        void moveLeft(SDL_Plotter&);

/*
description:    moves frog up
return:         void
precondition:   distance moved is constant speed
postcondition:  decreases y by speed and redraws frog
*/
        void moveUp(SDL_Plotter&);

/*
description:    moves frog down
return:         void
precondition:   distance moved is constant speed
postcondition:  increases y by speed and redraws frog
*/
        void moveDown(SDL_Plotter&);
};

#endif /* GENERAL_H_INCLUDED */
