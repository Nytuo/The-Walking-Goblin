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

//Modifie le déplacement du monstre
void modifMonstreDepl(monstre *tabMonstres, int value) {
    tabMonstres->depl = value;
}

//Access au déplacement du monstre
int accessMonstreDepl(monstre Monstres){
    return Monstres.depl;
}

//Access à la colonne du monstre
int* accessMonstreC(monstre *Monstres){
    return &Monstres->col;
}

//Access à la ligne du monstre
int* accessMonstreL(monstre *Monstres){
    return &Monstres->ligne;
}

