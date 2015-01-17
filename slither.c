// reads snake descriptions and echoes only those words that describe valid snake orientations
// (c) 2014 amelia l. archer

#include <stdlib.h>
#include <stdio.h>

typedef struct hinge {
  int x,y,orient;
} hinge;

int main(int argc, char **argv)
{
  int N = 0;
  int E = 1;
  int S = 2;
  int W = 3;
  int i,j,nextMove;
  char *snakeInput, c;
  hinge *snake = (hinge*)malloc(sizeof(hinge));
  hinge h;

  snakeInput = argv[1];
  snake[0].x = 0;
  snake[0].y = 1;
  snake[0].orient = N;

  i = 0;
  c = snakeInput[i];
  while (c != '\0') {
    snake = realloc(snake, (i+2)*sizeof(hinge));
    if (c == 'S') {
      nextMove = snake[i].orient;
    } else if (c == 'L') {
      nextMove = (snake[i].orient - 1)%4;
    } else if (c == 'R') {
      nextMove = (snake[i].orient + 1)%4;
    } else { return 0; }
    // add next hinge to snake
    if (nextMove == N) {
      snake[i+1].x = snake[i].x;
      snake[i+1].y = snake[i].y +1;
      snake[i+1].orient = N;
    } else if (nextMove == E) {
      snake[i+1].x = snake[i].x +1;
      snake[i+1].y = snake[i].y;
      snake[i+1].orient = E;
    } else if (nextMove == S) {
      snake[i+1].x = snake[i].x;
      snake[i+1].y = snake[i].y -1;
      snake[i+1].orient = S;
    } else {
      snake[i+1].x = snake[i].x -1;
      snake[i+1].y = snake[i].y;
      snake[i+1].orient = W;
    }
    c = snakeInput[++i];
  }
  snake[i+1].orient = 4;
  i = 0;
  while (snake[i].orient != 4) {
    j = i+1;
    while (snake[j].orient != 4) {
      if ((snake[i].x == snake[j].x) && (snake[i].y == snake[j].y)) {
	return 0;
      }
      j++;
    }
    i++;
  }
  printf("%s\n",snakeInput);
}
