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
  char *basename;
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

  /* remove trailing /'s */
  len = strlen(argv[optind]);
  while (len > 1) {
    if (len - 1 == (int)(strrchr(argv[optind], '/') - argv[optind]))
      argv[optind][--len] = 0;
    else break;
  }

  /* remove everything up to the last / */
  basename = strrchr(argv[optind], '/');
  if (basename != NULL && len > 1) basename++;
  else basename = argv[optind];

  /* check suffixes */
  if (argc - optind == 2)
    if ((len = strlen(argv[optind+1])) > 0) 
      if (strcmp(basename + len - 1, argv[optind+1]) == 0)
        basename[len-1] = 0;

  printf("%s\n", basename);
  return 0;
}

