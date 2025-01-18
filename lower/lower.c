#include <stdbool.h>
#include <string.h>
#include <ctype.h>


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
