#pragma once

#include <curses.h>

#include <vector>

void ConsoleInit();
void ConsoleFinish();

void Parse(int num, std::vector<int> &vec);