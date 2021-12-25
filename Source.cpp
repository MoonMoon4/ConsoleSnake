#include "Game.h"
#include <iostream>
#include <Windows.h>

int main()
{
    Game Game;
    while (Game.GetGameOver())
    {
        Sleep(200);
        Game.Render();
        Game.Input();
        Game.Logic();
    }
}