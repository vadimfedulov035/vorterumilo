/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -t -o vocab/suffixes.gperf  */
/* Computed positions: -k'1-3' */

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

#line 3 "vocab/suffixes.gperf"

#include <string.h>
#include "../vocab/vocab.h"
#line 7 "vocab/suffixes.gperf"
struct Res { char *word; char *eng; char *def; };

#define TOTAL_KEYWORDS 42
#define MIN_WORD_LENGTH 1
#define MAX_WORD_LENGTH 22
#define MIN_HASH_VALUE 1
#define MAX_HASH_VALUE 97
/* maximum key range = 97, duplicates = 0 */

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
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 15, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 15, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 10,  0, 45,
      20, 40, 98, 55, 98,  0, 50, 98,  2, 40,
       0, 35, 40, 98, 26,  5,  5, 20, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 10, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98,  1, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 30, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 10, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
      98, 98, 98, 98, 98, 98
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

struct Res *
get_suffix (register const char *str, register size_t len)
{
  static struct Res wordlist[] =
    {
      {""},
#line 38 "vocab/suffixes.gperf"
      {"i",            "country",                                             "1x",},
#line 18 "vocab/suffixes.gperf"
      {"in",           "female gender",                                       "1n",},
      {""},
#line 17 "vocab/suffixes.gperf"
      {"il",           "instrument",                                          "1n",},
      {""}, {""},
#line 44 "vocab/suffixes.gperf"
      {"it",           "present passive participle",                          "1v",},
#line 46 "vocab/suffixes.gperf"
      {"int",          "past active participle",                              "1v",},
      {""}, {""}, {""},
#line 11 "vocab/suffixes.gperf"
      {"an",           "member",                                              "1n",},
#line 19 "vocab/suffixes.gperf"
      {"ist",          "professional",                                        "1n",},
#line 29 "vocab/suffixes.gperf"
      {"i\304\235",           "anticausative",                                       "1v",},
      {""}, {""},
#line 45 "vocab/suffixes.gperf"
      {"at",           "present continuous passive participle",               "1v",},
#line 43 "vocab/suffixes.gperf"
      {"ant",          "present active participle",                           "1v",},
      {""}, {""}, {""},
#line 16 "vocab/suffixes.gperf"
      {"id",           "kid",                                                 "1n",},
#line 25 "vocab/suffixes.gperf"
      {"ind",          "worthy of",                                           "1a",},
#line 22 "vocab/suffixes.gperf"
      {"ul",           "person",                                              "1n",},
      {""}, {""},
#line 50 "vocab/suffixes.gperf"
      {"ut",           "conditional passive participle",                      "1v",},
#line 49 "vocab/suffixes.gperf"
      {"unt",          "conditional active participle",                       "1v",},
      {""}, {""}, {""},
#line 30 "vocab/suffixes.gperf"
      {"ad",           "continuous",                                          "1x",},
#line 34 "vocab/suffixes.gperf"
      {"a\304\211",           "pejorative",                                          "1x",},
      {""}, {""}, {""},
#line 27 "vocab/suffixes.gperf"
      {"on",           "fraction",                                            "1a",},
#line 12 "vocab/suffixes.gperf"
      {"ar",           "collection",                                          "1n",},
      {""},
#line 26 "vocab/suffixes.gperf"
      {"obl",          "multiple",                                            "1a",},
      {""},
#line 48 "vocab/suffixes.gperf"
      {"ot",           "future passive participle",                           "1v",},
#line 47 "vocab/suffixes.gperf"
      {"ont",          "future active participle",                            "1v",},
      {""},
#line 23 "vocab/suffixes.gperf"
      {"ebl",          "possible",                                            "1a",},
      {""},
#line 32 "vocab/suffixes.gperf"
      {"et",           "diminutive",                                          "1x",},
#line 20 "vocab/suffixes.gperf"
      {"ism",          "ideology",                                            "1n",},
      {""}, {""}, {""},
#line 40 "vocab/suffixes.gperf"
      {"nj",           "female diminutive",                                   "1x",},
#line 10 "vocab/suffixes.gperf"
      {"a\304\265",           "manifestation",                                       "1n",},
#line 15 "vocab/suffixes.gperf"
      {"estr",         "boss",                                                "1n",},
      {""}, {""},
#line 28 "vocab/suffixes.gperf"
      {"ig",           "causative",                                           "1v",},
#line 39 "vocab/suffixes.gperf"
      {"ing",          "holder",                                              "1x",},
      {""}, {""},
#line 9 "vocab/suffixes.gperf"
      {"// BASE SUFFIXES"},
#line 33 "vocab/suffixes.gperf"
      {"um",           "<ad hoc>",                                            "1x",},
#line 36 "vocab/suffixes.gperf"
      {"end",          "mandatory",                                           "1x",},
      {""}, {""}, {""},
#line 42 "vocab/suffixes.gperf"
      {"// PARTICIPLE SUFFIXES"},
#line 37 "vocab/suffixes.gperf"
      {"er",           "particle",                                            "1x",},
      {""}, {""}, {""},
#line 21 "vocab/suffixes.gperf"
      {"uj",           "container/country",                                   "1n",},
#line 35 "vocab/suffixes.gperf"
      {"\304\211j",           "male diminuitive",                                    "1x",},
      {""}, {""}, {""},
#line 41 "vocab/suffixes.gperf"
      {"op",           "group",                                               "1x",},
      {""}, {""}, {""}, {""},
#line 24 "vocab/suffixes.gperf"
      {"em",           "prone to",                                            "1a",},
      {""}, {""}, {""}, {""},
#line 13 "vocab/suffixes.gperf"
      {"ec",           "quality",                                             "1n",},
      {""}, {""}, {""}, {""},
#line 14 "vocab/suffixes.gperf"
      {"ej",           "place",                                               "1n",},
      {""}, {""}, {""}, {""},
#line 31 "vocab/suffixes.gperf"
      {"eg",           "augmentative",                                        "1x",}
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
