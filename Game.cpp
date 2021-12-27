#include "Game.h"

Game::Game()
{
    GameOver = false, MenuClose = false;
    Score = 0;

    SnakeY = Height / 2, SnakeX = Width / 2;
    FoodX = rand() % Width, FoodY = rand() % Height;
}

void Game::StartGame()
{
    this->Game::Game();
    MenuClose = true;
}

void Game::Render()
{
    system("cls");

    SetColor(7, 0);
    for (int i = 0; i <= Width + 1; i++) // UP
    {
        std::cout << "X";
    }
    std::cout << std::endl;

    for (int i = 0; i < Height; i++)
    {
        std::cout << "X";

        for (int b = 0; b < Width; b++)
        {
            if (b == SnakeX && i == SnakeY) // Snake
            {
                SetColor(11, 0);
                std::cout << "O";
                continue;
            }
            bool Space = true;
            for (int k = 0; (k < LocTailSnake[X].size()) && (k < LocTailSnake[Y].size()); k++)
            {
                if (b == LocTailSnake[X][k] && i == LocTailSnake[Y][k])
                {
                    SetColor(3, 0);
                    std::cout << "0";
                    Space = false;
                    break;
                }
            }
            if (b == FoodX && i == FoodY) // Food
            {
                SetColor(5, 0);
                std::cout << "0";
                continue;
            }
            
            if (Space)
            {
                std::cout << " ";
            }
        }

        SetColor(7, 0);
        std::cout << "X" << std::endl;
    }

    for (int i = 0; i <= Width + 1; i++) // DOWN
    {
        std::cout << "X";
    }
    std::cout << std::endl;

    SetColor(4, 0);
    std::cout << "Score : " << Score;
}

void Game::Input()
{
    if (_kbhit()) // Saving input
    {
        switch (tolower(_getch()))
        {
            case 'w':
                if ((Direction::DOWN == DirectionSnake) && (LocTailSnake[Y].size() > 0))
                    break;
                DirectionSnake = Direction::UP;
                break;
            case 's':
                if ((Direction::UP == DirectionSnake) && (LocTailSnake[Y].size() > 0))
                    break;
                DirectionSnake = Direction::DOWN;
                break;
            case 'a':
                if ((Direction::RIGHT == DirectionSnake) && (LocTailSnake[Y].size() > 0))
                    break;
                DirectionSnake = Direction::LEFT;
                break;
            case 'd':
                if ((Direction::LEFT == DirectionSnake) && (LocTailSnake[Y].size() > 0))
                    break;
                DirectionSnake = Direction::RIGHT;
                break;
            case 27: // esc
                MenuClose = false;
                break;
        }
    }
}

void Game::Logic() // Event Handling
{
    if (1 <= LocTailSnake[X].size()) // Lengthening of the tail
    {
        int TempX1 = LocTailSnake[X][0], TempY1 = LocTailSnake[Y][0];
        int TempX2 = 0, TempY2 = 0;

        LocTailSnake[X][0] = SnakeX;
        LocTailSnake[Y][0] = SnakeY;

        for (int i = 1; ((i <= LocTailSnake[X].size() - 1) && (i <= LocTailSnake[Y].size() - 1)); i++)
        {
            if ((1 <= LocTailSnake[X].size() - 1) && (1 <= LocTailSnake[Y].size() - 1))
            {
                TempX2 = LocTailSnake[X][i];
                LocTailSnake[X][i] = TempX1;
                TempX1 = TempX2;

                TempY2 = LocTailSnake[Y][i];
                LocTailSnake[Y][i] = TempY1;
                TempY1 = TempY2;
            }
        }
    }

    switch (DirectionSnake) // Keyboard click processing
    {
        case Direction::UP:
            SnakeY--;
            break;
        case Direction::DOWN:
            SnakeY++;
            break;
        case Direction::LEFT:
            SnakeX--;
            break;
        case Direction::RIGHT:
            SnakeX++;
            break;
    }


    for (int i = 0; (i < LocTailSnake[X].size()) && (i < LocTailSnake[Y].size()); i++) // The snake bumps into its tail?
    {
        if ((SnakeX == LocTailSnake[X][i]) && (SnakeY == LocTailSnake[Y][i]))
            MenuClose = false;
    }


    if (SnakeX == FoodX && SnakeY == FoodY) // Did you eat the food?
    {
        Score += 14;

        FoodX = rand() % Width;
        FoodY = rand() % Height;

        if ((1 <= LocTailSnake[X].size()) && (1 <= LocTailSnake[Y].size()))
        {
            LocTailSnake[X].push_back(LocTailSnake[X][LocTailSnake[X].size() - 1]);
            LocTailSnake[Y].push_back(LocTailSnake[Y][LocTailSnake[Y].size() - 1]);
        }
        else if ((0 == LocTailSnake[X].size()) && (0 <= LocTailSnake[Y].size()))
        {
            LocTailSnake[X].push_back(SnakeX);
            LocTailSnake[Y].push_back(SnakeY);
        }
    }

    if ((SnakeX == Width || SnakeY == Height) || (SnakeX == -1 || SnakeY == -1)) // Border
        MenuClose = false;
}

bool Game::GetGameOver() // Is the game over?
{
    return !GameOver;
}

bool Game::MenuIsClosed()
{
    return !MenuClose;
}

void SetColor(int text, int background) // Sets the color
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Game::MenuCycle()
{
    int ColorText1 = 15;
    int ColorText2 = 7;

    while (MenuIsClosed())
    {
        system("cls");


        SetColor(2, 0);
        std::cout << LogoData << std::endl;


        SetColor(ColorText1, 0);

        if (ColorText1 != 15)
            std::cout << "> Start the game!" << std::endl;
        else
            std::cout << "-> Start the game!" << std::endl;


        SetColor(ColorText2, 0);

        if (ColorText2 != 15)
            std::cout << "> Quit to Windows" << std::endl;
        else
            std::cout << "-> Quit to Windows" << std::endl;


        if (_kbhit())
        {
            switch (tolower(_getch()))
            {
                case 'w': {
                    ColorText1 = 15;
                    ColorText2 = 7;
                    break;
                }
                case 's': {
                    ColorText2 = 15;
                    ColorText1 = 7;
                    break;
                }
                case 13: { // Enter
                    if (ColorText2 == 15) exit(0);

                    MenuClose = true;
                    this->Game::StartGame();
                    break;
                }
            }
        }
    }
}