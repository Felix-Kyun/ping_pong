#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *itoa(long num) {
  char *tmp = (char *)malloc(30 * sizeof(char));
  sprintf(tmp, "%li", num);
  return tmp;
}

int string_len(char *string) {
  int size = 0;
  char ch = string[size];
  while (ch != '\0') {
    size++;
    ch = string[size];
  }
  return size;
}

int sstrlen(char *string) {
  int size = 0;
  while (string[size++] != '\0')
    ;
  return size - 1;
}

char *get_sstring(char *question, size_t len) {
  char *answer = (char *)malloc(len * sizeof(char));

  printf("%s ", question);
  fgets(answer, len, stdin);
  answer[strcspn(answer, "\n")] = '\0';

  return answer;
}

int get_int(char *question) {
  int answer;
  char *answer_str = get_sstring(question, 30);

  answer = atoi(answer_str);

  if (strcmp(answer_str, itoa(answer)) !=
      0) { // strcmp return 0(aka false) if both str are same, weird af
    free(answer_str);
    puts("enter number only");
    exit(69);
  }

  free(answer_str);
  return answer;
}

int isUpper(int c) {
  if (c <= 90 && c >= 65)
    return 1;
  else
    return 0;
}

int isLower(int c) {
  if (c <= 122 && c >= 97)
    return 1;
  else
    return 0;
}

int toggleCase(int c) {
  /*
   *  A-Z -> 65-90
   *  a-z -> 97-122
   *  diff : 32
   */

  if (isUpper(c))
    return c + 32;
  else if (isLower(c))
    return c - 32;
  return c;
}

int toLower(int c) {
  if (isUpper(c))
    toggleCase(c);
  return c;
}

int toUpper(int c) {
  if (isLower(c))
    toggleCase(c);
  return c;
}

void swap(int *i, int *j) {
  int tmp = *i;
  *i = *j;
  *j = tmp;
}

void bsort(int *arr, size_t elm) {
  for (int i = 0; i < elm; i++) {
    printf("bsort: iter: %d\n", i);
    for (int j = i; j < elm; j++) {
      if (arr[i] > arr[j])
        swap(&arr[i], &arr[j]);
    }
  }
}

int *mk_sorted_iarr(int elm) {
  srand(time(NULL));
  int *arr = (int *)malloc(elm * sizeof(int));
  for (int i = 0; i < elm; i++) {
    printf("mk_sorted_iarr: iter: %d\n", i);
    arr[i] = rand() % 100;
  }
  bsort(arr, elm);
  return arr;
}

void print_iarr(int *arr, size_t len) {
  for (int i = 0; i < len; i++) {
    printf("%d: %d\n", i, arr[i]);
  }
}

int get_middle(int a, int b) {
  int diff = abs(a - b);
  return ((diff % 2) == 0) ? (diff / 2) : ((diff - 1) / 2);
}

char *get_string(char *q) {
  /*
   * read stdin
   * check if new line
   * if not extend buffer and write to it
   * go to step one
   *
   */
  printf("%s: ", q);
  char ch = getc(stdin);
  char *line = NULL;
  int cursor = 0, size = 0;

  while (ch != '\n') {
    line = (char *)realloc(line, ++size * sizeof(char));
    line[cursor++] = ch;
    ch = getc(stdin);
  }
  return line;
}

char *fget_string(FILE *input) {
  /*
   * read stdin
   * check if new line
   * if not extend buffer and write to it
   * go to step one
   *
   */
  char ch = fgetc(input);
  char *line = NULL;
  int cursor = 0, size = 0;

  while (ch != EOF) {
    line = (char *)realloc(line, ++size * sizeof(char));
    line[cursor++] = ch;
    ch = getc(stdin);
  }
  return line;
}

int pow_(int a, int b) {

  int tmp = a;

  for (int i = 2; i <= b; i++) {
    tmp *= a;
  }
  return tmp;
}

int factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return factorial(n - 1) * n;
}

char *str_select(char *str, int start_pos, int size) {
  if (string_len(str) < start_pos + size) {
    perror("ERROR: (in str_select()) => size is out of index");
    exit(69);
  }

  char *text = (char *)malloc((size + 1) * sizeof(char));

  for (int i = start_pos, j = 0; i < start_pos + size; i++) {
    text[j++] = str[i];
  }

  text[size] = '\0';
  return text;
}

void str_fill(char **dest, char *src, unsigned int start_pos) {
  int src_len = string_len(src);
  if (start_pos + src_len > string_len(*dest)) {
    perror("ERROR: (in str_fill()) => fill idx goes out of bound");
    exit(69);
  }
  for (int i = start_pos, j = 0; i < start_pos + src_len; i++) {
    (*dest)[i] = src[j++];
  }
}

char *center(char *text, unsigned short int size) {
  int len = string_len(text);
  if (len >= size) {
    return str_select(text, 0, size);
  }

  int8_t isEven = ((size - len) % 2 == 0) ? 0 : 1;

  char *final_txt = (char *)malloc((size + 1) * sizeof(char));

  return final_txt;
}
