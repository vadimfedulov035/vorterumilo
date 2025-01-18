#ifndef SEARCH_H
#define SEARCH_H

#include <stdbool.h>

#include "../out/out.h"


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
#define INF_VERB     "-i (infinitive verb)"
#define VOL_VERB     "-u (volitive verb)"
#define PAST_VERB    "-is (paste tense verb)"
#define PRES_VERB    "-as (present tense verb)"
#define FUTUR_VERB   "-os (future tense verb)"
#define COND_VERB    "-us (conditional verb)"

enum Match {
	FALSE = 0,
	TRUE = 1,
	EXCEPTION = -1
};

char *strip_jn(char *rword, char (*out)[OL], int *i);
char *strip_oae(char *rword, char (*out)[OL], int *i);
char *strip_verb_end(char *rword, char (*out)[OL], int *i);

struct Res { char *word; char *eng; char *def; };
typedef struct Res* (*G) (const char *, unsigned int);

struct Res* get_core(const char *, unsigned int);
struct Res* get_meta(const char *, unsigned int);
struct Res* get_root(const char *, unsigned int);
struct Res* get_suffix(const char *, unsigned int);

bool search_full(char *lword, char (*out)[OL], int *li, G get);
char *search_forth(char *lword, char (*out)[OL], int *li, G get);
char *search_forth_buf(char *lword, char (*out)[OL], int *li, G get);
char *search_back(char *lword, char *rword, char (*out)[OL], int *ri, G get);

#endif
