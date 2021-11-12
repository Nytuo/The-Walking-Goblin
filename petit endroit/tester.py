import subprocess
import os
import shutil


def get_console(numero,exe):
    p = subprocess.run([f".\{exe}.exe"],capture_output=True,text=True)
    p=p.stdout
    
    with open(f'grille_{numero}.txt',"w") as f:
        f.write(p)
    return p

    
def found_files(dossier,dossier2):
    listfiles,listfiles2 = os.listdir(dossier),os.listdir(dossier2)
    
    
    for i in range(len(listfiles)):
        shutil.copyfile(os.getcwd()+"\\"+dossier+"\\"+listfiles[i],os.getcwd()+"\\grille1.txt")
        shutil.copyfile(os.getcwd()+"\\"+dossier2+"\\"+listfiles2[i],os.getcwd()+"\\deplacementsLutin_grille1.txt")
        
        prof = get_console("prof","SAe1_01")
        eleve = get_console("eleve","SAe1_01")
        if prof == eleve:
            print("OK ",i)
        else:
            print("Failed at :",i)
            return

found_files(".\\_grilles", ".\\_deplacement")