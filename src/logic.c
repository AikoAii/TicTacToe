#include "logic.h"

static char ai_char = 'o', user_char = 'x';

bool isMovesLeft(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == EMPTY_CELL) {
        return true;
      }
    }
  }
  return false;
}

int evaluate(char b[3][3]) {
  for (int i = 0; i < 3; i++) {
    if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != EMPTY_CELL)
      return (b[i][0] == ai_char) ? +10 : -10;
    if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != EMPTY_CELL)
      return (b[0][i] == ai_char) ? +10 : -10;
  }
  if (b[1][1] != EMPTY_CELL) {
    if ((b[0][0] == b[1][1] && b[1][1] == b[2][2]) ||
      (b[0][2] == b[1][1] && b[1][1] == b[2][0]))
      return (b[1][1] == ai_char) ? +10 : -10;
  }
  return 0;
}

int minimax(char board[3][3], int depth, bool isMax) {
  int score = evaluate(board);
  if (score == 10 || score == -10) return score;
  if (!isMovesLeft(board)) return 0;

  int best = isMax ? -1000 : 1000;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == EMPTY_CELL) {
        board[i][j] = isMax ? ai_char : user_char;
        int val = minimax(board, depth + 1, !isMax);
        board[i][j] = EMPTY_CELL;
        if (isMax) {
          if (val > best) best = val;
        } else {
          if (val < best) best = val;
        }
      }
    }
  }
  return best;
}

struct Move findBestMove(char board[3][3]) {
  int bestVal = -1000;
  struct Move bestMove = {-1, -1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == EMPTY_CELL) {
        board[i][j] = ai_char;
        int moveVal = minimax(board, 0, false);
        board[i][j] = EMPTY_CELL;
        if (moveVal > bestVal) {
          bestMove.row = i;
          bestMove.col = j;
          bestVal = moveVal;
        }
      }
    }
  }
  return bestMove;
}
