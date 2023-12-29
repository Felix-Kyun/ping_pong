#include "notify.h"
#include "setting.h"
#include <ncurses.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

unsigned long int message_counter = 0;

void notify(char *message, int status) {
  if (!status)
    return;
  pthread_t thread;
  if (pthread_create(&thread, NULL, show_message, (void *)message)) {
    perror("pthread create error");
    exit(EXIT_FAILURE);
  }
}

void *show_message(void *arg) {
  unsigned long int id = ++message_counter;
  char *message = (char *)arg;
  short int start = (COLS - strlen(message)) / 2;
  mvaddstr(1, start, message);
  sleep(NOTIFICATION_DELAY);
  if (id == message_counter)
    for (int i = start; i < start + strlen(message); i++)
      mvaddch(1, i, ' ');
  return NULL;
}
