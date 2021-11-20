#include "entetes.h"

int deplacementLutin(int sensLutin, int *nbTours, int grille[10][10], int largeurGrille, int nbMonstres,
                     monstre tabMonstres[], int *lLutin, int *cLutin, int lPorte, int cPorte) {
    if (sensLutin == 1) {
        /*gauche*/
        if (grille[*lLutin][*cLutin - 1] == 0) {
            //Si il y a un rien à gauche
            permutation(grille, lLutin, cLutin, *lLutin, *cLutin - 1);
            return 0;
        } else if (grille[*lLutin][*cLutin - 1] == 2) {
            //Si on tombe sur un monstre == mort
            return -1;
        } else if (grille[*lLutin][*cLutin - 1] == 3) {
            //Si on tombe sur la porte
            permutation(grille, lLutin, cLutin, *lLutin, *cLutin - 1);

            return 1;
        } else if (*lLutin + 1 < 0) {
            //Si on sort de la grille
            return 0;
        }
    }
    if (sensLutin == 2) {
        /*haut*/
        if (grille[*lLutin - 1][*cLutin] == 0) {
            //Si il y a un rien en haut
            permutation(grille, lLutin, cLutin, *lLutin - 1, *cLutin);
            return 0;
        } else if (grille[*lLutin - 1][*cLutin] == 2) {
            //Si on tombe sur un monstre == mort
            return -1;
        } else if (grille[*lLutin - 1][*cLutin] == 3) {
            //Si on tombe sur la porte
            permutation(grille, lLutin, cLutin, *lLutin - 1, *cLutin);

            return 1;
        } else if (*cLutin - 1 > largeurGrille) {
            //Si on sort de la grille
            return 0;
        }
    }
    if (sensLutin == 3) {
        /*droite*/
        if (grille[*lLutin][*cLutin + 1] == 0) {
            //Si il y a un rien à droite
            permutation(grille, lLutin, cLutin, *lLutin, *cLutin + 1);
            return 0;
        } else if (grille[*lLutin][*cLutin + 1] == 2) {
            //Si on tombe sur un monstre == mort
            return -1;
        } else if (grille[*lLutin][*cLutin + 1] == 3) {
            //Si on tombe sur la porte
            permutation(grille, lLutin, cLutin, *lLutin, *cLutin + 1);
            return 1;
        } else if (*lLutin - 1 > 0) {
            //Si on sort de la grille
            return 0;
        }
    }
    if (sensLutin == 4) {
        /*bas*/
        if (grille[*lLutin + 1][*cLutin] == 0) {
            //Si il y a un rien en bas
            permutation(grille, lLutin, cLutin, *lLutin + 1, *cLutin);
            return 0;
        } else if (grille[*lLutin + 1][*cLutin] == 2) {
            //Si on tombe sur un monstre == mort
            return -1;
        } else if (grille[*lLutin + 1][*cLutin] == 3) {
            //Si on tombe sur la porte
            permutation(grille, lLutin, cLutin, *lLutin + 1, *cLutin);

            return 1;
        } else if (*cLutin + 1 > largeurGrille) {
            //Si on sort de la grille
            return 0;
        }
    }

}