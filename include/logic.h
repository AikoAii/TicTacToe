#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h>

#define SIDE 3
#define EMPTY_CELL '_'

struct Move {
  int row, col;
};

int evaluate(char b[SIDE][SIDE]);
bool isMovesLeft(char board[SIDE][SIDE]);
int minimax(char board[SIDE][SIDE], int depth, bool isMax);
struct Move findBestMove(char board[SIDE][SIDE]);

#endif
