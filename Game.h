#pragma once

#include "cctype"
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>

#define X 0
#define Y 1

class Game
{
  private:
    bool GameOver;
    bool MenuClose;

    const int Width = 20;
    const int Height = 10;
    int Score;

    int SnakeY, SnakeX;
    int FoodX, FoodY;

    std::vector<int> LocTailSnake[2];

    const char *LogoData = {" ____              _        \n"
                            "/ ___| _ __   __ _| | _____ \n"
                            "\\___ \\| '_ \\ / _` | |/ / _ \\\n"
                            " ___) | | | | (_| |   <  __/\n"
                            "|____/|_| |_|\\__,_|_|\\_\\___|\n"};

    enum class Direction
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Direction DirectionSnake = Direction::STOP;

  public:
    Game();
    void StartGame();
    void Render();
    void Input();
    void Logic();
    bool GetGameOver();
    bool MenuIsClosed();
    void MenuCycle();
};

void SetColor(int text, int background);