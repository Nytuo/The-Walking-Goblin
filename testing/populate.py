# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 16:32:43 2021

@author: nono5
"""
import random

def a():
    listCooMonstres = [[random.randint(0, tailleGrille-1),random.randint(0, tailleGrille-1),random.randint(1,4)] for x in range(nbMonstres)]
    done = []
    for j in range(len(listCooMonstres)):
        if listCooMonstres[j] not in done:
            done.append(listCooMonstres[j])
    if len(done)!= nbMonstres:
        return a()
    return done

numberOfTurn = 20
print("populatting")

for y in range(numberOfTurn):
    tailleGrille = random.randint(3, 10)
    nbMonstres = random.randint(1,10)
    
    listCooMonstres = a()
    Lutin = [random.randint(0,tailleGrille-1),random.randint(0,tailleGrille-1)]
    Porte = [random.randint(0,tailleGrille-1),random.randint(0,tailleGrille-1)]
    with open('_grilles/grille'+str(y)+'.txt', "w") as f:
        txt = ""
        txt+=(str(tailleGrille)+"\n")
        txt+=(str(nbMonstres)+"\n")
        for o in listCooMonstres:
            for k in o:
                txt+=(str(k)+" ")
            txt+=("\n")
        for p in Lutin:
            txt+=(str(p)+" ")
            
        txt+=("\n")
        for i in Porte:    
            txt+=(str(i)+" ")
        txtlist = txt.split("\n")
        for line in txtlist:
            line.strip()
            f.write(line+"\n")
                

for y in range(numberOfTurn):
    maxDepLutin  = random.randint(2, 10)
    listDepLutin = [random.randint(1, 4) for x in range(maxDepLutin)]
    with open('_deplacement/deplacementsLutin_grille'+str(y)+'.txt', "w") as f:
        for i in listDepLutin:    
            f.write(str(i)+"\n")