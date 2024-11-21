#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "search.h"


char *strip_jn(char *rword, char (*out)[OUT_LEN], int *i) {

	/* indicate case (-/-n) and number (-/-j) categories *
	 * for nouns (-o) and adjectives (-a), adverbs (-e)  *
	 * can only have (-n) case indicating motion         */

	char *rword_old = rword;

	bool acc = false;
	bool plur = false;
	for (bool done = false; !done; rword--) {
		switch (*rword) {
			case 'n':
				acc = true;
				sprintf(out[(*i)--], ACC_CASE);
				break;
			case 'j':
				plur = true;
				sprintf(out[(*i)--], PLUR_NUM);
				break;
			case 'o':
			case 'a':
				if (!acc) {
					sprintf(out[(*i)--], NOM_CASE);
				}
				if (!plur) {
					sprintf(out[(*i)--], SING_NUM);
				}
			default:
				done = true;
				rword[1] = '\0';
				break;
		}
	}

	return ++rword;
}


char *strip_oae(char *rword, char (*out)[OUT_LEN], int *i) {

	/* indicate word class                           *
	 * for nouns (-o), adjectives (-a), adverbs (-e) *
	 * and abbreviations (-')                        */

	char *rword_old = rword;

	char *dst = out[(*i)--];
	switch (*rword--) {
		case 'o':
			sprintf(dst, NOUN_WC); 
			break;
		case 'a':
			sprintf(dst, ADJ_WC); 
			break;
		case 'e':
			sprintf(dst, ADV_WC); 
			break;
		case '\'':
			sprintf(dst, TRUNC_WC); 
			break;
		default:
			(*i)++;
			rword++;
			break;
	}
	rword[1] = '\0';

	return rword;
}


enum Match strip_verb_end_2(char *rword, char *dst) {
	enum Match match = TRUE;
	switch (*rword) {
		case 'i':
			sprintf(dst, PAST_VERB); 
			break;
		case 'a':
			sprintf(dst, PRES_VERB); 
			break;
		case 'o':
			sprintf(dst, FUTUR_VERB); 
			break;
		case 'u':
			sprintf(dst, COND_VERB); 
			break;
		default:
			match = FALSE;
			break;
	}
	return match;
}


enum Match strip_verb_end_1(char *rword, char *dst) {
	enum Match match = TRUE;
	switch (*rword) {
		case 'i':
			sprintf(dst, INF_VERB); 
			break;
		case 'u':
			sprintf(dst, VOL_VERB); 
			break;
		case 's':
			match = EXCEPTION;
			break;
		default:
			match = FALSE;
			break;
	}
	return match;
}


char *strip_verb_end(char *rword, char (*out)[OUT_LEN], int *i) {
	char *dst = out[*i];

	enum Match match = strip_verb_end_1(rword, dst);
	if (match == EXCEPTION) {
		match = strip_verb_end_2(--rword, dst);
	}

	if (match == TRUE) {
		*rword-- = '\0';
		(*i)--;
	}

	return rword;
}


void sprintf_res(struct word *res, char (*out)[OUT_LEN], int i) {

	bool is_meta = (res->def[0] == '*');
	if (is_meta) {
		sprintf(out[i], "%s", res->eng);
	} else {
		sprintf(out[i], "%s [%s] (%s)", res->word, res->eng, res->def);
	}
}


bool search_full(char *lword, char (*out)[OUT_LEN], int *li, Get get) {
	struct word *res = get(lword, strlen(lword));

	bool match = (res != NULL && res->word != NULL && res->eng != NULL && res->def != NULL);
	if (match) {
		sprintf_res(res, out, (*li)++);
	}

	return match;
}


char *buf_search_forth(char *lword, char (*out)[OUT_LEN], int *li, Get get) {

	struct word *res;
    for (size_t n = strlen(lword); n > 0; n--) {

		char buf[n + 1];
		strncpy(buf, lword, n);
		buf[n] = '\0';

        res = get(buf, n);
        if (res != NULL && res->word != NULL && res->eng != NULL && res->def != NULL) {
			sprintf_res(res, out, (*li)++);

			lword = lword + n;
			n = strlen(lword) + 1;
        }
    }

	return lword;
}


char
*search_back(char *lword, char *rword, char (*out)[OUT_LEN], int *ri, Get get) {
	bool match = false;
	char *rword_old = rword;

	struct word *res;
	for (; rword >= lword; rword--) {
        res = get(rword, strlen(rword));
        if (res != NULL && res->word != NULL && res->eng != NULL && res->def != NULL) {
			match = true;
			sprintf_res(res, out, (*ri)--);
            *rword = '\0';
        }
    }

	if (!match) {
		return rword_old;
	}

	return rword;
}
