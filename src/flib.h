#ifndef _FELIX_LIB
#define _FELIX_LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FIX: write some damn doc for the functions 

char *itoa(long num);

char *get_sstring(char *question, size_t len);

int get_int(char *question);

int isUpper(int c);

int isLower(int c);

int toggleCase(int c);

int toLower(int c);

int toUpper(int c);

void bsort(int *arr, size_t elm);

int *mk_sorted_iarr(int elm);

void swap(int *i, int *j);

void print_iarr(int *arr, size_t len);

int get_middle(int a, int b);

char *get_string(char *question);

char *fget_string(FILE *input);

int string_len(char *string);

char *str_select(char *str, int start_pos, int size);

char *center(char *text, unsigned short int size);

void str_fill(char **dest, char *src, unsigned int start_pos);

#endif
