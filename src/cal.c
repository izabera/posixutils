#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/* cal */

void printheader (struct tm *time, bool printyear) {
  char buffer[22], spaces[10];
  int i;
  size_t output;
  if (printyear) output = strftime(buffer, 80, "%B %Y", time);
  else output = strftime(buffer, 80, "%B", time);
  for (i = 0; i < (21-output)/2; i++) spaces[i] = ' ';
  spaces[i] = 0;
  printf("%s%s\n", spaces, buffer);
}

#define isleap(year) ((!((year)%400)) || (((year)%100) && (!((year)%4))))
#define draw() {                                                              \
          for (i = 1; i <= monthlen[time->tm_mon]; i++)                       \
            array[i+shift] = i;                                 \
          for (i = 0; i < 6; i++)                                             \
            printf("%2d %2d %2d %2d %2d %2d %2d\n",   array[i*6+0],           \
            array[i*6+1], array[i*6+2], array[i*6+3], array[i*6+4],           \
            array[i*6+5], array[i*6+6]);                                      \
        }

void printmonth (struct tm *time) {
  int array[42] = {0}, i, j, shift,
      monthlen[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  char buffer[2];
  strftime(buffer, 2, "%w", time);
  shift = buffer[0] - '0';
  if (isleap(time->tm_year)) monthlen[1] = 29;

  if (time->tm_year > 1752-1900) {
    draw();
  }
  else if (time->tm_year == 1752-1900) {
    if (time->tm_mon > 9) {
     /* gregorian calendar */
      draw();
    }
    else if (time->tm_mon == 9) {
      puts("       1  2 14 15 16");
      puts("17 18 19 20 21 22 23");
      puts("24 25 26 27 28 29 30");
      puts("\n\n");
    }
    else {
    }
  }
  else {
    draw();
  }
}

int main (int argc, char *argv[]) {
  struct tm *local_time;
  bool printall = false;
  time_t unix_time;
  time(&unix_time);
  local_time = localtime(&unix_time);
  switch (argc) {
    case 1:
      break;
    case 2:
      local_time->tm_year = (unsigned) atoi(argv[1]);
      printall = true;
      break;
    case 3:
      local_time->tm_mon = (unsigned) atoi(argv[1]) - 1;
      local_time->tm_year = (unsigned) atoi(argv[2]);
      break;
    default:
      fprintf(stderr, "Usage: %s [[month] year]\n", argv[0]);
      exit(EXIT_FAILURE);
  }
  if (local_time->tm_mon > 12 || local_time->tm_year > 9999) {
    fprintf(stderr, "Usage: %s [[month] year]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  local_time->tm_mday = 1;
  /*local_time->tm_year -= 1900;*/
  char days[] = "Su Mo Tu We Th Fr Sa";
  if (printall) {
    do {
      printheader(local_time, false);
      puts(days);
      printmonth(local_time);
    } while (++local_time->tm_mon < 12);
  }
  else {
    printheader(local_time, true);
    puts(days);
    printmonth(local_time);
  }
  return 0;
}
