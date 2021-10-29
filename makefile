# build an executable named labyrinthe2D from labyrinthe2D.c
all: labyrinthe2D.c
	gcc -g -Wall -o labyrinthe2D labyrinthe2D.c -I.

clean: 
	$(RM) myprog