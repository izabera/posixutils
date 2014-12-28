#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* echo */

bool cut = false; /* found a \c */

void echo (const char *str) {
  unsigned int i, octal_i;
  unsigned char octal;
  for (i = 0; !cut && i < strlen(str); i++) {
    if (str[i] == '\\') {
      switch (str[i+1]) {
        case 'c': cut = true; break;
        case 'a': i++; putchar('\a'); break;
        case 'b': i++; putchar('\b'); break;
        case 'f': i++; putchar('\f'); break;
        case 'n': i++; putchar('\n'); break;
        case 'r': i++; putchar('\r'); break;
        case 't': i++; putchar('\t'); break;
        case 'v': i++; putchar('\v'); break;
        case '0': i++;
                  octal = 0;
                  octal_i = 0;
                  while (str[i+1+octal_i] &&
                         str[i+1+octal_i] >= '0' &&
                         str[i+1+octal_i] <= '7' &&
                         octal_i < 3) {
                    octal *= 8;
                    octal += (str[i+1+octal_i] - '0');
                    octal_i++;
                  }
                  putchar(octal);
                  i += octal_i;
                  break;
        default: putchar(str[i]);
      }
    }
    else putchar(str[i]);
  }
}

int main (int argc, char ** argv) {
  while (*(++argv)) {
    echo(*argv);
    if (cut) break;
    if (--argc > 1) printf(" ");
  }
  if (!cut) printf("\n");
  return 0;
}

