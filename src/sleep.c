/*
 *  sleep.c
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

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <getopt.h>

/* sleep */

void quit() { exit(EXIT_SUCCESS); }

int main (int argc, char *argv[]) {
  unsigned int num;
  int opt;
  while ((opt = getopt(argc, argv, "")) != -1) {
    switch (opt) {
      default:
        fprintf(stderr, "Usage: %s time\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  if (argc - optind > 1) {
    fprintf(stderr, "Usage: %s time\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  signal(SIGALRM, quit);

  /* posix doesn't require validation */
  num = atoi(argv[1]);
  sleep(num);
  return 0;
}
