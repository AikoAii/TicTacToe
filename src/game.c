#include <stdio.h>
#include "game.h"
#include "ui.h"
#include "logic.h"

void initialise(char board[][SIDE]) {
  for (int i = 0; i < SIDE; i++)
    for (int j = 0; j < SIDE; j++) board[i][j] = EMPTY_CELL;
}

int isGameOver(char board[][SIDE]) {
  if (evaluate(board) != 0) return 1;
  return !isMovesLeft(board);
}

void playTicTacToe(int whoseTurn) {
  char board[SIDE][SIDE];
  initialise(board);
  showInstructions();

  while (!isGameOver(board)) {
    if (whoseTurn == COMPUTER) {
      struct Move m = findBestMove(board);
      board[m.row][m.col] = COMPUTERMOVE;
      printf("AI (O) melangkah:\n");
      showBoard(board);
      whoseTurn = HUMAN;
    } else {
      int move, r, c;
      printf("Giliranmu (X) [1-9]: ");
      if (scanf("%d", &move) != 1) {
        while(getchar() != '\n');
        continue;
      }
      r = (move - 1) / 3;
      c = (move - 1) % 3;
      if (move >= 1 && move <= 9 && board[r][c] == EMPTY_CELL) {
        board[r][c] = HUMANMOVE;
        showBoard(board);
        whoseTurn = COMPUTER;
      } else {
        printf("Ilegal!\n");
      }
    }
  }

  int res = evaluate(board);
  if (res == 10) printf("AI Menang!\n");
  else if (res == -10) printf("Kamu Menang!\n");
  else printf("Seri!\n");
}
