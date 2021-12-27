#include "Game.h"

int main()
{
    Game Game;

    while (Game.GetGameOver())
    {
        Sleep(100);
        Game.MenuCycle();
        Game.Render();
        Game.Input();
        Game.Logic();
    }
}