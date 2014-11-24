size_t getline(char **lineptr, size_t *n, FILE *stream) {
  if (lineptr == NULL || stream == NULL || n == NULL) {
    return -1;
  }
  char *bufptr = *lineptr;
  size_t size = *n;

  int c = fgetc(stream);
  if (c == EOF) {
    return -1;
  }
  bufptr = malloc(128);
  if (bufptr == NULL) {
    return -1;
  }
  size = 128;
  char *p = bufptr;
  while(c != EOF) {
    if ((p - bufptr) > (size - 1)) {
      size = size + 128;
      bufptr = realloc(bufptr, size);
      if (bufptr == NULL) {
        return -1;
      }
    }
    *p++ = c;
    if (c == '\n') {
      break;
    }
    c = fgetc(stream);
  }

  *p++ = '\0';
  *lineptr = bufptr;
  *n = size;

  return p - bufptr - 1;
}
