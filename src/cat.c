#include <stdio.h>
#include <stdlib.h>
#include "getline.h"

int main (int argc, char ** argv) {
  FILE * file;
  char * line = NULL;
  int i, ret = 0;
  size_t len = 0;
  if (argc > 1) {
    for (i = 1; i < argc; i++) {
      if (argv[i][0] != '-' && argv[i][1] != 0) {
        file = fopen(argv[i], "r");
        if (!file) {
          /*fputs("Failed to open file: ", stderr);*/
          fputs("Can't open file: ", stderr);
          fputs(argv[i], stderr);
          /*fputs("\n", stderr);*/
          ret = 1;
        }
        else {
          while (getline(&line, &len, file) != -1) fputs(line, stdout);
          fclose(file);
        }
      }
      else
        while (getline(&line, &len, stdin) != -1) fputs(line, stdout);
    }
  }
  else {
    while (getline(&line, &len, stdin) != -1) fputs(line, stdout);
  }
  /*free(line);*/
  return ret;
}

