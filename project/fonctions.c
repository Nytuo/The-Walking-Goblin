/*
Aide Mémoire:
    Case:
 * 0 : vide
 * 1 : lutin
 * 2 : monstre
 * 3 : porte de sortie
    Direction / sens:
 * 1 : Gauche
 * 2 : Haut
 * 3 : Droite
 * 4 : Bas

 */

#include "entetes.h"

int deplacementsMonstresLutins(int sensLutin, int *nbTours, int grille[10][10], int largeurGrille, int nbMonstres,
                               monstre tabMonstres[], int *lLutin, int *cLutin, int lPorte, int cPorte) {

    //On gère les déplacements des monstres et du lutin, ainsi que les conditions de victoire / défaite.
    //On appelle deplacementLutin pour déplacer le lutin sur la grille, le resultat est récupéré pour les conditions de victoire et défaite.
    int res = deplacementLutin(sensLutin, grille, largeurGrille, lLutin, cLutin);

    //On incrémente le nombre de tours.
    (*nbTours)++;

    if (res == 1) {
        //On vérifie si le lutin a atteint la porte de sortie. (res = 1), si oui, on retourne 1, la partie est gagnée.
        return 1;

    } else if (res == -1) {
        //On vérifie si le lutin s'est jéter sur un monstre (res = -1), si oui, on retourne 2, la partie est perdue.
        return 2;

    } else {
        //On fait ce déplacer les monstres seulement si le lutin n'est pas mort et on retourne 2 si un monstre tue le Lutin, sinon on retourne 0 (partie nulle / en cours).
        //On vérifie si le lutin est sur une case vide (res = 0), si oui, on continue.

        int res2 =deplacementMonstres(grille, largeurGrille, nbMonstres, tabMonstres);
        if (res2 == 1) {
            return 2;
        }

        return 0;
    }

}

int deplacementLutin(int directionLutin, int grille[10][10], int largeurGrille,
                     int *lLutin, int *cLutin) {

    if (directionLutin == 1) {
        //Si le lutin veut aller à gauche, on vérifie qu'il reste dans la grille, qu'il ne meurt pas et si il est ou non en contact avec la porte.
        if (*cLutin -1 < 0) {
            //Le lutin va en dehors de la grille, on ne fait rien.
            return 0;
        }else
        if (grille[*lLutin][*cLutin - 1] == 0) {
            //Il n'y a rien, on déplace le lutin.
            deplacement(grille, lLutin, cLutin, *lLutin, *cLutin - 1);
            return 0;

        } else if (grille[*lLutin][*cLutin - 1] == 2) {
            //Le lutin va sur un monstre, la partie est fini.
            deplacement(grille, lLutin, cLutin, *lLutin, *cLutin - 1);
            return -1;

        } else if (grille[*lLutin][*cLutin - 1] == 3) {
            //Le lutin va sur la porte de sortie, la partie est gagnée.
            deplacement(grille, lLutin, cLutin, *lLutin, *cLutin - 1);
            return 1;


        }
    }

    if (directionLutin == 2) {
        //Si le lutin veut aller en haut, on vérifie qu'il reste dans la grille, qu'il ne meurt pas et si il est ou non en contact avec la porte.
        if (*lLutin - 1 <0) {
            //Le lutin va en dehors de la grille, on ne fait rien.
            return 0;
        }else if (grille[*lLutin - 1][*cLutin] == 0) {
            //Il n'y a rien, on déplace le lutin.
            deplacement(grille, lLutin, cLutin, *lLutin - 1, *cLutin);
            return 0;

        } else if (grille[*lLutin - 1][*cLutin] == 2) {
            //Le lutin va sur un monstre, la partie est fini.
            deplacement(grille, lLutin, cLutin, *lLutin - 1, *cLutin);
            return -1;

        } else if (grille[*lLutin - 1][*cLutin] == 3) {
            //Le lutin va sur la porte de sortie, la partie est gagnée.
            deplacement(grille, lLutin, cLutin, *lLutin - 1, *cLutin);
            return 1;

        }
    }

    if (directionLutin == 3) {
        //Si le lutin veut aller à droite, on vérifie qu'il reste dans la grille, qu'il ne meurt pas et si il est ou non en contact avec la porte.
        if (*cLutin + 1 > largeurGrille-1) {
            //Le lutin va en dehors de la grille, on ne fait rien.
            return 0;

        }else
        if (grille[*lLutin][*cLutin + 1] == 0) {
            //Il n'y a rien, on déplace le lutin.
            deplacement(grille, lLutin, cLutin, *lLutin, *cLutin + 1);
            return 0;

        } else if (grille[*lLutin][*cLutin + 1] == 2) {
            //Le lutin va sur un monstre, la partie est fini.
            deplacement(grille, lLutin, cLutin, *lLutin, *cLutin + 1);
            return -1;

        } else if (grille[*lLutin][*cLutin + 1] == 3) {
            //Le lutin va sur la porte de sortie, la partie est gagnée.
            deplacement(grille, lLutin, cLutin, *lLutin, *cLutin + 1);
            return 1;
        }
    }
    if (directionLutin == 4) {
        //Si le lutin veut aller en bas, on vérifie qu'il reste dans la grille, qu'il ne meurt pas et si il est ou non en contact avec la porte.
        if (*lLutin +1 > largeurGrille-1) {
            //Si on sort de la grille
            return 0;
        }else
        if (grille[*lLutin + 1][*cLutin] == 0) {
            //Il n'y a rien, on déplace le lutin.
            deplacement(grille, lLutin, cLutin, *lLutin + 1, *cLutin);
            return 0;

        } else if (grille[*lLutin + 1][*cLutin] == 2) {
            //Le lutin va sur un monstre, la partie est fini.
            deplacement(grille, lLutin, cLutin, *lLutin + 1, *cLutin);
            return -1;

        } else if (grille[*lLutin + 1][*cLutin] == 3) {
            //Le lutin va sur la porte de sortie, la partie est gagnée.
            deplacement(grille, lLutin, cLutin, *lLutin + 1, *cLutin);
            return 1;
        }
    }
    return 0;
}

void deplacement(int grille[10][10], int *initL, int *initC, int destL, int destC) {

    //On déplace le lutin vers une autre case de initL et initC à destL et destC.
    grille[destL][destC] = grille[*initL][*initC];
    grille[*initL][*initC] = 0;
    *initC = destC;
    *initL = destL;
}

void
RecoverCase(int direction, int *initlMonstre, int *initCmonstre, int *lMonstre,
            int *Cmonstre) {

    //On récupère les coordonnées de la case devant le monstre en fonction de sa direction.
    if (direction == 1) {
        *lMonstre = *initlMonstre;
        *Cmonstre = *initCmonstre - 1;

    } else if (direction == 2) {
        *lMonstre = *initlMonstre - 1;
        *Cmonstre = *initCmonstre;

    } else if (direction == 3) {
        *lMonstre = *initlMonstre;
        *Cmonstre = *initCmonstre + 1;

    } else if (direction == 4) {
        *lMonstre = *initlMonstre + 1;
        *Cmonstre = *initCmonstre;
    }
}