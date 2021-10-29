#include <stdio.h>

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
    printf(s);
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


int main(int argc, char const *argv[])
{   

    unsigned short x = 110;
    int c= 185;
    printf("%016X\n",x);
    printf("%d\n",x);
    printf("lmlkg fdsg %c kjfdlkgj\n",c);

    generateLabFull(10,10);
    return 0;
}