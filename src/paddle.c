#include "paddle.h"
#include "flib.h"
#include "notify.h"
#include "setting.h"
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

// FIX: check bounds before init
Paddle *init_paddle(int y, int x) {
  Paddle *p = (Paddle *)malloc(sizeof(Paddle));

  // init
  p->x = x;
  p->y = (float)y;
  p->len = PADDLE_LEN;
  p->body = PADDLE_ICON;

  // draw the paddle
  draw_paddle(p, 1);

  return p;
}

void update_paddle(Paddle *p, float addy) {
  static unsigned int test_counter;
  if (addy == 0 || p->y + addy + p->len > LINES - 1 || p->y + addy <= 0)
    return;
  if ((int)p->y == (int)(p->y + addy)) {
    notify(itoa((long)(abs(p->y * 100))), 1);
    p->y += addy;
    return;
  } else {
    draw_paddle(p, 0);
    p->y += addy;
    draw_paddle(p, 1);
  }
}

// FIX: check bounds before draw
void draw_paddle(Paddle *p, int status) {
  extern int LINES;
  // if status then set ch to p.body else its ' '
  char *ch = (status) ? p->body : " ";
  // draw the char on y axis
  for (int i = p->y; i < p->y + p->len + ((!strcmp(ch, " ")) ? 1 : 0); i++) {
    // for (int i = p->y; i < p->y + p->len ; i++) {
    mvaddstr(i, p->x, ch);
  }
}
