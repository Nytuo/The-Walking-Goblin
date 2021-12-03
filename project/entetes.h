#ifndef stdio_h
#include <stdio.h>

//Le type monstre
typedef struct
{
    int ligne ;
    int col ;
    int depl ;      /// 1=gauche, 2=haut, 3=droite, 4=bas
} monstre ;

//Donner par la prof
void recuperationGrille (FILE *f, int grille [10][10], int *largeurGrille, int *nbMonstres, monstre tabMonstres [], int *lLutin, int *cLutin, int *lPorte, int *cPorte) ;
void afficherMonstres (monstre tabMonstres [], int nbMonstres) ;
void afficherLigneVide (int largeur) ;
void afficherLigneNumeros (int grille [10][10], int largeur, int l) ;
void afficherLignePleine (int largeur) ;
void afficherGrille (int grille [10][10], int largeur) ;
int deplacementsMonstresLutins (int sensLutin, int *nbTours, int grille [10][10], int largeurGrille, int nbMonstres,
                                monstre tabMonstres [], int *lLutin, int *cLutin, int lPorte, int cPorte) ;

//Creation original
int deplacementLutin(int directionLutin, int grille [10][10], int largeurGrille, int *lLutin, int *cLutin);
void deplacement(int grille[10][10], int *initL, int *initC, int destL, int destC);
int deplacementMonstres(int grille[10][10], int largeurGrille, int nbMonstres,
                        monstre tabMonstres[]);
void RecoverCase(int direction, int *initlMonstre, int *initCmonstre, int *lMonstre, int *Cmonstre);
void Inverser(monstre *tabMonstres);
void modifMonstreDepl(monstre *tabMonstres, int value);
void modifMonstreC(monstre *tabMonstres, int value);
void modifMonstreL(monstre *tabMonstres, int value);
int accessMonstreDepl(monstre Monstres);
int* accessMonstreC(monstre *Monstres);
int* accessMonstreL(monstre *Monstres);
#endif
