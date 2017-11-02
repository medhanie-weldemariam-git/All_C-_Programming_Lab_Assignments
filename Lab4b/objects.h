#ifndef OBJECTS_H
#define OBJECTS_H

#include"console.h"

//Declaration of class 'Paddle'
class Paddle
{
private:
    const char * paddle_coordinate;//---Coordinate of the paddle
    int paddle_width;
    int paddle_height;
public:
    Paddle(Console& console);
    void move(Console& console, char command);
    int paddleBoundary(Console& console);
    void clean(Console& console);//clean paddle existing touches
    void show(Console& console);//show paddle after movement
    int getWidth();//coordinate of paddle W
    int getHeight();//coordinate of paddle H
};

//Declaration of class 'Ball'
class Ball
{
private:
    char ball_coordinate;
    int ball_width;
    int ball_height;
    bool up_down;
    bool left_right;
public:
    Ball();
    void move(Console& console,int height, int width, bool& game_over);
    int ballBoundary(Console& console,int height, int width);
    void clean(Console& console);//clean ball existing touches
    void show(Console& console);//show ball after movement
    void bounce(int boundary);//---When the ball touch the console it changes its direction so that the variableswil also change
    int getWidth();//coordinate of ball Wedith
    int getHeight();//coordinate of ball Height
};
#endif

