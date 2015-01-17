/*
 *  basename.c
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
#include <unistd.h>
#include <getopt.h>
#include <libgen.h>
/* basename */

int main (int argc, char *argv[]) {
  /* exit if we get any option 
   * required because 'basename -- path' must produce a filename */
  int opt;
  while ((opt = getopt(argc, argv, "")) != -1) {
    switch (opt) {
      default:
        fprintf(stderr, "Usage: %s string [suffix]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  
  if (optind == argc || argc - optind > 2) {
    fprintf(stderr, "Usage: %s string [suffix]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *base = basename(argv[optind]), *suffix;
  suffix = (char *)malloc(strlen(base));
  memcpy(suffix, base, strlen(base));
  if (argv[optind+1] && strlen(argv[optind+1]) < strlen(base)) {
    suffix += strlen(base) - strlen(argv[optind+1]);
    if (strcmp(suffix, argv[optind+1]) == 0) base[strlen(suffix)+1] = 0;
  }

  printf("%s\n", base);
  return 0;
}
