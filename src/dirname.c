#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <libgen.h>
/* dirname */

int main (int argc, char *argv[]) {
  /* exit if we get any option 
   * required because 'basename -- path' must produce a filename */
  int opt;
  while ((opt = getopt(argc, argv, "")) != -1) {
    switch (opt) {
      default:
        fprintf(stderr, "Usage: %s string\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  }
  
  if (optind != argc - 1) {
    fprintf(stderr, "Usage: %s string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  printf("%s\n", dirname(argv[optind]));
  return 0;
}
