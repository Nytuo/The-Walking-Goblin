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


int deplacementsMonstresLutins(int sensLutin, int *nbTours, int grille[10][10], int largeurGrille, int nbMonstres,
                               monstre tabMonstres[], int *lLutin, int *cLutin, int lPorte, int cPorte) {
    int res = deplacementLutin(sensLutin, grille, largeurGrille, lLutin, cLutin);
    deplacementMonstre(nbTours, grille, largeurGrille, nbMonstres, tabMonstres);
    (*nbTours)++;
    if (res == 0) {
        return 0;

    } else if (res == 1) {
        return 1;
    } else if (res == -1) {
        return 2;
    }

}

void permutation(int grille[10][10], int *coordX_init, int *coordY_init, int coordX_dest, int coordY_dest) {
    //permutation dans une liste
    grille[coordX_dest][coordY_dest] = grille[*coordX_init][*coordY_init];
    grille[*coordX_init][*coordY_init] = 0;
    *coordY_init = coordY_dest;
    *coordX_init = coordX_dest;
}

void inverted(monstre *tabMonstres) {
    //inversion dans une liste
    if (tabMonstres->depl == 1) {
        tabMonstres->depl = 3;
    } else if (tabMonstres->depl == 2) {
        tabMonstres->depl = 4;
    } else if (tabMonstres->depl == 3) {
        tabMonstres->depl = 1;
    } else if (tabMonstres->depl == 4) {
        tabMonstres->depl = 2;
    }
}

void
FoundFront(int grille[10][10], int largeurGrille, int direction, int *lMonstresInt, int *CmonstresInt, int *lMonstres,
           int *Cmonstres) {
    if (direction == 1) {
        *lMonstres = *lMonstresInt;
        *Cmonstres = *CmonstresInt-1;
    } else if (direction == 2) {
        *lMonstres = *lMonstresInt-1;
        *Cmonstres = *CmonstresInt;
    } else if (direction == 3) {
        *lMonstres = *lMonstresInt;
        *Cmonstres = *CmonstresInt+1;
    } else if (direction == 4) {
        *lMonstres = *lMonstresInt+1;
        *Cmonstres = *CmonstresInt;
    }
}

/// 1=gauche, 2=haut, 3=droite, 4=bas
int deplacementMonstre(int *nbTours, int (*grille)[10], int largeurGrille, int nbMonstres, monstre *tabMonstres) {
    int fini=0;
    int lMonstres, cMonstres;
    for (int i = 0; i < nbMonstres; i++) {



        FoundFront(grille, largeurGrille, tabMonstres[i].depl, &tabMonstres[i].ligne, &tabMonstres[i].col, &lMonstres,
                   &cMonstres);

        if (grille[lMonstres][cMonstres] == 1) {
            //if monster kill lutin

            permutation(grille, &tabMonstres[i].ligne, &tabMonstres[i].col, lMonstres, cMonstres);

            fini=1;

        }else if ((lMonstres > largeurGrille-1) || (lMonstres < 0) || (cMonstres > largeurGrille-1) || (cMonstres < 0) ||
            (grille[lMonstres][cMonstres] == 2) || (grille[lMonstres][cMonstres] == 3)) {
            //sort de la grille
            inverted(&tabMonstres[i]);
            FoundFront(grille, largeurGrille, tabMonstres[i].depl, &tabMonstres[i].ligne, &tabMonstres[i].col, &lMonstres,
                       &cMonstres);
            if (grille[lMonstres][cMonstres] == 1){
                permutation(grille, &tabMonstres[i].ligne, &tabMonstres[i].col, lMonstres, cMonstres);
                fini=1;
            }else if ((lMonstres > largeurGrille) || (lMonstres < 0) || (cMonstres > largeurGrille) || (cMonstres < 0) ||
                (grille[lMonstres][cMonstres] == 0)){
                permutation(grille, &tabMonstres[i].ligne, &tabMonstres[i].col, lMonstres, cMonstres);
            }
        } else{
            permutation(grille, &tabMonstres[i].ligne, &tabMonstres[i].col, lMonstres, cMonstres);
        }



    }
    return fini;

}
