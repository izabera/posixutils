/*
 *  head.c
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
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <getopt.h>

/* head */

int main (int argc, char **argv) {
  FILE *file;
  int i, numlines = 10, newlinescount, exitcode = 0, opt;

  while ((opt = getopt(argc, argv, "n:")) != -1) {
    switch (opt) {
      case 'n':
        numlines = atoi(optarg);
        break;
      default:
        fprintf(stderr, "Usage: %s [−n number] [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif
  char buffer[BUFFER_SIZE];
  size_t numbytes, tmpcount;
  bool multiple;

  if (optind == argc) {
    optind--;
    strcpy(argv[optind], "-");
  }
  else if (optind > argc - 1) {
    multiple = true;
  }
  for (i = optind; i < argc; i++) {
    if (strcmp(argv[i], "-") == 0) file = stdin;
    else file = fopen(argv[i], "r");
    if (!file) {
      fprintf(stderr, "%s: Error %d: %s\n", argv[0], errno, strerror(errno));
      exitcode = 1;
      continue;
    }
    if (multiple) {
      if (i == optind) printf("==> %s <==\n", argv[i]);
      else printf("\n==> %s <==\n", argv[i]);
    }
    for (newlinescount = 0; newlinescount < numlines;) {
      numbytes = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, file);
      for (tmpcount = 0; tmpcount < numbytes; tmpcount++) {
        if (buffer[tmpcount] == '\n') newlinescount++;
        if (newlinescount == numlines) numbytes = tmpcount + 1;
      }
      fwrite(buffer, sizeof(unsigned char), numbytes, stdout);
      if (numbytes < BUFFER_SIZE) break;
    }
    if (strcmp(argv[i], "-") != 0) fclose(file);
  }
  return exitcode;
}
