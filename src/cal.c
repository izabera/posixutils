#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
/* cal */

/* TODO:
 *   print full calendar on 3 columns 
 *   fix the 1900 issue since we don't really need it
 *   generate days' 2 letter names instead of hardcoding them */

void printheader (struct tm *time, bool printyear) {
  char buffer[22], spaces[10];
  int i;
  size_t output;
  if (printyear) output = strftime(buffer, 80, "%B %Y", time);
  else output = strftime(buffer, 80, "%B", time);
  spaces[i] = 0;
  printf("%s%s\n", spaces, buffer);
}

/* sakamoto method to get the day of week in gregorian calendar */
int dow (int y, int m, int d) {
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}


#define isleap(year) ((!((year)%400)) || (((year)%100) && (!((year)%4))))
#define draw() {                                                              \
          for (i = 1; i <= monthlen[time->tm_mon]; i++)                       \
            array[i+shift-1] = i;                                             \
          for (i = 0; i < 6; i++) {                                           \
            for (j = 0; j < 6; j++)                                           \
              if (array[i*7+j] != 0) printf("%2d ", array[i*7+j]);            \
              else printf("   ", array[i*7+j]);                               \
            if (array[i*7+j] != 0) printf("%2d\n", array[i*7+j]);             \
            else printf("  \n", array[i*7+j]);                                \
          }                                                                   \
        }

void printmonth (struct tm *time) {
  int array[42] = {0}, i, j, shift,
      monthlen[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  shift = dow(time->tm_year + 1900, time->tm_mon + 1, time->tm_mday);
  if (isleap(time->tm_year)) monthlen[1] = 29;

  if (time->tm_year > 1752-1900) {
    draw();
  }
  else if (time->tm_year == 1752-1900) {
    if (time->tm_mon > 9) {
     /* gregorian calendar starts here */
      draw();
    }
    else if (time->tm_mon == 8) {
      puts("       1  2 14 15 16");
      puts("17 18 19 20 21 22 23");
      puts("24 25 26 27 28 29 30");
      puts("\n\n");
    }
    else {
      shift = (shift+4) % 7;
      draw();
    }
  }
  else {
    shift = (shift+4) % 7;
    draw();
  }
}

/* FIXME */
#define generate_days()                                                       \
          struct tm *tmp;                                                     \
          char buffer[5];                                                     \
          for (tmp->tm_wday = 0; tmp->tm_wday < 7; tmp->tm_wday++) {          \
            strftime(buffer, 5, "%a", tmp);                                   \
            printf ("%s-",buffer);                                            \
          }                                                                   \
          printf("coso %s\n", days);


int main (int argc, char *argv[]) {
  struct tm *local_time;
  bool printall = false;
  time_t unix_time;
  time(&unix_time);
  local_time = localtime(&unix_time);

  /* why most of this is idiotic:
   *
   * 1. strftime thinks year 0 is 1900
   * we have to remove 1900 if the user inputs a parameter
   * add 1900 and remove it if no parameter was inserted
   *
   * 2. strftime thinks jan = 0
   * which is not too bad compared to the workaround required for the years
   * 
   * 3. strftime only uses the gregorian calendar
   * we need to hand convert the days before september 1752
   *
   * 4. the tm structure doesn't contain an actual date
   * we can't generate it with mktime to know the day of the week
   * it fails on 32 bit machines when year < 1912    (year 2038 bug) */

  switch (argc) {
    case 1:
      local_time->tm_year += 1900;
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
  local_time->tm_year -= 1900;

  char days[] = "Su Mo Tu We Th Fr Sa";
  /*char days[22];*/
  /*generate_days();*/

  if (printall) {
    local_time->tm_mon = 0;
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
