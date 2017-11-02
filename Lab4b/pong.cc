#include "console.h"
#include "objects.h"


int main()
{
    Console _console;
    char cmd_move;
    Ball _ball;
    Paddle paddle(_console);
    paddle.show(_console);

    //'a'--> Move paddle to the left
    //'d'--> Move paddle to the right
    //'q'--> Exit game
    bool exist_game = false;
    do
    {
        if (_console.get(cmd_move))
        {
            // implementation of user input process
            if ((cmd_move == 'a') || (cmd_move == 'd'))
            {
                paddle.clean(_console);
                paddle.move(_console,cmd_move);
                paddle.show(_console);
            }
            else if (cmd_move =='q')
                exist_game = true;
        }

        _ball.clean(_console);
        _ball.move(_console,paddle.getHeight(),paddle.getWidth(),exist_game);
        _ball.show(_console);
        // move ball
    }while ( ! exist_game );
    return 0;
}
