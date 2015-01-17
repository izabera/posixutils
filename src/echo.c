/*
 *  echo.c
 *  This file is part of posixutils.
 *
 *  Copyright (C) 2015 izabera
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

