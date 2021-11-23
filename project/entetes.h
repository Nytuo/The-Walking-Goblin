#ifndef MON_H
#define MON_H

#include <stdio.h>




typedef struct
{
    int ligne ;
    int col ;
    int depl ;      /// 1=gauche, 2=haut, 3=droite, 4=bas
} monstre ;




void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille, int *nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int *lPorte, int *cPorte) ;
void afficherMonstres (monstre tabMonstres [], int nbMonstres) ;
void afficherLigneVide (int largeur) ;
void afficherLigneNumeros (int grille [10][10], int largeur, int l) ;
void afficherLignePleine (int largeur) ;
void afficherGrille (int grille [10][10], int largeur) ;


int deplacementsMonstresLutins (int sensLutin, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                                monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) ;
int deplacementLutin(int sensLutin, int grille [10][10], int largeurGrille, int *lLutin, int *cLutin);
void permutation(int grille[10][10], int *coordX_init, int *coordY_init, int coordX_dest, int coordY_dest);
int deplacementMonstre( int *nbTours, int grille[10][10], int largeurGrille, int nbMonstres,
                         monstre tabMonstres[]);
void FoundFront(int grille[10][10], int largeurGrille,int direction, int *lMonstresInt,int *CmonstresInt,int *lMonstres,int *Cmonstres);
#endif
