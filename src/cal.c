#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* cal */

void printheader (struct tm *time) {
  char buffer[80];
  /* strftime thinks months start from 0 */
  time->tm_mon--;
  strftime(buffer, 80, "   %B %Y", time);
  time->tm_mon++;
  puts(buffer);
}

#define draw()                                                                \
          for (i = 0; i < 6; i++)                                             \
            printf("%2d %2d %2d %2d %2d %2d %2d\n", array[i], array[i+1],     \
              array[i+2], array[i+3], array[i+4], array[i+5], array[i+6]);

void printmonth (struct tm *time) {
  int array[42] = {0}, i = 0,
      shift[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 },
      monthlen[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (isleap(time->tm_year)) {
    shift[] = { 0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };
    monthlen[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  }

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
  time_t unix_time;
  time(&unix_time);
  local_time = localtime(&unix_time);
  switch (argc) {
    case 1:
      break;
    case 2:
      local_time->tm_year = (unsigned) atoi(argv[1]);
      local_time->tm_mon = 0;
      break;
    case 3:
      local_time->tm_mon = (unsigned) atoi(argv[1]);
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
  local_time->tm_year -= 1900;
  char days[] = "Su Mo Tu We Th Fr Sa";
  if (!local_time->tm_mon) while (++local_time->tm_mon < 13) {
    printheader(local_time);
    puts(days);
    printmonth(local_time);
  }
  else {
    printheader(local_time);
    puts(days);
    printmonth(local_time);
  }
  return 0;
}
