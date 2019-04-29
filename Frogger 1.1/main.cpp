#include <iostream>
#include "SDL_Plotter.h"
#include "Obstacles.h"

using namespace std;

const int PLOT_X  = 500;
const int PLOT_Y = 500;

int main(int argc, char ** argv)
{
    SDL_Plotter g(PLOT_X, PLOT_Y);
    int red = 0,
        green = 200,
        blue = 200;
    int box_x = 250,
        box_y = 490,
        obj_x = 480,
        obj_y = 250;
    int rate = 10,
        timer = 0;
    char key;
    int speed = 10,
        obj_speed = -10;
    Obstacles obs1(obj_x, obj_y, obj_speed, 10, 3, 255, 0, 0),
              obs2;
/*
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
             g.plotPixel(x + obj_x, obj_y + y, 255, 0, 0);
    }
*/
    obs1.drawObstacle(g);

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
            g.plotPixel(box_x + x, box_y + y,red,green,blue);
    }

    while (!g.getQuit())
    {
        if(g.kbhit())
        {
    	    key = g.getKey();
            switch(key)
            {
                case RIGHT_ARROW: box_x += speed;
                                  g.clear();
                                  break;
                case LEFT_ARROW:  box_x -= speed;
                                  g.clear();
                                  break;
                case UP_ARROW:    box_y -= speed;
                                  g.clear();
                                  break;
                case DOWN_ARROW:  box_y += speed;
                                  g.clear();
                                  break;
            }
    	    //cout << static_cast<int>(key) << endl;

            for (int y = 0; y < 10; y++)
            {
                for (int x = 0; x < 10; x++)
                {
                    g.plotPixel(box_x + x,box_y + y,red,green,blue);
                }
            }

            obs1.drawObstacle(g);
    	}

        //update an obsticle after 1000 ms
        if (timer % rate == 0)
        {
            timer = 0;
            obj_speed -= 10;
            obs1.set_speed(obj_speed);

            if (obj_speed < -480)
                obj_speed = 0;

            g.clear();

            for (int y = 0; y < 10; y++)
            {
                for (int x = 0; x < 10; x++)
                {
                    g.plotPixel(box_x + x,box_y + y,red,green,blue);
                 //   cout << "box :" << box_x + x << " " << box_y + y << "\n";
                //    g.plotPixel(x + obj_x, obj_y + y, 255, 0, 0);
                }
            }

        obs1.drawObstacle(g);
        }

        g.update();

        timer++;
    }

    return 0;
}
