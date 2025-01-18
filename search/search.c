#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "search.h"


char *strip_jn(char *rword, char (*out)[OL], int *i) {

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


char *strip_oae(char *rword, char (*out)[OL], int *i) {

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


char *strip_verb_end(char *rword, char (*out)[OL], int *i) {
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


void sprintf_res(struct Res *res, char (*out)[OL], int i) {

	bool is_meta = (res->def[0] == '*');
	if (is_meta) {
		sprintf(out[i], "%s", res->eng);
	} else {
		sprintf(out[i], "%s [%s] (%s)", res->word, res->eng, res->def);
	}
}


bool got_res(struct Res *res) {
	if (res == NULL) {
		return false;
	}

	bool no_word = (res->word == NULL);
	bool no_eng  = (res->eng  == NULL);
	bool no_def  = (res->def  == NULL);
	if (no_word || no_eng || no_def) {
		return false;
	}

	return true;
}


bool search_full(char *lword, char (*out)[OL], int *li, G get) {
	struct Res *res = get(lword, strlen(lword));

	bool match;
	if (match = got_res(res)) {
		sprintf_res(res, out, (*li)++);
	}

	return match;
}


char *search_forth(char *lword, char (*out)[OL], int *li, G get) {
	size_t wordlen = strlen(lword);

	struct Res *res;
    for (size_t n = 1; n <= wordlen; n++) {

		char buf[n + 1];
		strncpy(buf, lword, n);
		buf[n] = '\0';

		res = get(buf, n);
		if (got_res(res)) {
			sprintf_res(res, out, (*li)++);
			lword = lword + n;
			n = strlen(lword) - 1;
		}
	}

	return lword;
}


char *search_forth_buf(char *lword, char (*out)[OL], int *li, G get) {
	char *lword_old = lword;

	struct Res *res;
	bool match = false;
    for (size_t n = strlen(lword); n > 0; n--) {

		char buf[n + 1];
		strncpy(buf, lword, n);
		buf[n] = '\0';

		res = get(buf, n);
		if (got_res(res)) {
			match = true;
			sprintf_res(res, out, (*li)++);
			lword = lword + n;
			n = strlen(lword) + 1;
        }
    }

	if (!match) {
		lword = lword_old;
	}

	return lword;
}


char *search_back(char *lword, char *rword, char (*out)[OL], int *ri, G get) {
	char *rword_old = rword;

	struct Res *res;
	bool match = false;
	for (; rword >= lword; rword--) {
        res = get(rword, strlen(rword));

        if (got_res(res)) {
			match = true;
			sprintf_res(res, out, (*ri)--);
            *rword = '\0';
        }
    }

	if (!match) {
		rword = rword_old;
	}

	return rword;
}
