#include <curses.h>

#include "GameObjects.h"
#include "Game.h"

int main() {
    ConsoleInit();

    srand(time(NULL));

    Game game_snake;

    while (game_snake.IsGameOver()) {
        game_snake.Render();
        game_snake.Input();
        game_snake.Logic();
    }

    ConsoleFinish();
}