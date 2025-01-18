#ifndef OUT_H
#define OUT_H

#include <stdbool.h>

#define ON 25
#define OL 500

char (*out_alloc())[OL];
bool out_non_empty(char (*out)[OL]);
void out_print(char *fbuf, char (*out)[OL], int *li, int *ri);

#endif
