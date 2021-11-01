#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR_N(x,n) ((x)&~(1<<(n)))
#define GET_N(x,n) ((x)>>(n))&1
#define SET_N(x,n) ((x)|1<<(n))

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

void buildCellLab(){ // va casser les murs pour creer le labyrinthe cohérent ( le lab peut ne pas avoir d'acces à la sortie) (la sortie peut etre égale à l'entrée)

}

void generateLab(){ // génere un lab cohérent en cassant aléatoirement les colones et places les entrées et sorties
    
}

void printlabwallsimple(){  // va interpreter le lab créé et l'afficher (version simple sans afficher les intersections de routes)

}
void printlabwallfinal(){   //  va afficher le lab créé avec toutes les intersections de routes (version avec les contours)
    
}

void printlabCurrent(){  // va afficher le parcours
    printlabCurrent();
}

/// pour charger le fichier contenant les lab

int verifyLab(){  // 1 si le lab est cohérent 0 sinon
    return 0;  // todo 
}

void readMaze(){ // mettre a jour les différents 
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
    int tab[6];
    int i= 0;
   // loop through the string to extract all other tokens
    while( token != NULL ) {
        printf( " %s\n", token ); //printing each token
        tab[i]= atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    //int mat[tab[0]][tab[1]];
    int mat[tab[0]][tab[1]];
    char* lab[2*tab[0]+1][2*tab[1]+1];
    i=0;
    int j=0;
    while(getline(&line, &len, fp) != -1) {
        printf("line: %s\n", line);
        token = strtok(line, " ");

        while(token != NULL) {
            mat[i][j]= atoi(token);
            //lab[i][j]= atoi(token);
            printf("the mat:%d and token: %s\n",mat[i][j],token);
            token = strtok(NULL, " ");
            
            j++;
        }
        j=0;
        i++;
    }

    printf("\n\nMax line size: %zd\n", len);

    fclose(fp);
    free(line);
}


int main(int argc, char const *argv[])
{   
    unsigned short val = 110;
    unsigned char c= 185;
    printf("%016X\n",val);
    printf("%d\n",val);
    printf("lmlkg fdsg %c kjfdlkgj\n",c);
    printf("\u2500\u2501\n");
    printf("🇧🇴\n");
    //sprintf("%c%c%c\n", (char)105, (char)213, (char)157);

    generateLabFull(10,10);

    readMaze();
    return 0;
}