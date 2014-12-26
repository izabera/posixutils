#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

/* tee */

/* any option that's not -a or -i is treated as files */

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
      exitcode = 1;
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

