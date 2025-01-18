/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -t -o vocab/cores.gperf  */
/* Computed positions: -k'1-4' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#line 3 "vocab/cores.gperf"

#include <string.h>
#include "../vocab/vocab.h"
#line 7 "vocab/cores.gperf"
struct Res { char *word; char *eng; char *def; };

#define TOTAL_KEYWORDS 87
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 18
#define MIN_HASH_VALUE 3
#define MAX_HASH_VALUE 218
/* maximum key range = 216, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register size_t len)
{
  static unsigned char asso_values[] =
    {
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219,  40, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219,  40, 219,  40,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219,   0, 219,   5, 219, 219,
      219, 219, 219,   0, 219, 219, 219,   0, 219, 219,
        0, 219, 219,  35, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219,  20,   0,  65,
       90,  80,  67,   5,  25,   5,  10,  30,  45,  35,
        5,  55,  20,  45,   0,   0,   0,   0,  75,  45,
        0, 219,  10, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219,  80,  70,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219,   0,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219,   5,  70, 219, 219, 219, 219, 219,
      219, 219, 219,   0, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219,  70,   5,   5,  70,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
      219, 219, 219, 219, 219, 219, 219, 219
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]+1];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]+2];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

struct Res *
get_core (register const char *str, register size_t len)
{
  static struct Res wordlist[] =
    {
      {""}, {""}, {""},
#line 51 "vocab/cores.gperf"
      {"tra",          "across",                                              "1p'",},
      {""}, {""}, {""},
#line 22 "vocab/cores.gperf"
      {"se",           "if",                                                  "1c",},
      {""}, {""},
#line 52 "vocab/cores.gperf"
      {"trans",        "through",                                             "1p'",},
      {""},
#line 13 "vocab/cores.gperf"
      {"ne",           "ne [no] (negative particle)",                         "*",},
      {""}, {""},
#line 66 "vocab/cores.gperf"
      {"gra\305\255",         "as a result of",                                      "1p?",},
      {""},
#line 37 "vocab/cores.gperf"
      {"je",           "<ad hoc>",                                            "1px",},
#line 14 "vocab/cores.gperf"
      {"jes",          "jes [yes] (exclamation)",                             "*",},
      {""}, {""}, {""}, {""},
#line 91 "vocab/cores.gperf"
      {"tro",          "too",                                                 "1d!",},
      {""}, {""}, {""},
#line 48 "vocab/cores.gperf"
      {"al",           "to",                                                  "1p'",},
#line 58 "vocab/cores.gperf"
      {"per",          "via",                                                 "1p?",},
      {""}, {""}, {""}, {""},
#line 59 "vocab/cores.gperf"
      {"pri",          "about",                                               "1p?",},
      {""}, {""}, {""},
#line 30 "vocab/cores.gperf"
      {"ke",           "that",                                                "1c",},
#line 86 "vocab/cores.gperf"
      {"pli",          "more",                                                "1d!",},
      {""}, {""}, {""},
#line 29 "vocab/cores.gperf"
      {"kvankam",      "although",                                            "1c",},
#line 57 "vocab/cores.gperf"
      {"pro",          "because of",                                          "1p?",},
      {""}, {""}, {""},
#line 33 "vocab/cores.gperf"
      {"kvaza\305\255",       "as if",                                               "1c",},
#line 39 "vocab/cores.gperf"
      {"sur",          "on",                                                  "1p_",},
      {""}, {""}, {""},
#line 20 "vocab/cores.gperf"
      {"nu",           "well / I mean",                                       "1c",},
#line 73 "vocab/cores.gperf"
      {"nur",          "only",                                                "1dx",},
      {""}, {""}, {""},
#line 94 "vocab/cores.gperf"
      {"ju",           "the",                                                 "1d!",},
#line 25 "vocab/cores.gperf"
      {"nek",          "neither/nor",                                         "1c",},
      {""}, {""}, {""},
#line 32 "vocab/cores.gperf"
      {"ol",           "than",                                                "1c",},
#line 62 "vocab/cores.gperf"
      {"sen",          "without",                                             "1p?",},
      {""}, {""},
#line 43 "vocab/cores.gperf"
      {"anta\305\255",        "before",                                              "1p_",},
#line 60 "vocab/cores.gperf"
      {"po",           "per",                                                 "1p?",},
#line 56 "vocab/cores.gperf"
      {"por",          "for",                                                 "1p?",},
#line 69 "vocab/cores.gperf"
      {"post",         "after",                                               "1p@",},
#line 90 "vocab/cores.gperf"
      {"tre",          "very",                                                "1d!",},
      {""},
#line 16 "vocab/cores.gperf"
      {"ho",           "oh",                                                  "1i",},
#line 76 "vocab/cores.gperf"
      {"jen",          "here",                                                "1d_",},
      {""}, {""}, {""},
#line 93 "vocab/cores.gperf"
      {"ja",           "indeed",                                              "1d!",},
#line 77 "vocab/cores.gperf"
      {"tuj",          "just",                                                "1d@",},
      {""}, {""}, {""},
#line 17 "vocab/cores.gperf"
      {"ve",           "geez",                                                "1i",},
#line 80 "vocab/cores.gperf"
      {"jam",          "already",                                             "1d@",},
#line 68 "vocab/cores.gperf"
      {"\304\235is",          "since",                                               "1p@",},
      {""}, {""},
#line 49 "vocab/cores.gperf"
      {"el",           "out",                                                 "1p'",},
#line 27 "vocab/cores.gperf"
      {"sed",          "but",                                                 "1c",},
#line 63 "vocab/cores.gperf"
      {"krom",         "besides",                                             "1p?",},
      {""}, {""},
#line 85 "vocab/cores.gperf"
      {"morga\305\255",       "tomorrow",                                            "1d@",},
#line 53 "vocab/cores.gperf"
      {"preter",       "past",                                                "1p'",},
      {""},
#line 88 "vocab/cores.gperf"
      {"preska\305\255",      "almost",                                              "1d!",},
      {""},
#line 50 "vocab/cores.gperf"
      {"de",           "of",                                                  "1p'",},
#line 95 "vocab/cores.gperf"
      {"des",          "the",                                                 "1d!",},
#line 89 "vocab/cores.gperf"
      {"apena\305\255",       "barely",                                              "1d!",},
      {""}, {""},
#line 38 "vocab/cores.gperf"
      {"en",           "in",                                                  "1p_",},
#line 55 "vocab/cores.gperf"
      {"plu",          "beyond/further",                                      "1d'",},
#line 34 "vocab/cores.gperf"
      {"plus",         "plus",                                                "1c#",},
      {""},
#line 87 "vocab/cores.gperf"
      {"plej",         "most",                                                "1d!",},
      {""},
#line 78 "vocab/cores.gperf"
      {"nun",          "now",                                                 "1d@",},
#line 26 "vocab/cores.gperf"
      {"ka\305\255",          "and/or",                                              "1c",},
#line 46 "vocab/cores.gperf"
      {"inter",        "between",                                             "1p_",},
#line 74 "vocab/cores.gperf"
      {"anka\305\255",        "also",                                                "1dx",},
#line 10 "vocab/cores.gperf"
      {"la",           "la [the] (definite article)",                         "*",},
#line 40 "vocab/cores.gperf"
      {"sub",          "under",                                               "1p_",},
      {""},
#line 54 "vocab/cores.gperf"
      {"for",          "away",                                                "1d'",},
      {""}, {""},
#line 75 "vocab/cores.gperf"
      {"almena\305\255",      "at least",                                            "1dx",},
      {""}, {""},
#line 42 "vocab/cores.gperf"
      {"ekster",       "outside",                                             "1p_",},
      {""},
#line 12 "vocab/cores.gperf"
      {"ajn",          "ajn [any] (indefinite determiner)",                   "*",},
#line 64 "vocab/cores.gperf"
      {"la\305\255",          "according to",                                        "1p?",},
#line 35 "vocab/cores.gperf"
      {"minus",        "minus",                                               "1c#",},
      {""},
#line 9 "vocab/cores.gperf"
      {"// META"},
#line 23 "vocab/cores.gperf"
      {"kaj",          "and",                                                 "1c",},
#line 83 "vocab/cores.gperf"
      {"hiera\305\255",       "yesterday",                                           "1d@",},
#line 71 "vocab/cores.gperf"
      {"// ADVERBS"},
      {""}, {""},
#line 61 "vocab/cores.gperf"
      {"kun",          "with",                                                "1p?",},
      {""},
#line 36 "vocab/cores.gperf"
      {"// PREPOSITIONS"},
#line 15 "vocab/cores.gperf"
      {"// INTERJECTIONS"},
#line 19 "vocab/cores.gperf"
      {"do",           "so",                                                  "1c",},
#line 65 "vocab/cores.gperf"
      {"kontra\305\255",      "against the",                                         "1p?",},
      {""},
#line 18 "vocab/cores.gperf"
      {"// CONJUNCTIONS"},
      {""}, {""},
#line 67 "vocab/cores.gperf"
      {"dum",          "while/for",                                           "1p@",},
#line 31 "vocab/cores.gperf"
      {"\304\211ar",          "because",                                             "1c",},
      {""}, {""}, {""},
#line 81 "vocab/cores.gperf"
      {"ankora\305\255",      "still/yet",                                           "1d@",},
#line 79 "vocab/cores.gperf"
      {"\304\265us",          "at once",                                             "1d@",},
      {""}, {""}, {""},
#line 11 "vocab/cores.gperf"
      {"\304\211i",           "ĉi [one] (relative selective determiner)",            "*",},
      {""},
#line 28 "vocab/cores.gperf"
      {"tamen",        "however",                                             "1c",},
      {""},
#line 70 "vocab/cores.gperf"
      {"da",           "of [quantity]",                                       "1p#",},
#line 47 "vocab/cores.gperf"
      {"\304\211irka\305\255",       "around",                                              "1p_",},
      {""}, {""}, {""},
#line 84 "vocab/cores.gperf"
      {"hodia\305\255",       "today",                                               "1d@",},
#line 24 "vocab/cores.gperf"
      {"a\305\255",           "or",                                                  "1c",},
      {""}, {""}, {""}, {""},
#line 72 "vocab/cores.gperf"
      {"e\304\211",           "even",                                                "1dx",},
      {""}, {""}, {""}, {""},
#line 92 "vocab/cores.gperf"
      {"// SPECIFIC ADVERB"},
      {""},
#line 41 "vocab/cores.gperf"
      {"super",        "over",                                                "1p_",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 45 "vocab/cores.gperf"
      {"apud",         "next to",                                             "1p_",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 82 "vocab/cores.gperf"
      {"balda\305\255",       "soon",                                                "1d@",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""},
#line 44 "vocab/cores.gperf"
      {"\304\211e",           "at",                                                  "1p_",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""},
#line 21 "vocab/cores.gperf"
      {"\304\211u",           "whether",                                             "1c",}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].word;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
