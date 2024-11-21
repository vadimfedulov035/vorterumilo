#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "search/search.h"


bool tolower_diacritic(char *str, int *i) {
	bool is_diacritic = false;

	/* diacritic letters are represesented
	 * by two contiguous bytes, we increment:
	 * the second byte to make letter lowercase,
	 * the index to get to the next letter */

	unsigned char *fir = (unsigned char *) str;
	unsigned char *sec = fir + 1;
	switch (*fir) {
		case 196:
			switch (*sec) {
				case 136:  // Ĉ
				case 156:  // Ĝ
				case 180:  // Ĵ
					is_diacritic = true;
					(*sec)++;  // captialize
					(*i)++;    // offset
					break;
				default:
					break;
			}
			break;
		case 197:
			switch (*sec) {
				case 156:  // Ŝ
				case 164:  // Ĥ
				case 172:  // Ŭ
					is_diacritic = true;
					(*sec)++;  // captialize
					(*i)++;    // offset
					break;
				default:
					break;
			}
		default:
			break;
	}

	return is_diacritic;
}


void tolower_esperanto(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {

		if (isdigit(str[i])) {
			continue;
		}

		bool is_diacritic = tolower_diacritic(str, &i);
		if (!is_diacritic) {
			str[i] = tolower(str[i]);
		}

    }
}


void print_all(char (*out)[OUT_LEN], int *li, int *ri) {
	bool is_read = false;

	// print (->)
	for (int i = 0; i < *li ; i++) {
		is_read = true;
		printf("%s, ", out[i]);
		strcpy(out[i], "");
	}

	// print (<-)
	for (int i = ++(*ri); i < OUT_NUM; i++) {
		is_read = true;
		printf("%s, ", out[i]);
		strcpy(out[i], "");
	}


	// make up extra comma
	if (is_read) {
		printf("\n");
	}
}


void morphemize(char *line, char (*out)[OUT_LEN]) {

	const char *ds = " \t\n\r,.?!:;\"'()[]{}-";
	char *lword, *lword_old;
	char *rword, *rword_old;
	int li = 0;
	int ri = OUT_NUM - 1;

	bool match;
	for (lword = strtok(line, ds); lword != NULL; lword = strtok(NULL, ds)) {
		rword = lword + strlen(lword) - 1;

		if (match) {
			print_all(out, &li, &ri);
		}

		li = 0;
		ri = OUT_NUM - 1;

		// print whole word
		printf("%s: ", lword);
		// skip letters and numbers
		if (strlen(lword) == 1 || isdigit(*lword)) {
			printf("%s\n", lword);
			continue;
		}

		tolower_esperanto(lword);

		// cores (words without endings or with pseudo-endings)
		match = search_full(lword, out, &li, &get_core);
		if (match) {
			continue;
		}

		// -j, -n
		rword = strip_jn(rword, out, &ri);

		// pronouns, numerals, correlatives,
		match = search_full(lword, out, &li, &get_meta);
		if (match) {
			continue;
		}

		// -o, -a, -e, -'
		rword_old = rword;
		rword = strip_oae(rword, out, &ri);
		// -i, -u, -is, -as, -os, -us
		if (rword == rword_old) {
			rword = strip_verb_end(rword, out, &ri);
		}

		// roots, suffixes
		rword_old = rword;
		lword = buf_search_forth(lword, out, &li, &get_root);
		rword = search_back(lword, rword, out, &ri, &get_suffix);

		match = true;
    }

	print_all(out, &li, &ri);
}


int main() {
    FILE *file_in = fopen("data/tekstaro.txt", "r");
    if (file_in == NULL) {
        perror("Error opening input file");
        return 1;
    }
    FILE *file_out = freopen("out.txt", "w", stdout);
    if (file_out == NULL) {
        perror("Error opening output file");
        return 1;
    }

	char (*out)[OUT_LEN] = malloc(OUT_NUM * sizeof(*out));
	for (int i = 0; i < OUT_NUM; i++) {
		strcpy(out[i], "");
	}

	char line[4096];
	while ((fgets(line, sizeof(line), file_in)) != NULL) {
		morphemize(line, out);
	}
	free(out);

	fflush(stdout);

    fclose(file_in);
    fclose(file_out);
    return 0;
}
