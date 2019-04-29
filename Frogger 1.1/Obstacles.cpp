#include "SDL_Plotter.h"
#include "Obstacles.h"

Obstacles::Obstacles()
{
    obs_x = 480;
    obs_y = 250;
    dimen = 10;
    numb = 1;
    speed = -10;
    red = 255;
    green = 0;
    blue = 0;
}

Obstacles::Obstacles(int x, int y, int sp, int dim, int num,
                     int re, int gr, int bl)
{
    dimen = 10;
    if (dim >= 10 && dim <= 20)
        dimen = dim;

    obs_x = 500 - 20;
    obs_y = 500 / 2;

    if (x <= 500 - dimen && x >= dimen && y <= 500 - dimen && y >= dimen)
    {
        obs_x = x;
        obs_y = y;
    }

    numb = 1;
    if (num > 0 && num <= 3)
        numb = num;

    //speed = 10;
    //if (speed >= 10 && speed <= 20)
    speed = sp;

    red = 255;
    green = 0;
    blue = 0;

    if (re >= 0 && re <= 255 && gr >=0 && gr <= 255
        && bl >= 0 && bl <= 255)
    {
        red = re;
        green = gr;
        blue = bl;
    }
}

//set function
void Obstacles::set_obs_x(int x)
{
    obs_x = 500 - 20;
    obs_y = 500 / 2;

    if (x <= 500 - dimen*2 && x >= dimen)
        obs_x = x;
}

void Obstacles::set_obs_y(int y)
{
    obs_y = 500 / 2;

    if (y <= 500 - dimen*2 && y >= dimen)
        obs_y = y;

}

void Obstacles::set_dimen(int dim)
{
    dimen = 10;
    if (dim >= 10 && dim <= 20)
        dimen = dim;

}

void Obstacles::set_numb(int num)
{
    numb = 1;
    if (num > 0 && num <= 3)
        numb = num;
}

void Obstacles::set_speed(int sp)
{
    speed = sp;
}

void Obstacles::set_red(int re)
{
    red = 255;

    if (re >= 0 && re <= 255)
        red = re;
}

void Obstacles::set_green(int gr)
{
    green = 0;

    if (gr >=0 && gr <= 255)
        green = gr;
}
void Obstacles::set_blue(int bl)
{
    blue = 0;

    if (bl >= 0 && bl <= 255)
        blue = bl;
}

//get functions
int Obstacles::get_obs_x()
{
    return obs_x;
}

int Obstacles::get_obs_y()
{
    return obs_y;
}

int Obstacles::get_dimen()
{
    return dimen;
}

int Obstacles::get_numb()
{
    return numb;
}

int Obstacles::get_speed()
{
    return speed;
}

int Obstacles::get_red()
{
    return red;
}

int Obstacles::get_green()
{
    return green;
}

int Obstacles::get_blue()
{
    return blue;
}

void Obstacles::drawObstacle(SDL_Plotter& g)
{
    for (int y = 0; y < dimen; y++)
    {
        for (int x = 0; x < dimen; x++)
        {
            for (int c = 0; c < numb; c++)
            {
                g.plotPixel(obs_x + x + -20*c + speed,
                            obs_y + y, red, green, blue);
            }
        }
    }
}
