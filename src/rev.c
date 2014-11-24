#include <stdio.h>

int main (int argc, char ** argv) {
  if (argc == 1) {
    while (scanf()) {}
  }
  else if (argc == 2) {
    FILE * file;
    file = fopen (argv[1], "r");
    if (!file) {
      fprintf(stderr, "Failed to open %s\n", argv[1]);
      return 1;
    }
  }
  else {
    fprintf(stderr, "Invalid arguments");
    return 2;
  }
}

