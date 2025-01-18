/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -t -o vocab/meta.gperf  */
/* Computed positions: -k'1-6' */

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

#line 3 "vocab/meta.gperf"

#include <string.h>
#include "../vocab/vocab.h"
#line 7 "vocab/meta.gperf"
struct Res { char *word; char *eng; char *def; };

#define TOTAL_KEYWORDS 113
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 15
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 290
/* maximum key range = 289, duplicates = 0 */

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
  static unsigned short asso_values[] =
    {
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291,   0, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291,   0, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291,   0, 291, 291,
      291, 291, 291, 291, 291,   2, 291,   5,   0,   0,
        0, 291,   0, 291, 291,   0, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291,   0,  20, 125,
      105,  10,   5, 291, 291,   0,  90,  75,  25,   5,
       20,  15, 105,  37,  50,  30,  50, 105, 100, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291,  35, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291,  25, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291,   5, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291,  30,  12,   0, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291, 291, 291, 291,
      291, 291, 291, 291, 291, 291, 291
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]+1];
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
get_meta (register const char *str, register size_t len)
{
  static struct Res wordlist[] =
    {
      {""}, {""},
#line 83 "vocab/meta.gperf"
      {"ia",          INDEF_PRO DES_DET,                                   "*",},
      {""}, {""}, {""}, {""},
#line 10 "vocab/meta.gperf"
      {"mi",          "mi [I] ("        PER PRO FIR SING    ")",           "*",},
#line 101 "vocab/meta.gperf"
      {"ial",         INDEF_PRO REASON_ADV,                                "*",},
      {""},
#line 86 "vocab/meta.gperf"
      {"Kie",         INTER_PRO PLACE_ADV,                                 "*",},
#line 9 "vocab/meta.gperf"
      {"// PRONOUNS"},
#line 89 "vocab/meta.gperf"
      {"ie",          INDEF_PRO PLACE_ADV,                                 "*",},
#line 53 "vocab/meta.gperf"
      {"mil",         "mil [thousand/1000] ("  CARDNUM ")",                "*",},
#line 66 "vocab/meta.gperf"
      {"mila",        "mil- [thousand/1000] (" CARDNUM "), " ORD_NUM,      "*",},
#line 67 "vocab/meta.gperf"
      {"// CORRELATIVES"},
#line 40 "vocab/meta.gperf"
      {"// NUMERALS"},
#line 71 "vocab/meta.gperf"
      {"io",          INDEF_PRO COR_PRO,                                   "*",},
#line 107 "vocab/meta.gperf"
      {"iel",         INDEF_PRO MANNER_ADV,                                "*",},
      {""}, {""}, {""},
#line 11 "vocab/meta.gperf"
      {"ni",          "ni [we] ("       PER PRO FIR PLUR    ")",           "*",},
#line 95 "vocab/meta.gperf"
      {"iam",         INDEF_PRO TIME_ADV,                                  "*",},
      {""},
#line 80 "vocab/meta.gperf"
      {"Kia",         INTER_PRO DES_DET,                                   "*",},
      {""},
#line 13 "vocab/meta.gperf"
      {"li",          "li [he] ("       PER PRO THI SING M  ")",           "*",},
#line 20 "vocab/meta.gperf"
      {"mia",         "mi- [I] ("       PER PRO FIR SING    "), " POS_DET, "*",},
#line 50 "vocab/meta.gperf"
      {"na\305\255",         "naŭ [nine/9] ("         CARDNUM ")",                "*",},
#line 63 "vocab/meta.gperf"
      {"na\305\255a",        "naŭ- [nine/9] ("        CARDNUM "), " ORD_NUM,      "*",},
#line 92 "vocab/meta.gperf"
      {"Kiam",        INTER_PRO TIME_ADV,                                  "*",},
#line 18 "vocab/meta.gperf"
      {"si",          "si [self] ("     REF PRO THI SING EP ")",           "*",},
      {""}, {""}, {""},
#line 104 "vocab/meta.gperf"
      {"Kiel",        INTER_PRO MANNER_ADV,                                "*",},
      {""},
#line 113 "vocab/meta.gperf"
      {"iom",         INDEF_PRO AMOUNT_ADV,                                "*",},
      {""}, {""},
#line 116 "vocab/meta.gperf"
      {"Kies",        INTER_PRO POS_PRO,                                   "*",},
      {""},
#line 21 "vocab/meta.gperf"
      {"nia",         "ni- [we] ("      PER PRO FIR PLUR    "), " POS_DET, "*",},
#line 30 "vocab/meta.gperf"
      {"mies",        "mi- [I] ("       PER PRO FIR SING    "), " POS_PRO, "*",},
      {""},
#line 16 "vocab/meta.gperf"
      {"\305\235li",         "ŝli [he/she] ("  PER PRO THI SING EP ")",           "*",},
#line 26 "vocab/meta.gperf"
      {"\305\235lia",        "ŝli- [he/she] (" PER PRO THI SING EP "), " POS_DET, "*",},
#line 23 "vocab/meta.gperf"
      {"lia",         "li- [he] ("      PER PRO THI SING M  "), " POS_DET, "*",},
      {""},
#line 85 "vocab/meta.gperf"
      {"nenia",       NEGAT_PRO DES_DET,                                   "*",},
#line 98 "vocab/meta.gperf"
      {"Kial",        INTER_PRO REASON_ADV,                                "*",},
      {""},
#line 28 "vocab/meta.gperf"
      {"sia",         "si [self] ("     REF PRO THI SING EP ")",           "*",},
      {""}, {""},
#line 97 "vocab/meta.gperf"
      {"neniam",      NEGAT_PRO TIME_ADV,                                  "*",},
      {""},
#line 88 "vocab/meta.gperf"
      {"tie",         DEMON_PRO PLACE_ADV,                                 "*",},
#line 31 "vocab/meta.gperf"
      {"nies",        "ni- [we] ("      PER PRO FIR PLUR    "), " POS_PRO, "*",},
#line 91 "vocab/meta.gperf"
      {"nenie",       NEGAT_PRO PLACE_ADV,                                 "*",},
      {""}, {""},
#line 119 "vocab/meta.gperf"
      {"ies",         INDEF_PRO POS_PRO,                                   "*",},
#line 33 "vocab/meta.gperf"
      {"lies",        "li- [he] ("      PER PRO THI SING M  "), " POS_PRO, "*",},
#line 73 "vocab/meta.gperf"
      {"nenio",       NEGAT_PRO COR_PRO,                                   "*",},
      {""}, {""}, {""},
#line 38 "vocab/meta.gperf"
      {"sies",        "si [self] ("     REF PRO THI SING EP ")",           "*",},
      {""},
#line 115 "vocab/meta.gperf"
      {"neniom",      NEGAT_PRO AMOUNT_ADV,                                "*",},
      {""},
#line 82 "vocab/meta.gperf"
      {"tia",         DEMON_PRO DES_DET,                                   "*",},
      {""}, {""},
#line 103 "vocab/meta.gperf"
      {"nenial",      NEGAT_PRO REASON_ADV,                                "*",},
      {""}, {""},
#line 94 "vocab/meta.gperf"
      {"tiam",        DEMON_PRO TIME_ADV,                                  "*",},
#line 48 "vocab/meta.gperf"
      {"sep",         "sep [seven/7] ("        CARDNUM ")",                "*",},
#line 61 "vocab/meta.gperf"
      {"sepa",        "sep- [seven/7] ("       CARDNUM "), " ORD_NUM,      "*",},
      {""},
#line 87 "vocab/meta.gperf"
      {"kie",         RELAT_PRO PLACE_ADV,                                 "*",},
#line 106 "vocab/meta.gperf"
      {"tiel",        DEMON_PRO MANNER_ADV,                                "*",},
      {""},
#line 109 "vocab/meta.gperf"
      {"neniel",      NEGAT_PRO MANNER_ADV,                                "*",},
      {""},
#line 36 "vocab/meta.gperf"
      {"\305\235lies",       "ŝli- [he/she] (" PER PRO THI SING EP "), " POS_PRO, "*",},
#line 118 "vocab/meta.gperf"
      {"ties",        DEMON_PRO POS_PRO,                                   "*",},
      {""},
#line 121 "vocab/meta.gperf"
      {"nenies",      NEGAT_PRO POS_PRO,                                   "*",},
#line 49 "vocab/meta.gperf"
      {"ok",          "ok [eight/8] ("         CARDNUM ")",                "*",},
#line 47 "vocab/meta.gperf"
      {"ses",         "ses [six/6] ("          CARDNUM ")",                "*",},
#line 60 "vocab/meta.gperf"
      {"sesa",        "ses- [six/6] ("         CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""},
#line 81 "vocab/meta.gperf"
      {"kia",         RELAT_PRO DES_DET,                                   "*",},
#line 100 "vocab/meta.gperf"
      {"tial",        DEMON_PRO REASON_ADV,                                "*",},
      {""}, {""},
#line 12 "vocab/meta.gperf"
      {"vi",          "vi [you] ("      PER PRO SEC BOTH    ")",           "*",},
      {""},
#line 93 "vocab/meta.gperf"
      {"kiam",        RELAT_PRO TIME_ADV,                                  "*",},
#line 74 "vocab/meta.gperf"
      {"Kiu",         INTER_PRO SEL_DET,                                   "*",},
      {""},
#line 77 "vocab/meta.gperf"
      {"iu",          INDEF_PRO SEL_DET,                                   "*",},
      {""},
#line 105 "vocab/meta.gperf"
      {"kiel",        RELAT_PRO MANNER_ADV,                                "*",},
#line 68 "vocab/meta.gperf"
      {"Kio",         INTER_PRO COR_PRO,                                   "*",},
      {""}, {""},
#line 62 "vocab/meta.gperf"
      {"oka",         "ok- [eight/8] ("        CARDNUM "), " ORD_NUM,      "*",},
#line 117 "vocab/meta.gperf"
      {"kies",        RELAT_PRO POS_PRO,                                   "*",},
      {""},
#line 110 "vocab/meta.gperf"
      {"Kiom",        INTER_PRO AMOUNT_ADV,                                "*",},
      {""},
#line 17 "vocab/meta.gperf"
      {"ili",         "ili [they] ("    PER PRO THI PLUR    ")",           "*",},
#line 27 "vocab/meta.gperf"
      {"ilia",        "ili- [they] ("   PER PRO THI PLUR    "), " POS_DET, "*",},
      {""}, {""}, {""},
#line 22 "vocab/meta.gperf"
      {"via",         "vi- [you] ("     PER PRO SEC BOTH    "), " POS_DET, "*",},
#line 99 "vocab/meta.gperf"
      {"kial",        RELAT_PRO REASON_ADV,                                "*",},
      {""}, {""}, {""},
#line 19 "vocab/meta.gperf"
      {"oni",         "oni [one] ("     IND PRO THI PLUR    ")",           "*",},
#line 29 "vocab/meta.gperf"
      {"onia",        "oni- [one] ("    IND PRO THI PLUR    "), " POS_DET, "*",},
#line 14 "vocab/meta.gperf"
      {"\305\235i",          "ŝi [she] ("      PER PRO THI SING F  ")",           "*",},
#line 24 "vocab/meta.gperf"
      {"\305\235ia",         "ŝi- [she] ("     PER PRO THI SING F  "), " POS_DET, "*",},
      {""},
#line 41 "vocab/meta.gperf"
      {"nul",         "nul [zero/0] ("         CARDNUM ")",                "*",},
#line 54 "vocab/meta.gperf"
      {"nula",        "nul- [zero/0] ("        CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""}, {""},
#line 32 "vocab/meta.gperf"
      {"vies",        "vi- [you] ("     PER PRO SEC BOTH    "), " POS_PRO, "*",},
      {""}, {""}, {""},
#line 51 "vocab/meta.gperf"
      {"dek",         "dek [ten/10] ("         CARDNUM ")",                "*",},
#line 64 "vocab/meta.gperf"
      {"deka",        "dek- [ten/10] ("        CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""},
#line 15 "vocab/meta.gperf"
      {"\304\235i",          "ĝi [it] ("       PER PRO THI SING N  ")",           "*",},
#line 25 "vocab/meta.gperf"
      {"\304\235ia",         "ĝi- [it] ("      PER PRO THI SING N  "), " POS_DET, "*",},
      {""}, {""}, {""},
#line 76 "vocab/meta.gperf"
      {"tiu",         DEMON_PRO SEL_DET,                                   "*",},
      {""},
#line 79 "vocab/meta.gperf"
      {"neniu",       NEGAT_PRO SEL_DET,                                   "*",},
      {""}, {""},
#line 70 "vocab/meta.gperf"
      {"tio",         DEMON_PRO COR_PRO,                                   "*",},
#line 84 "vocab/meta.gperf"
      {"\304\211ia",         UNIVE_PRO DES_DET,                                   "*",},
#line 37 "vocab/meta.gperf"
      {"ilies",       "ili- [they] ("   PER PRO THI PLUR    "), " POS_PRO, "*",},
      {""}, {""}, {""},
#line 112 "vocab/meta.gperf"
      {"tiom",        DEMON_PRO AMOUNT_ADV,                                "*",},
#line 96 "vocab/meta.gperf"
      {"\304\211iam",        UNIVE_PRO TIME_ADV,                                  "*",},
      {""}, {""}, {""},
#line 90 "vocab/meta.gperf"
      {"\304\211ie",         UNIVE_PRO PLACE_ADV,                                 "*",},
#line 39 "vocab/meta.gperf"
      {"onies",       "oni- [they] ("   IND PRO THI PLUR    "), " POS_PRO, "*",},
      {""},
#line 34 "vocab/meta.gperf"
      {"\305\235ies",        "ŝi- [she] ("     PER PRO THI SING F  "), " POS_PRO, "*",},
      {""},
#line 72 "vocab/meta.gperf"
      {"\304\211io",         UNIVE_PRO COR_PRO,                                   "*",},
      {""}, {""}, {""},
#line 75 "vocab/meta.gperf"
      {"kiu",         RELAT_PRO SEL_DET,                                   "*",},
      {""},
#line 114 "vocab/meta.gperf"
      {"\304\211iom",        UNIVE_PRO AMOUNT_ADV,                                "*",},
      {""}, {""},
#line 69 "vocab/meta.gperf"
      {"kio",         RELAT_PRO COR_PRO,                                   "*",},
      {""},
#line 102 "vocab/meta.gperf"
      {"\304\211ial",        UNIVE_PRO REASON_ADV,                                "*",},
      {""}, {""}, {""},
#line 111 "vocab/meta.gperf"
      {"kiom",        RELAT_PRO AMOUNT_ADV,                                "*",},
#line 35 "vocab/meta.gperf"
      {"\304\235ies",        "ĝi- [it] ("      PER PRO THI SING N  "), " POS_PRO, "*",},
      {""}, {""},
#line 44 "vocab/meta.gperf"
      {"tri",         "tri [three/3] ("        CARDNUM ")",                "*",},
#line 57 "vocab/meta.gperf"
      {"tria",        "tri- [three/3] ("       CARDNUM "), " ORD_NUM,      "*",},
#line 108 "vocab/meta.gperf"
      {"\304\211iel",        UNIVE_PRO MANNER_ADV,                                "*",},
      {""}, {""}, {""}, {""},
#line 120 "vocab/meta.gperf"
      {"\304\211ies",        UNIVE_PRO POS_PRO,                                   "*",},
      {""}, {""}, {""},
#line 52 "vocab/meta.gperf"
      {"cent",        "cent [hundred/100] ("   CARDNUM ")",                "*",},
#line 65 "vocab/meta.gperf"
      {"centa",       "cent- [hundred/100] ("  CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 43 "vocab/meta.gperf"
      {"du",          "du [two/2] ("           CARDNUM ")",                "*",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 42 "vocab/meta.gperf"
      {"unu",         "unu [one/1] ("          CARDNUM ")",                "*",},
#line 55 "vocab/meta.gperf"
      {"unua",        "unu- [one/1] ("         CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""},
#line 56 "vocab/meta.gperf"
      {"dua",         "du- [two/2] ("          CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 45 "vocab/meta.gperf"
      {"kvar",        "kvar [four/4] ("        CARDNUM ")",                "*",},
#line 58 "vocab/meta.gperf"
      {"kvara",       "kvar- [four/4] ("       CARDNUM "), " ORD_NUM,      "*",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""},
#line 78 "vocab/meta.gperf"
      {"\304\211iu",         UNIVE_PRO SEL_DET,                                   "*",},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 46 "vocab/meta.gperf"
      {"kvin",        "kvin [five/5] ("        CARDNUM ")",                "*",},
#line 59 "vocab/meta.gperf"
      {"kvina",       "kvin- [five/5] ("       CARDNUM "), " ORD_NUM,      "*",}
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
