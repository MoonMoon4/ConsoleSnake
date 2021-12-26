#include "Game.h"

int main()
{
    Game Game;

    Sleep(200);
    while (Game.GetGameOver())
    {
        Game.MenuCycle();
        Game.Render();
        Game.Input();
        Game.Logic();
    }
}