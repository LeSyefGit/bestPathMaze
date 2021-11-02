#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CLEAR_N(x,i) ((x)&~(1<<(i)))
#define GET_N(x,i) ((x)>>(i))&1
#define SET_N(x,i) ((x)|1<<(i))

struct labyrinthe
{
    int M, N;
    int entry[2], exit[2];
    unsigned short mat[10][10];
    int x,y;
};
typedef struct labyrinthe Lab;

void generateLabFull(int row, int col){ // génere un lab plein avec tous les murs batis
    char *c= "\n\n";
    for (int i=0; i< row;i++){
        for (int z=0; z< col;z++){
            printf("####");
        }
        printf("#\n");
        for (int j=0; j< col;j++){
            printf("# 9 ");
        }
        printf("#\n");
    }
    for (int t=0; t< col;t++){
            printf("####");
    }
    printf("#\n\n");
    //printf(s);
}


void generateLab(int n, int m, unsigned short mat[0][0],char lab[0][0]){ // génere un lab cohérent en cassant aléatoirement les colones et places les entrées et sorties
    //mat = new unsigned short [n][m];
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<m ; j++){

            lab[2*i+1][2*j+1] = (GET_N(mat[i][j],15) ==1) ? '-': ' '; // is part of the final path

            lab[2*i][2*j+1] = (GET_N(mat[i][j],0) == 1) ? '=': ' '; // up
            lab[2*i+1][2*j+2] = (GET_N(mat[i][j],1) == 1) ? '|': ' '; // right
            lab[2*i+2][2*j+1] = (GET_N(mat[i][j],2) ==1) ? '=': ' '; // down
            lab[2*i+1][2*j] = (GET_N(mat[i][j],3) ==1) ? '|': ' '; // left

            lab[2*i][2*j] = '*';                           //up left
            lab[2*i][2*j+2] = '*';                           //up right
            lab[2*i+2][2*j+2] = '*';                           //down right
            lab[2*i+2][2*j] = '*';                          //down left
        }
    }   
    

}

void printlabsimple(int n, int m,char lab[0][0]){  // va interpreter le lab créé et l'afficher (version simple sans afficher les intersections de routes)
    printf("sdfsdf %d , %d\n",n,m);
    for(int i=0; i< 2*n+1 ;i++){
        for(int j=0; j< 2*m+1 ; j++){
                printf("%c",lab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


/// pour charger le fichier contenant les lab

int verifyLab(){  // 1 si le lab est cohérent 0 sinon
    return 0;  // todo 
}

void readMaze(int tab[6], unsigned short mat[tab[0]][tab[1]],char lab[2*tab[0]+1][2*tab[1]+1]){ // mettre a jour les différents 
    FILE *fp = fopen("mazefile.txt", "r");
    if(fp == NULL) {
        perror("Unable to open file!");
        exit(1);
    }
 
    // Read lines using POSIX function getline
    // This code won't work on Windows
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    char * token = strtok(line, " ");
    //int tab[6];
    int i= 0;
   // loop through the string to extract all other tokens
    while( token != NULL ) {
        //printf( " %s\n", token ); //printing each token
        tab[i]= atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    i=0;
    int j=0;
    while(getline(&line, &len, fp) != -1) {
        //printf("line: %s\n", line);
        token = strtok(line, " ");

        while(token != NULL) {
            mat[i][j]= atoi(token);
            //lab[i][j]= atoi(token);
            //printf("the mat:%d and token: %s\n",mat[i][j],token);
            //printf("the mat:%s and token: %s\n",matbin[i][j],token);
            token = strtok(NULL, " ");
            
            j++;
        }
        j=0;
        i++;
    }

    fclose(fp);
    free(line);
}

int main(int argc, char const *argv[])
{   

    generateLabFull(10,10);

    printf("test to verity %d", SET_N(3,3));
    printf("test to verity %d", GET_N(3,2));
    printf("test to verity %d", CLEAR_N(3,1));


    int tab[6];
    unsigned short mat[tab[0]][tab[1]];
    char lab[2*tab[0]+1][2*tab[1]+1];
    readMaze(tab,mat,lab);
    int n = tab[0];
    int m = tab[1];
    printf("sdfsdf %d ,d %d\n",n,m);
    generateLab(n,m,mat,lab);
    printlabsimple(n,m,lab);

    printf("juset tot sldjf %d",mat[5][6]);


    //readMaze();
    return 0;
}