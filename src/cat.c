#include <stdio.h>
#include <stdlib.h>

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
          fprintf(stderr, "Failed to open file: %s\n", argv[i]);
          ret = 1;
        }
        else
          while (getline(&line, &len, file) != -1) printf("%s", line);
        fclose(file);
      }
      else
        while (getline(&line, &len, stdin) != -1) printf("%s", line);
    }
  }
  else {
    while (getline(&line, &len, stdin) != -1) printf("%s", line);
  }
  free(line);
  return ret;
}

