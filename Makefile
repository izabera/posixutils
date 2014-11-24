CC=diet gcc
CFLAGS=-Wall -Os -s -fno-inline -nostdinc

all:
	$(CC) $(CFLAGS) -o bin/echo -march=native src/echo.c
	$(CC) $(CFLAGS) -o bin/cat -march=native src/cat.c
	$(CC) $(CFLAGS) -o bin/rev -march=native src/rev.c

clean:
	rm -rf bin/*
