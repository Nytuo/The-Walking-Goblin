//
// Created by vc108395 on 12/11/2021.
//
/*0 : la case est vide,
1 : la case contient le lutin,
2 : la case contient un monstre,
3 : la case contient la porte de sortie.*/
/*1 : le lutin se déplace vers la gauche si c’est possible,
2 : le lutin se déplace vers le haut si c’est possible,
3 : le lutin se déplace vers la droite si c’est possible,
4 : le lutin se déplace vers le bas si c’est possible.*/
#include "entetes.h"


int deplacementsMonstresLutins (int sensLutin, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                                monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) {
    deplacementLutin( sensLutin, nbTours, grille, largeurGrille, nbMonstres,tabMonstres, lLutin, cLutin, lPorte, cPorte);
    (*nbTours)++;
    printf("%d\n", *nbTours);
return 0;
}

void permutation(int grille [10][10], int *coordX_init, int *coordY_init, int coordX_dest, int coordY_dest) {
    //permutation dans une liste
    grille[coordX_dest][coordY_dest]=grille[*coordX_init][*coordY_init];
    grille[*coordX_init][*coordY_init]=0;
    *coordY_init = coordY_dest;
    *coordX_init = coordX_dest;
}
void deplacementMonstre(){

}