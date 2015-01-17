/*
 *  tee.c
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

/* tee */

int main (int argc, char **argv) {
  FILE *output[argc];
  int i, exitcode = 0, opt;
  bool append = false;

  while ((opt = getopt(argc, argv, "ai")) != -1) {
    switch (opt) {
      case 'a':
        append = true;
        break;
      case 'i':
        signal(SIGINT, SIG_IGN);
        break;
      default:
        fprintf(stderr, "Usage: %s [−ai] [file...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  for (i = optind; i < argc; i++) {
    if (append) output[i] = fopen(argv[i], "a");
    else output[i] = fopen(argv[i], "w");
    if (output[i]) {
      setvbuf(output[i], NULL, _IONBF, 0);
    }
    else {
      fprintf(stderr, "ERROR: %s\n", strerror(errno));
      exitcode = EXIT_FAILURE;
    }
  }

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif
  char buffer[BUFFER_SIZE];
  size_t numbytes;

  while (1) {
    numbytes = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, stdin);
    for (i = optind; i < argc; i++) 
      if (output[i]) fwrite(buffer, sizeof(unsigned char), numbytes, output[i]);
    fwrite(buffer, sizeof(unsigned char), numbytes, stdout);
    if (numbytes < BUFFER_SIZE) break;
  }
  for (i = optind; i < argc; i++) 
    if (output[i]) fclose(output[i]);
  return exitcode;
}

