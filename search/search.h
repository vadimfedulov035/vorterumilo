#ifndef SEARCH_H
#define SEARCH_H

#ifndef STDDEF_H
#define NULL ((void *)0)
#endif

#include <stdbool.h>

#define OUT_NUM 25
#define OUT_LEN 500

// CATEGORY OF CASE (definition)
#define ACC_CASE "-n (accusative case)"
#define NOM_CASE "- (nominative case)"

// CATEGORY OF NUMBER (definition)
#define PLUR_NUM "-j (plural number)"
#define SING_NUM "- (singular number)"

// WORD CLASSES
#define NOUN_WC    "-o (noun)"
#define ADJ_WC     "-a (adjective)"
#define ADV_WC     "-e (adverb)"
#define TRUNC_WC   "-' (truncated)"

// VERB
#define INF_VERB     "-i (infinitive)"
#define VOL_VERB     "-u (volitive)"
#define PAST_VERB    "-is (paste tense)"
#define PRES_VERB    "-as (present tense)"
#define FUTUR_VERB   "-os (future tense)"
#define COND_VERB    "-us (conditional)"

enum Match {
	FALSE = 0,
	TRUE = 1,
	EXCEPTION = -1
};

char *strip_jn(char *rword, char (*out)[OUT_LEN], int *i);
char *strip_oae(char *rword, char (*out)[OUT_LEN], int *i);
char *strip_verb_end(char *rword, char (*out)[OUT_LEN], int *i);

struct word { char *word; char *eng; char *def; };
typedef struct word* (*Get)(const char *, unsigned int);

struct word* get_core(const char *, unsigned int);
struct word* get_meta(const char *, unsigned int);
struct word* get_root(const char *, unsigned int);
struct word* get_suffix(const char *, unsigned int);

bool search_full(char *lword, char (*defs)[OUT_LEN], int *li, Get get);
char *buf_search_forth(char *lword, char (*defs)[OUT_LEN], int *li, Get get);
char *search_back(char *lword, char *rword, char (*defs)[OUT_LEN], int *ri, Get get);

#endif
