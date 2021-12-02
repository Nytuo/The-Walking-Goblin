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

void Inverser(monstre *tabMonstres) {

    //Inversion du sens de direction des monstres.
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

int deplacementMonstres(int grille[10][10], int largeurGrille, int nbMonstres, monstre *tabMonstres) {
    //Gère le déplacement des monstres.
    int over = 0;
    int lMonstre, cMonstre;

    //Pour chaque monstre, le déplacer (si possible) et vérifier la défaite du monstre.
    for (int i = 0; i < nbMonstres; i++) {
        //On récupère les coordonnées de la case devant le monstre (lMonstre, cMonstre).
        RecoverCase(tabMonstres[i].depl, &tabMonstres[i].ligne, &tabMonstres[i].col, &lMonstre,
                    &cMonstre);


        if (grille[lMonstre][cMonstre] == 1) {
            //Si le monstre entre en collision avec le lutin, la partie est finie (over = 1).
            over = 1;

        } else if (((lMonstre > largeurGrille - 1) || (lMonstre < 0) || (cMonstre > largeurGrille - 1) ||
                    (cMonstre < 0)) ||
                   (grille[lMonstre][cMonstre] == 2) || (grille[lMonstre][cMonstre] == 3)) {

            //On teste si le monstre quitte la grille ou si il rencontre un autre monstre / la porte et on le fait se retourner puis on teste la case devant lui.

            Inverser(&tabMonstres[i]);

            RecoverCase(tabMonstres[i].depl, &tabMonstres[i].ligne, &tabMonstres[i].col,
                        &lMonstre,
                        &cMonstre);

            if (grille[lMonstre][cMonstre] == 1) {
                //Si le monstre entre en collision avec le lutin, la partie est finie (over = 1).
                over = 1;

            } else if (((lMonstre <= largeurGrille - 1) && (lMonstre >= 0) && (cMonstre <= largeurGrille - 1) &&
                        (cMonstre >= 0)) && (grille[lMonstre][cMonstre] == 0)) {

                //Si le monstre ne quitte pas la grille et peut se déplacer car la case est libre, on le déplace.
                deplacement(grille, &tabMonstres[i].ligne, &tabMonstres[i].col, lMonstre, cMonstre);
            }
        } else {

            //Si la case est libre sans obstacle, on déplace le monstre sur cette case.

            deplacement(grille, &tabMonstres[i].ligne, &tabMonstres[i].col, lMonstre, cMonstre);
        }
    }

    //On retourne la valeur d'over pour savoir si la partie est finie ou non.
    return over;
}
