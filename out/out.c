#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "out.h"


char (*out_alloc())[OL] {
	char (*out)[OL] = malloc(ON * sizeof(*out));
	for (int i = 0; i < ON; i++) {
		strcpy(out[i], "");
	}
	return out;
}


bool out_non_empty(char (*out)[OL]) {
	for (int i = 0; i < ON; i++) {
		if (out[i] != NULL && strlen(out[i]) > 0) {
			return true;
		}
	}
	return false;
}


void out_print(char *fbuf, char (*out)[OL], int *li, int *ri) {
	bool is_read = false;

	int offset = 0;

	// print (->)
	for (int i = 0; i < *li ; i++) {
		is_read = true;
		printf("%s, ", out[i]);
		offset += sprintf(fbuf + offset, "%s, ", out[i]);
		strcpy(out[i], "");
	}

	// print (<-)
	for (int i = ++(*ri); i < ON; i++) {
		is_read = true;
		printf("%s, ", out[i]);
		offset += sprintf(fbuf + offset, "%s, ", out[i]);
		strcpy(out[i], "");
	}

	// extra comma (x)
	if (is_read) {
		printf("\b\b \n");
		fbuf[offset - 2] = '\n';
		fbuf[offset - 1] = '\0';
	}
}
