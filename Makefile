all:
	gcc -Os -s -Wall -o bin/echo -march=native src/echo.c
	gcc -Os -s -Wall -o bin/cat -march=native src/cat.c

clean:
	rm -rf bin/*
