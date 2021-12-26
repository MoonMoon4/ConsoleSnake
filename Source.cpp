#include "Game.h"


int main()
{
    Game Game;


    while (Game.GetGameOver())
    {
        Game.MenuCycle();
        Sleep(200);
        Game.Render();
        Game.Input();
        Game.Logic();
    }
}