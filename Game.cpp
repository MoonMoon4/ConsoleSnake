#include "Game.h"

Game::Game() : game_over_(true), score_(0), snake_(std::vector<int>(1, COLS / 2), std::vector<int>(1, LINES / 2), '*'),
      food_f_snake_(std::vector<int>(1, rand() % COLS), std::vector<int>(1, rand() % LINES), '0') {}

void Game::Render() {
    clear();

    attron(COLOR_PAIR(COLOR_RED));
    Put(snake_.loc[X][0], snake_.loc[Y][0], snake_.ch);

    attron(COLOR_PAIR(rand() % 8));
    Put(food_f_snake_.loc[X][0], food_f_snake_.loc[Y][0], food_f_snake_.ch);

    attron(COLOR_PAIR(COLOR_GREEN));
    if (snake_.SnakeSize() >= 2) {
        for (int i = 1; i < snake_.SnakeSize(); i++) {
            Put(snake_.loc[X][i], snake_.loc[Y][i], snake_.ch);
        }
    }

    attron(COLOR_PAIR(COLOR_YELLOW));
    for (int i = 0; i < text_score.size(); i++) {
        Put(0 + i, 0, text_score[i]);
    }

    std::vector<int> numbers;
    Parse(score_, numbers);

    for (int i = 1; i <= numbers.size(); i++) {
        Put(text_score.size() + i, 0, numbers[numbers.size() - i] + 48);
    }
}

void Game::Input() {
    switch (wgetch(stdscr)) {
        case 'w': 
            if (Direction::DOWN != direction_snake_) {
                direction_snake_ = Direction::UP;
            }
            break;
        case 's':  
            if (Direction::UP != direction_snake_) {
                direction_snake_ = Direction::DOWN;
            }
            break;
        case 'a': 
            if (Direction::RIGHT != direction_snake_) {
                direction_snake_ = Direction::LEFT;
            }
            break;
        case 'd': 
            if (Direction::LEFT != direction_snake_) {
                direction_snake_ = Direction::RIGHT;
            }
            break;
    }
}


void Game::Logic() { // Event Handling
    if (2 <= snake_.SnakeSize()) { // Lengthening of the tail 
        snake_.loc[X][1] = snake_.loc[X][0];
        snake_.loc[Y][1] = snake_.loc[Y][0];

        for (int i = 2; i < snake_.SnakeSize(); i++) {
            std::swap(snake_.loc[X][i], snake_.loc[X][i - 1]);
            std::swap(snake_.loc[Y][i], snake_.loc[Y][i - 1]);
        }
    }

    switch (direction_snake_) { // Keyboard click processing
        case Direction::UP: snake_.loc[Y][0]--;
            break;
        case Direction::DOWN: snake_.loc[Y][0]++;
            break;
        case Direction::LEFT: snake_.loc[X][0]--;
            break;
        case Direction::RIGHT: snake_.loc[X][0]++;
            break;
    }

    for (int i = 1; i <= snake_.SnakeSize() - 1; i++) { // The snake bumps into its tail?
        if ((snake_.loc[X][0] == snake_.loc[X][i]) && (snake_.loc[Y][0] == snake_.loc[Y][i])) {
            game_over_ = false;
            break;
        }
    }

    if ((snake_.loc[X][0] == food_f_snake_.loc[X][0]) && (snake_.loc[Y][0] == food_f_snake_.loc[Y][0])) { // Did you eat the food?
        score_ += 14;

        food_f_snake_.loc[X][0] = rand() % COLS;
        food_f_snake_.loc[Y][0] = rand() % LINES;

        snake_.loc[X].push_back(snake_.loc[X][snake_.loc[X].size() - 1]);
        snake_.loc[Y].push_back(snake_.loc[Y][snake_.loc[Y].size() - 1]);
    }

    if (((snake_.loc[X][0] == COLS) || (snake_.loc[Y][0] == LINES)) || ((snake_.loc[X][0] == -1) || (snake_.loc[Y][0] == -1))) { // Border
        game_over_ = false;
    }
}

bool Game::IsGameOver() const { 
    return game_over_;
}

bool Game::MenuIsClosed() const {
    return game_over_;
}

void Game::Put(int x, int y, char ch) const {
    move(y, x);
    addch(ch);
    napms(1);
}