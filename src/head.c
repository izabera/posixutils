#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

/* head */

int main (int argc, char **argv) {
  FILE *file;
  int i, numlines = 10, newlinescount, tmpcount, exitcode = 0, opt;

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
  size_t numbytes;

  if (optind == argc) {
    optind--;
    strcpy(argv[optind], "-");
  }
  for (i = optind; i < argc; i++) {
    if (strcmp(argv[i], "-") == 0) file = stdin;
    else file = fopen(argv[i], "r");
    if (!file) {
      fprintf(stderr, "Error: couldn't open %s\n", argv[i]);
      exitcode = 1;
      continue;
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
