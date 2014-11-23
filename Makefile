all:
	gcc -Os -s -Wall -o bin/echo src/echo.c

clean:
	rm -rf bin/*
