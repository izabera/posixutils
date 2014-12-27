#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
/* cat */

int main (int argc, char ** argv) {
  FILE * file;
  int i, exitcode = 0, opt;
  bool usebuffer = true;

  while ((opt = getopt(argc, argv, "u")) != -1) {
    switch (opt) {
      case 'u':
        usebuffer = false;
        break;
      default:
        fprintf(stderr, "Usage: %s [−u] [file...]\n", argv[0]);
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
      fprintf(stderr, "%s: couldn't open %s\n", argv[0], argv[i]);
      exitcode = 1;
      continue;
    }
    if (usebuffer) {
      while (1) {
        numbytes = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, file);
        fwrite(buffer, sizeof(unsigned char), numbytes, stdout);
        if (numbytes < BUFFER_SIZE) break;
      }
    }
    else {
      int c;
      while ((c = getc(file)) != EOF)
        putchar(c);
    }
    if (strcmp(argv[i], "-") != 0) fclose(file);
  }
  return exitcode;
}
