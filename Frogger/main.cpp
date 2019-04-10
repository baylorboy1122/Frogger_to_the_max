#include <iostream>
#include "SDL_Plotter.h"

using namespace std;

int main(int argc, char ** argv)
{
    SDL_Plotter g(500,500);
    int red = 0,
        green = 200,
        blue = 200;
    int box_x = 250,
        box_y = 480;
    char key;
    int speed = 50;

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
            g.plotPixel(box_x + x,box_y + y,red,green,blue);
    }
    g.update();

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
    	    cout << static_cast<int>(key) << endl;

            //Wait(1);

    	     for (int y = 0; y < 10; y++)
            {
                for (int x = 0; x < 10; x++)
                    g.plotPixel(box_x + x,box_y + y,red,green,blue);
            }

            g.update();
    	}

    }

    return 0;
}
