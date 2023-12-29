#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include "auto.h"
#include "ball.h"
#include "notify.h"
#include "paddle.h"
#include "ping.h"
#include "setting.h"

int main(int argc, const char **argv) {
  // init
  setlocale(LC_ALL, ""); // to add unicode support
  initscr();
  noecho();
  raw();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);

  // add some sexy border
  box(stdscr, 0, 0);
  mvaddstr(0, 0, "╭");                // tl
  mvaddstr(0, COLS - 1, "╮");         // tr
  mvaddstr(LINES - 1, 0, "╰");        // bl
  mvaddstr(LINES - 1, COLS - 1, "╯"); // br
  refresh();

  // main
  // user paddle
  Paddle *p1 = init_paddle(1, 1);
  // ai based paddle
  Paddle *p2 = init_paddle(1, COLS - 2);
  // ball
  Ball *ball = init_ball();
  // gameloop
  int ch;
  while ((ch = getch()) != 'q') {
    refresh_ball(ball, p1, p2);
    auto_paddle(p2, ball);
    refresh();
    switch (ch) {
    case KEY_UP:
      update_paddle(p1, -1);
      break;
    case KEY_DOWN:
      update_paddle(p1, 1);
      break;
    case KEY_LEFT:
      break;
    case KEY_RIGHT:
      break;
    case 'x':
      notify("x pressed", DEBUG);
      break;
    case 'b':
      draw_ball(ball, 1);
      break;
    }
    usleep(1000);
  }

  // free up mem
  free(p1);
  free(p2);

  // de init
  endwin();
  return 0;
}
