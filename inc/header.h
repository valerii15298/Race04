#ifndef HEADER_H
#define HEADER_H
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int mx_tostring(char *nameoffile, char **string);
int mx_strlen(const char *s);
_Bool checkerr(int errnum);
int mx_hight(char *str);
int tonumbers(int **mas, int width, char *s);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char *str);
void cmp(int **arr, int a, int b, int a2, int b2, int w, int h);
int go(int **arr, int x, int y, int h, int w);
int pvalid(int **arr, int h, int w, int points[]);
int tofile(char **arrchar, int y, int x);
void direction(int **arr, char **arrchar, int hight, int width, int x, int y, int max);
void mx_printint(int n);

#endif

