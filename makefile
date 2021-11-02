# build an executable named labyrinthe2D from labyrinthe2D.c
all: maze.c
	gcc -g -Wall -o maze maze.c -I.

clean:
	$(RM) myprog