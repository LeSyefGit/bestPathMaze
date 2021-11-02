#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Display the maze. */
void ShowMaze(char *maze, int n, int m) {
   int x, y;
   for(y = 0; y < m; y++) {
      for(x = 0; x < n; x++) {
         switch(maze[y * n + x]) {
         case 1:  printf("[]");  break;
         case 2:  printf("--");  break;
         default: printf("  ");  break;
         }
      }
      printf("\n");
   }
}

/*  Carve the maze starting at x, y. */
void CarveMaze(char *maze, int n, int m, int x, int y) {

   int x1, y1;
   int x2, y2;
   int dx, dy;
   int dir, count;

   dir = rand() % 4;
   count = 0;
   while(count < 4) {
      dx = 0; dy = 0;
      switch(dir) {
      case 0:  dx = 1;  break;
      case 1:  dy = 1;  break;
      case 2:  dx = -1; break;
      default: dy = -1; break;
      }
      x1 = x + dx;
      y1 = y + dy;
      x2 = x1 + dx;
      y2 = y1 + dy;
      if(   x2 > 0 && x2 < n && y2 > 0 && y2 < m
         && maze[y1 * n + x1] == 1 && maze[y2 * n + x2] == 1) {
         maze[y1 * n + x1] = 0;
         maze[y2 * n + x2] = 0;
         x = x2; y = y2;
         dir = rand() % 4;
         count = 0;
      } else {
         dir = (dir + 1) % 4;
         count += 1;
      }
   }

}

/* Generate maze in matrix maze with size n, m. */
void GenerateMaze(char *maze, int n, int m) {

   int x, y;

   /* Initialize the maze. */
   for(x = 0; x < n * m; x++) {
      maze[x] = 1;
   }
   maze[1 * n + 1] = 0;

   /* Seed the random number generator. */
   srand(time(0));

   /* Carve the maze. */
   for(y = 1; y < m; y += 2) {
      for(x = 1; x < n; x += 2) {
         CarveMaze(maze, n, m, x, y);
      }
   }

   /* Set up the entry and exit. */
   maze[0 * n + 1] = 0;
   maze[(m - 1) * n + (n - 2)] = 0;

}

/* Solve the maze. */
void SolveMaze(char *maze, int n, int m) {

   int dir, count;
   int x, y;
   int dx, dy;
   int forward;

   /* Remove the entry and exit. */
   maze[0 * n + 1] = 1;
   maze[(m - 1) * n + (n - 2)] = 1;

   forward = 1;
   dir = 0;
   count = 0;
   x = 1;
   y = 1;
   while(x != n - 2 || y != m - 2) {
      dx = 0; dy = 0;
      switch(dir) {
      case 0:  dx = 1;  break;
      case 1:  dy = 1;  break;
      case 2:  dx = -1; break;
      default: dy = -1; break;
      }
      if(   (forward  && maze[(y + dy) * n + (x + dx)] == 0)
         || (!forward && maze[(y + dy) * n + (x + dx)] == 2)) {
         maze[y * n + x] = forward ? 2 : 3;
         x += dx;
         y += dy;
         forward = 1;
         count = 0;
         dir = 0;
      } else {
         dir = (dir + 1) % 4;
         count += 1;
         if(count > 3) {
            forward = 0;
            count = 0;
         }
      }
   }

   /* Replace the entry and exit. */
   maze[(m - 2) * n + (n - 2)] = 2;
   maze[(m - 1) * n + (n - 2)] = 2;

}

int main(int argc,char *argv[]) {

   int n, m;
   char *maze;

   if(argc != 3 && argc != 4) {
      printf("wrong parameters\n");
      exit(EXIT_FAILURE);
   }

   /* Get and validate the size. */
   n = atoi(argv[1]) * 2 + 3;
   m = atoi(argv[2]) * 2 + 3;
   if(n < 7 || m < 7) {
      printf("error: illegal maze size\n");
      exit(EXIT_FAILURE);
   }
   if(argc == 4 && argv[3][0] != 's') {
      printf("error: invalid argument\n");
      exit(EXIT_FAILURE);
   }

   /* Allocate the maze array. */
   maze = (char*)malloc(n * m * sizeof(char));
   if(maze == NULL) {
      printf("error: not enough memory\n");
      exit(EXIT_FAILURE);
   }

   /* Generate and display the maze. */
   GenerateMaze(maze, n, m);
   ShowMaze(maze, n, m);

   /* Solve the maze if requested. */
   if(argc == 4) {
      SolveMaze(maze, n, m);
      printf("\n");
      ShowMaze(maze, n, m);
   }

   /* Clean up. */
   free(maze);
   exit(EXIT_SUCCESS);

}