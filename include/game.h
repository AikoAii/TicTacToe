#ifndef GAME_H
#define GAME_H

#define SIDE 3
#define COMPUTER 1
#define HUMAN 2
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'

void initialise(char board[][SIDE]);
int isGameOver(char board[][SIDE]);
void playTicTacToe(int whoseTurn);

#endif
