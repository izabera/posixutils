CC=diet gcc
CFLAGS=-Wall -Os -s -fno-inline -nostdinc

all:
	$(CC) $(CFLAGS) -o bin/echo -march=native src/echo.c
	#$(CC) $(CFLAGS) -o bin/echo -march=native src/echo.c
	$(CC) $(CFLAGS) -o bin/cat -march=native src/cat.c
	$(CC) $(CFLAGS) -o bin/rev -march=native src/rev.c
	#$(CC) $(CFLAGS) -o bin/true -march=native src/true.c
	#$(CC) $(CFLAGS) -o bin/false -march=native src/false.c
	nasm -f bin -o bin/true src/true.asm
	chmod +x bin/true
	nasm -f bin -o bin/false src/false.asm
	chmod +x bin/false
	nasm -f bin -o bin/helloworld src/helloworld.asm
	chmod +x bin/helloworld

clean:
	rm -rf bin/*
