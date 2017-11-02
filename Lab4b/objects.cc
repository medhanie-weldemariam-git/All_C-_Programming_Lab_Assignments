#include"objects.h"

using namespace std;

//----Constructor of the ball (ball class)
Ball::Ball() : ball_coordinate('o'), ball_width(1), ball_height(1),up_down(true), left_right(false)
{
    //---default values that the ball will come up with when the game starts
}

//---Show the ball as it moves
void Ball::show(Console& console)
{
    console.setPos(ball_width,ball_height);
    console.put(ball_coordinate);
}

//--- Clean the ball's old point as it moves from one direction to the other
void Ball::clean(Console& console)
{
    console.setPos(ball_width,ball_height);
    console.put(" ");
}

//--- Possible coordinates where the ball can be in, locate and return a value that tells about is coordinate
int Ball::ballBoundary(Console& console,int p_height, int p_width)
{

    if ((ball_width == 0)&&(ball_height==0))
        return 1;//Top left
    else if ((ball_width == (console.getWidth() -1))&&(ball_height==0))
        return 2;//Top right
    else if(ball_width == (console.getWidth() -1))
        return 3;// Right
    else if (ball_width == 0)
        return 4;// Top wall
    else if ((ball_height == (p_height-1)) && ((p_width-1<=ball_width)&&((p_width+6)>=ball_width)))
        return 5;// Trying to check where tha paddle is
    else if (ball_height == 0)
        return 6;// When the ball is in the left wall
    else if(ball_height == (console.getHeight() -1))
        return 7;// when the ball is touching the game over place
    else
        return 8;//---otherwise it moves in colsole
}
//--- Define how the ball coordinate values will be changed as the ball is moving
void Ball::move(Console& console,int ballHeight, int ballWidth,bool& game_over)
{
    int ball_boundary = ballBoundary(console,ballHeight,ballWidth);

    if(ball_boundary == 8)
    {
        if (up_down)
            ball_height+=1;
        else
            ball_height-=1;

        if (left_right)
            ball_width-=1;
        else
            ball_width+=1;
    }
    // If it is touching the game over part, you will lose the game
    else if (ball_boundary == 7)
        game_over = true;
    else
        // if it is touching some part of the walls you have to change the direction
        bounce(ball_boundary);
}

//--Change the direction of the ball depending where you are
void Ball::bounce(int boundary)
{
    if(boundary==1)
    {
        up_down = true;
        left_right = false;
        ball_height+=1;
        ball_width+=1;
    }
    else if(boundary==2)
    {
        up_down = true;
        left_right = true;
        ball_height+=1;
        ball_width-=1;
    }
    else if(boundary==3)
    {
        left_right = true;
        ball_width-=1;
    }
    /*You touch the left part of the Wall so you have to
     * change the direction to the right, so you increase the ball_width*/
    else if(boundary==4)
    {
        left_right = false;
        ball_width+=1;
    }
    else if(boundary==5)
    {
        up_down = false;
        ball_height-=1;
    }
    // If you touch the top part of the wall you have to change direction to the down and increase ball_height
    else if(boundary==6)
    {
        up_down = true;
        ball_height+=1;
    }
}

int Ball::getWidth()
{
    return ball_width;
}

int Ball::getHeight()
{	
    return ball_height;
}

//----Paddle constructor
Paddle::Paddle(Console& console) : paddle_coordinate("-------"), paddle_width(console.getWidth()/2), paddle_height(console.getHeight() - 4){}

//---Show the paddle
void Paddle::show(Console& console)
{
    console.setPos(paddle_width,paddle_height);
    console.put(paddle_coordinate);
}

void Paddle::clean(Console& console)
{
    console.setPos(paddle_width,paddle_height);
    console.put("        ");
}
void Paddle::move(Console& console,char command)
{
    if (paddleBoundary(console)==1 && command == 'd')
    {
        paddle_width+=1;
    }
    else if(paddleBoundary(console)==2&& command == 'a')
    {
        paddle_width-=1;
    }
    else if (command == 'd')
    {
        paddle_width+=1;
    }
    else
        paddle_width-=1;
}
int Paddle::paddleBoundary(Console& console)
{
    if (paddle_width == 0)
        return 1;
    else if(paddle_width == (console.getWidth() -1))
        return 2;
    else
        return 3;
}

int Paddle::getWidth()
{
    return paddle_width;
}

int Paddle::getHeight()
{	
    return paddle_height;
}


