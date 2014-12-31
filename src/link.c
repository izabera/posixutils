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

