/* rev from util-linux will try to read a file named "-"
 * when it receives "-" as a parameter
 *
 * this version will read from stdin */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getline.h"

int main (int argc, char ** argv) {
  FILE * file;
  char * line = NULL;
  int i, ret = 0, j;
  size_t len = 0;
  if (argc > 1) {
    for (i = 1; i < argc; i++) {
      if (argv[i][0] != '-' && argv[i][1] != 0) {
        file = fopen (argv[i], "r");
        if (!file) {
          fprintf (stderr, "Failed to open file: %s\n", argv[i]);
          ret = 1;
        }
        else
          while (getline (&line, &len, file) != -1) {
            if (line[strlen(line)-1] != '\n') printf ("%c", line[strlen(line)-1]);
            for (j = strlen (line) - 1; j > 0; j--) printf ("%c", line[j-1]);
            if (line[strlen(line)-1] == '\n') printf ("\n");
          }
        fclose(file);
      }
      else {
        while (getline (&line, &len, stdin) != -1) {
          if (line[strlen(line)-1] != '\n') printf ("%c", line[strlen(line)-1]);
          for (j = strlen (line) - 1; j > 0; j--) printf ("%c", line[j-1]);
          if (line[strlen(line)-1] == '\n') printf ("\n");
        }
      }
    }
  }
  else {
    while (getline (&line, &len, stdin) != -1) {
      if (line[strlen(line)-1] != '\n') printf ("%c", line[strlen(line)-1]);
      for (j = strlen (line) - 1; j > 0; j--) printf ("%c", line[j-1]);
      if (line[strlen(line)-1] == '\n') printf ("\n");
    }
  }
  free(line);
  return ret;
}

