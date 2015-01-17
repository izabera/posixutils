/*
 *  link.c
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

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>

/* link */

int main (int argc, char *argv[]) {
  int opt, ret;
  while ((opt = getopt(argc, argv, "")) != -1) {
    switch (opt) {
      default:
        fprintf(stderr, "Usage: %s string [suffix]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }

  if (argc - optind != 2) {
    fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  ret = link(argv[1], argv[2]);
  if (ret != 0) {
    fprintf(stderr, "%s: Error %d: %s\n", argv[0], errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  return ret;
}

