#include "entetes.h"

int deplacementLutin(int sensLutin, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                     monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte){
    if (sensLutin==1){
        /*gauche*/
        if (grille[*lLutin-1][*cLutin]==0){
            //Si il y a un monstre à gauche
            permutation(grille, lLutin, cLutin, *lLutin, *cLutin-1);
            return 0;
        }
        else if (grille[*lLutin-1][*cLutin]==2){
            //Si on tombe sur un monstre == mort
            return -1;
        }
        else if(*lLutin+1<0){
            //Si on sort de la grille
            return 0;
        }
        else if (grille[*lLutin-1][*cLutin]==3){
            //Si on tombe sur la porte
            return 1;
        }
    }
    if (sensLutin==2){
        /*haut*/
            if (grille[*lLutin][*cLutin+1]==0){
                //Si il y a un monstre à bas
                permutation(grille, lLutin, cLutin, *lLutin-1, *cLutin);
                return 0;
            }
            else if (grille[*lLutin][*cLutin+1]==2){
                //Si on tombe sur un monstre == mort
                return -1;
            }
            else if(*cLutin-1>largeurGrille){
                //Si on sort de la grille
                return 0;
            }
            else if (grille[*lLutin][*cLutin+1]==3){
                //Si on tombe sur la porte
                return 1;
        }
    }
    if (sensLutin==3){
        /*droite*/
        if (grille[*lLutin+1][*cLutin]==0){
            //Si il y a un monstre à gauche
            permutation(grille, lLutin, cLutin, *lLutin, *cLutin+1);
            return 0;
        }
        else if (grille[*lLutin+1][*cLutin]==2){
            //Si on tombe sur un monstre == mort
            return -1;
        }
        else if(*lLutin-1>0){
            //Si on sort de la grille
            return 0;
        }
        else if (grille[*lLutin+1][*cLutin]==3){
            //Si on tombe sur la porte
            return 1;}

    }
    if (sensLutin==4){
        if (grille[*lLutin][*cLutin-1]==0){
            //Si il y a un monstre à bas
            permutation(grille, lLutin, cLutin, *lLutin+1, *cLutin);
            return 0;
        }
        else if (grille[*lLutin][*cLutin-1]==2){
            //Si on tombe sur un monstre == mort
            return -1;
        }
        else if(*cLutin+1>largeurGrille){
            //Si on sort de la grille
            return 0;
        }
        else if (grille[*lLutin][*cLutin-1]==3){
            //Si on tombe sur la porte
            return 1;
        }
    }

}