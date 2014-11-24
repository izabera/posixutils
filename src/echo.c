/* a saner implementation of echo
 * ==============================
 *
 * "echo -n -n x" will print "-n x" (with no newline) instead of "x"
 *
 * \x and \0 followed by a char out of bound will produce a 0 byte
 * this is the way echo works in zsh
 * (outside of that, echo in zsh is weird: backslash escapes are interpreted when
 * the parameter is quoted even without -e, but -E overrides this behaviour
 * i don't like it, stick with posix)
 *
 * in bash and gnu echo, \0 followed by an invalid char produces a 0 byte,
 * while \x followed by an invalid char produces a literal "\x" 
 * this makes no sense at all
 *
 * furthermore, \0XXX won't let you type any 3 octal digits,
 * it has to be an actual number < 256 DEC
 * otherwise, only the first 2 digits will be used */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int cut = 0;

char * replace (char * str);
char * str_replace (const char * string, const char * substr, const char * replacement);
char * octhex (char * str);
char convert (char c);

char * str_replace (const char * string, const char * substr, const char * replacement) {
  char * tok = NULL;
  char * newstr = NULL;
  char * oldstr = NULL;
  newstr = strdup (string);
  while ((tok = strstr (newstr, substr))) {
    oldstr = newstr;
    newstr = malloc (strlen (oldstr) - strlen (substr) + strlen (replacement) + 1);
    /* failed to alloc mem, free old string and return NULL */
    if (newstr == NULL) {
      free (oldstr);
      return NULL;
    }
    memcpy (newstr, oldstr, tok - oldstr);
    memcpy (newstr + (tok - oldstr), replacement, strlen (replacement));
    memcpy (newstr + (tok - oldstr) + strlen (replacement),
            tok + strlen (substr), strlen (oldstr) - strlen (substr) - (tok - oldstr));
    memset (newstr + strlen (oldstr) - strlen (substr) + strlen (replacement), 0, 1);
    free (oldstr);
  }
  return newstr;
}

char * octhex (char * str) {
  char * newstr = NULL;
  char tmpstr[3];
  char a, b, c, tot = 0;
  int amount = 0;
  newstr = strdup (str);
  int i;
  for (i = 0; newstr[i]; i++)
    if (i+2 < strlen (newstr)) {
      memcpy (tmpstr, newstr + i, 2);
      tmpstr[2] = 0;
      if (!strcmp(tmpstr, "\\0")) {
        printf ("lallal");
        if (newstr[i+2] && newstr[i+2] < '8' && newstr[i+2] >= '0') {
          a = newstr[i+2] - '0';
          tot = a;
          amount = 1;
          i++;
          if (newstr[i+2] && newstr[i+2] < '8' && newstr[i+2] >= '0') {
            b = newstr[i+2] - '0';
            tot = tot * 8 + b;
            amount++;
            i++;
            if (tot < 32 && newstr[i+2] && newstr[i+2] < '8' && newstr[i+2] >= '0') {
              c = newstr[i+2] - '0';
              tot = tot * 8 + c;
              amount++;
              i++;
            }
          }
        }
        i -= amount;
        memmove (newstr + i, newstr + i + amount + 1, strlen (newstr));
        newstr[i] = tot;
      }
      else if (!strcmp(tmpstr, "\\x")) {
        printf ("lalala");
        if (newstr[i+2] && ( (newstr[i+2] <= '9' && newstr[i+2] >= '0') ||
                             (newstr[i+2] <= 'f' && newstr[i+2] >= 'a') ||
                             (newstr[i+2] <= 'F' && newstr[i+2] >= 'A') ) ) {
          a = convert(newstr[i+2]);
          tot = a;
          amount = 1;
          i++;
          if (newstr[i+2] && ( (newstr[i+2] <= '9' && newstr[i+2] >= '0') ||
                               (newstr[i+2] <= 'f' && newstr[i+2] >= 'a') ||
                               (newstr[i+2] <= 'F' && newstr[i+2] >= 'A') ) ) {
            b = convert(newstr[i+2]);
            tot = tot * 16 + b;
            amount++;
            i++;
          }
        }
        i -= amount;
        memmove (newstr + i, newstr + i + amount + 1, strlen (newstr));
        newstr[i] = tot;
      }
    }
  /* this was a pain. there must be an easier way */
  return newstr;
}

char * replace (char * str) {
  if (strstr (str, "\\")) {
    char * tmp;
    if ((tmp = strstr (str, "\\c"))) {
      strncpy (tmp, "\0", 1);
      cut = 1;
    }
    str = str_replace (str, "\\a", "\a");
    str = str_replace (str, "\\b", "\b");
    str = str_replace (str, "\\e", "\e");
    str = str_replace (str, "\\f", "\f");
    str = str_replace (str, "\\n", "\n");
    str = str_replace (str, "\\r", "\r");
    str = str_replace (str, "\\t", "\t");
    str = str_replace (str, "\\v", "\v");
    if (strstr (str, "\\0")) {
      str = octhex (str);
    }
  }
  return str;
}

char convert (char c) {
  c = (c - '0') % 38;
  return c > 16 ? c - 7 : c;
}

int main (int argc, char ** argv) {
  unsigned short int n = FALSE, e = FALSE;
  unsigned int startfrom = 1, i;
  if (argc > 1) {
    if (!strcmp(argv[1], "-n")) n = TRUE, startfrom++;
    if (!strcmp(argv[1], "-e")) e = TRUE, startfrom++;
    if (!strcmp(argv[1], "-ne") || !strcmp(argv[1], "-en")) e = TRUE, n = TRUE, startfrom++;
    if (argc > 2) {
      if (!strcmp(argv[2], "-n") && !strcmp(argv[1], "-e")) n = TRUE, startfrom++;
      if (!strcmp(argv[2], "-e") && !strcmp(argv[1], "-n")) e = TRUE, startfrom++;
    }
  }
  for (i = startfrom; i < argc && cut == 0; i++)
    printf (i < argc - 1 ? "%s " : "%s", e ? replace (argv[i]) : argv[i]);
  if (!n && !cut) printf ("\n");
  return 0;
}

