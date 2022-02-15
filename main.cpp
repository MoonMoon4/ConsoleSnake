#include <curses.h>

#include "GameObjects.h"
#include "Game.h"

int main() {
    ConsoleInit();

    Game game_snake;

    while (game_snake.IsGameOver()) {
        // Game.MenuCycle();
        game_snake.Render();
        game_snake.Input();
        game_snake.Logic();
    }

    ConsoleFinish();
}