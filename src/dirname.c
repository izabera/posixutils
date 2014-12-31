#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
/* basename */

/* // -> / */

int main (int argc, char *argv[]) {
  /* exit if we get any option 
   * required because 'basename -- path' must produce a filename */
  int opt, len;
  char *dirname;
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

  /* remove trailing /'s */
  len = strlen(argv[optind]);
  while (len > 1) {
    if (len - 1 == (int)(strrchr(argv[optind], '/') - argv[optind]))
      argv[optind][--len] = 0;
    else break;
  }

  /* remove everything from the last / */
  dirname = strrchr(argv[optind], '/');
  if (dirname != NULL && len > 1)
    argv[optind][len-strlen(dirname)] = 0;
  dirname = argv[optind];

  /* remove trailing /'s again */
  len = strlen(dirname);
  while (len > 1) {
    if (len - 1 == (int)(strrchr(dirname, '/') - dirname))
      dirname[--len] = 0;
    else break;
  }

  printf("%s\n", dirname);
  return 0;
}

