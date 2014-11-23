#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int cut = 0;

char * str_replace ( const char *string, const char *substr, const char *replacement );
char * replace (char * str);
char * octhex (char * str);

char * str_replace ( const char *string, const char *substr, const char *replacement ){
  char *tok = NULL;
  char *newstr = NULL;
  char *oldstr = NULL;
  newstr = strdup (string);
  while ( (tok = strstr ( newstr, substr ))){
    oldstr = newstr;
    newstr = malloc ( strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) + 1 );
    /* failed to alloc mem, free old string and return NULL */
    if ( newstr == NULL ){
      free (oldstr);
      return NULL;
    }
    memcpy ( newstr, oldstr, tok - oldstr );
    memcpy ( newstr + (tok - oldstr), replacement, strlen ( replacement ) );
    memcpy ( newstr + (tok - oldstr) + strlen( replacement ), tok + strlen ( substr ), strlen ( oldstr ) - strlen ( substr ) - ( tok - oldstr ) );
    memset ( newstr + strlen ( oldstr ) - strlen ( substr ) + strlen ( replacement ) , 0, 1 );
    free (oldstr);
  }
  return newstr;
}

char * octhex (char * str) {
  /*char *tok = NULL;*/
  /*char *newstr = NULL;*/
  /*char *oldstr = NULL;*/
  /*newstr = strdup (string);*/
  /*while ( (tok = strstr ( newstr, substr ))){*/
  return str;
}

char * replace (char * str) {
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
  str = octhex (str);
  return str;
}

int main (int argc, char ** argv) {
  unsigned short int n = FALSE, e = FALSE;
  unsigned int startfrom = 1, i;
  /* a saner version of echo */
  /* "echo -n -n x" will print "-n 1" (with no newline) instead of "x"*/
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
