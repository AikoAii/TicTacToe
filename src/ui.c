#include <stdio.h>
#include "ui.h"

void showBoard(char board[][SIDE]) {
  printf("\n");
  for (int i = 0; i < SIDE; i++) {
    printf("\t %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
    if (i < SIDE - 1) printf("\t-----------\n");
  }
  printf("\n");
}

void showInstructions() {
  printf("\nTic-Tac-Toe AI\n");
  printf("\t 1 | 2 | 3 \n\t-----------\n\t 4 | 5 | 6 \n\t-----------\n\t 7 | 8 | 9 \n");
}
