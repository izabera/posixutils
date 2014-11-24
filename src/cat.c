#include <stdio.h>
#include <stdlib.h>
/*#include "getline.h"*/

int main (int argc, char ** argv) {
  FILE * file;
  int i, ret = 0;
  char c;
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
          c = fgetc(file);
          while (c != EOF) {
            /*putchar(c);*/
            /*fputc(c, stdout);*/
            putc(c, stdout);
            c = fgetc(file);
          }
          fclose(file);
        }
      }
      else
        c = fgetc(stdin);
      while (c != EOF) {
        /*putchar(c);*/
        /*fputc(c, stdout);*/
        putc(c, stdout);
        c = fgetc(stdin);
      }
    }
  }
  else {
    c = fgetc(stdin);
    while (c != EOF) {
      /*putchar(c);*/
      /*fputc(c, stdout);*/
      putc(c, stdout);
      c = fgetc(stdin);
    }
  }
  return ret;
}

