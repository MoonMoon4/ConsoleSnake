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
    bool GameOver = false;
    bool MenuClose = false;
    const int Width = 20;
    const int Height = 10;
    int Score = 0;

    int SnakeY = Height / 2, SnakeX = Width / 2;
    int FoodX = rand() % Width, FoodY = rand() % Height;

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
    void Render();
    void Input();
    void Logic();
    bool GetGameOver();
    bool MenuIsClosed();
    void MenuCycle();
};

void SetColor(int text, int background);