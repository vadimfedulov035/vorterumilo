#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "search/search.h"
#include "lower/lower.h"
#include "out/out.h"


void morphemize(char *line, char (*out)[OL], FILE *fout) {

	const char *ds = " \t\n\r,.?!:;\"'()[]{}-";
	char *lword, *lword_old;
	char *rword, *rword_old;
	int li = 0;
	int ri = ON - 1;

	bool match = false;
	bool is_equal = false;

	char fbuf[ON * OL + 1];

	for (lword = strtok(line, ds); lword != NULL; lword = strtok(NULL, ds)) {
		rword = lword + strlen(lword) - 1;

		if (match) {
			//if (is_equal) {
			out_print(fbuf, out, &li, &ri);
			//} else {
			// API call to LLM
			//}
			fprintf(fout, "%s", fbuf);
		}
		li = 0;
		ri = ON - 1;

		// print whole word
		printf("%s: ", lword);
		fprintf(fout, "%s: ", lword);
		// skip letters and numbers analysis
		if (strlen(lword) == 1 || isdigit(*lword)) {
			printf("%s\n", lword);
			fprintf(fout, "%s", lword);
			continue;
		}

		tolower_esperanto(lword);

		// cores (small words)
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

		// greedy search
		// lword = search_forth( lword,        out, &li, &get_root);
		// rword = search_back(  lword, rword, out, &ri, &get_suffix);

		// ungreedy search
		lword = search_forth_buf(lword,        out, &li, &get_root);
		rword = search_back(     lword, rword, out, &ri, &get_suffix);

		if (out_non_empty(out)) {
			match = true;
		} else {
			printf("%s\n", lword);
			fprintf(fout, "%s\n", lword);
		}
    }

	out_print(fbuf, out,     &li,     &ri);
	fprintf(fout, "%s", fbuf);
}




int main() {
    FILE *fin = fopen("data/input.txt", "r");
    if (fin == NULL) {
        perror("Error opening input file");
        return 1;
    }
    FILE *fout = fopen("data/output.txt", "w");
    if (fout == NULL) {
        perror("Error opening output file");
        return 1;
    }

	char (*out)[OL] = out_alloc();

	char line[4096];
	while ((fgets(line, sizeof(line), fin)) != NULL) {
		morphemize(line, out, fout);
	}
	fflush(stdout);

	free(out);

    fclose(fin);
    fclose(fout);

    return 0;
}
