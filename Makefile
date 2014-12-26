CC = gcc
CFLAGS = -Wall -O2 -march=native

all:
	#$(CC) $(CFLAGS) -o bin/echo src/echo.c
	#$(CC) $(CFLAGS) -o bin/cat src/cat.c
	$(CC) $(CFLAGS) -o bin/tee src/tee.c
	$(CC) $(CFLAGS) -o bin/true src/true.c
	$(CC) $(CFLAGS) -o bin/false src/false.c

clean:
	rm -rf bin/*

