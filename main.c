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


char (*out_alloc())[OL] {
	char (*out)[OL] = malloc(ON * sizeof(*out));
	for (int i = 0; i < ON; i++) {
		strcpy(out[i], "");
	}
	return out;
}


void out_sprint(char *fbuf, char (*out)[OL], int *li, int *ri) {
	bool is_read = false;

	// print (->)
	for (int i = 0; i < *li ; i++) {
		is_read = true;
		printf("%s, ", out[i]);
		strcpy(out[i], "");
	}

	// print (<-)
	for (int i = ++(*ri); i < ON; i++) {
		is_read = true;
		printf("%s, ", out[i]);
		strcpy(out[i], "");
	}

	// extra comma (x)
	if (is_read) {
		printf("\b\b \n");
	}
}


void out_copy(char (*src)[OL], char (*dst)[OL]) {
	for (size_t i = 0; i < ON; i++) {
		strcpy(src[i], dst[i]);
	}
}


bool out_compare(char (*o1)[OL], char (*o2)[OL]) {
	for (size_t i = 0; i < ON; i++) {
		if (strcmp(o1[i], o2[i]) != 0) {
			return false;
		}
	}
	return true;
}


void morphemize(char *line, char (*out)[OL], char (*out_buf)[OL], FILE *fout) {

	const char *ds = " \t\n\r,.?!:;\"'()[]{}-";
	char *lword, *lword_old;
	char *rword, *rword_old;
	int li = 0;
	int ri = ON - 1;
	int li_buf, ri_buf;

	bool match = false;
	bool is_equal = false;

	char fbuf[ON * OL + 1];

	for (lword = strtok(line, ds); lword != NULL; lword = strtok(NULL, ds)) {
		rword = lword + strlen(lword) - 1;

		if (match) {
			//if (is_equal) {
			//	sprintf(fbuf, "(");
			//	out_sprint(fbuf, out_buf, &li_buf, &ri_buf);
			//	sprintf(fbuf, "|");
			//	out_sprint(fbuf, out,     &li,     &ri);
			//	sprintf(fbuf, ")");
			//} else {
			out_sprint(fbuf, out,     &li,     &ri);
			//}
			//fprintf(fout, "%s", fbuf);
		}

		li = 0;
		ri = ON - 1;

		// print whole word
		printf("%s: ", lword);
		// skip letters and numbers analysis
		if (strlen(lword) == 1 || isdigit(*lword)) {
			printf("%s\n", lword);
			continue;
		}

		tolower_esperanto(lword);

		// cores (a priori words)
		match = search_full(lword, out, &li, &get_core);
		if (match) {
			continue;
		}

		// -j, -n
		rword = strip_jn(rword, out, &ri);

		// meta (pronouns, numerals, correlatives)
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
		//li_buf = li;
		//ri_buf = ri;
		//out_copy(out, out_buf);

		// greedy search
		lword = search_forth(lword,        out, &li, &get_root);
		rword = search_back( lword, rword, out, &ri, &get_suffix);

		// ungreedy search
		//lword = search_forth_buf(lword,        out_buf, &li_buf, &get_root);
		//rword = search_back(     lword, rword, out_buf, &ri_buf, &get_suffix);

		// greedy output == ungreedy outupt
		//is_equal = out_compare(out, out_buf);

		match = true;
    }
}




int main() {
    FILE *fin = fopen("data/tekstaro.txt", "r");
    if (fin == NULL) {
        perror("Error opening input file");
        return 1;
    }
    FILE *fout = fopen("data/dataset.txt", "w");
    if (fout == NULL) {
        perror("Error opening output file");
        return 1;
    }

	char (*out)[OL]     = out_alloc();
	char (*out_buf)[OL] = out_alloc();

	char line[4096];
	while ((fgets(line, sizeof(line), fin)) != NULL) {
		morphemize(line, out, out_buf, fout);
	}

	fflush(stdout);

	free(out);
	free(out_buf);

    fclose(fin);
    fclose(fout);
    return 0;
}
