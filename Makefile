all:
	gcc -Os -s -Wall -o bin/echo -march=native src/echo.c

clean:
	rm -rf bin/*
