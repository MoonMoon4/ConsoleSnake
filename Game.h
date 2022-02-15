#pragma once

#include <curses.h>

#include <iostream>
#include <string>
#include <vector>

#include "AdditionalFunctions.h"
#include "GameObjects.h"

class Game {

    bool game_over_;

    int score_;

    Snake snake_;
    Food food_f_snake_;

    const std::string logo_data_ =   {" ____              _        \n"
                                    "/ ___| _ __   __ _| | _____ \n"
                                    "\\___ \\| '_ \\ / _` | |/ / _ \\\n"
                                    " ___) | | | | (_| |   <  __/\n"
                                    "|____/|_| |_|\\__,_|_|\\_\\___|\n"};

    const std::string text_score = "SCORE";

    enum class Direction {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    Direction direction_snake_ = Direction::STOP;

  public:
    Game();
    void Render();
    void Input();
    void Logic();
    void Put(int x, int y, char ch) const;
    bool IsGameOver() const;
    bool MenuIsClosed() const;
};