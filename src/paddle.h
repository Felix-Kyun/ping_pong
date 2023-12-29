#ifndef _PADDLE 
#define _PADDLE
typedef struct Paddle {
  int x;
  float y;
  int len;
  char *body;
} Paddle;

Paddle* init_paddle(int, int);
void update_paddle(Paddle *, float);
void draw_paddle(Paddle*, int);
#endif
