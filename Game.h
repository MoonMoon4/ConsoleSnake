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
    const int Width = 20;
    const int Height = 10;
    unsigned int Score = 0;

    int SnakeY = Height / 2, SnakeX = Width / 2;
    int FoodY, FoodX;

    std::vector<int> LocTailSnake[2];

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
    void Render();
    void Input();
    void Logic();
    bool GetGameOver();
};

void SetColor(int text, int background);