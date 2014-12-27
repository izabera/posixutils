#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void quit() { exit(EXIT_SUCCESS); }

int main (int argc, char *argv[]) {
  unsigned int num;
  if (argc != 2) {
    fprintf(stderr, "Usage: %s time\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  signal(SIGALRM, quit);

  /* posix doesn't require validation */
  num = atoi(argv[1]);
  sleep(num);
  return 0;
}
