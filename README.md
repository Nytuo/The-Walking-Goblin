# The Walking Lutin

Le projet de la S1.01

Le but de ce jeu est de permettre à un lutin de s’échapper d’une grille
avant qu’il ne se fasse manger par les monstres.

## Les données qui permettent d’initialiser la grille sont lues dans un fichier de configuration.

Dans ce fichier de configuration se trouvent les informations suivantes :

La taille de la grille,
Le nombre de monstres,
Pour chacun des monstres :
L’emplacement du monstre sur la grille (ligne puis colonne),
Le sens de déplacement initial du monstre : 1 vers la gauche, 2 vers le haut, 3 vers la droite et 4 vers le bas,
L’emplacement du lutin sur la grille (ligne puis colonne),
L’emplacement de la porte de sortie sur la grille (ligne puis colonne).

À chaque tour de jeu, le lutin bouge en
premier et les monstres bougent ensuite.

## Le lutin :

les déplacements du lutin sont lus dans un fichier qui contient à chaque ligne un nombre compris entre 1 et 4 :

1 : le lutin se déplace vers la gauche si c’est possible,
2 : le lutin se déplace vers le haut si c’est possible,
3 : le lutin se déplace vers la droite si c’est possible,
4 : le lutin se déplace vers le bas si c’est possible.
Si le déplacement du lutin lu dans le fichier n’est pas possible, il est ignoré et le lutin ne bouge pas.

## Les testes:

Pour tester ce projet, la team a développer un programme Python qui teste notre programme et le programme témoin.

## La Team en charge de ce projet titanesque:

|           <a href="http://nytuo.yo.fr" target="_blank">**BEUX Arnaud**</a>            |    <a href="https://github.com/alexandrejbc" target="_blank">**COLIN Alexandre**</a>    |      <a href="https://github.com/fc106656" target="_blank">**FAUX Clement**</a>       |   <a href="https://github.com/MyLifeIsDamba" target="_blank">**VEILLARD Corentin**</a>    |
| :-----------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------: | :---------------------------------------------------------------------------------------: |
| <img src="https://avatars.githubusercontent.com/u/34894524?s=128v=4" align="center"/> |  <img src="https://avatars.githubusercontent.com/u/63028565?s=128v=4" align="center"/>  | <img src="https://avatars.githubusercontent.com/u/92145923?s=128v=4" align="center"/> |   <img src="https://avatars.githubusercontent.com/u/92926995?s=128v=4" align="center"/>   |
|       <a href="http://github.com/Nytuo" target="_blank">`github.com/Nytuo`</a>        | <a href="https://github.com/alexandrejbc" target="_blank">`github.com/alexandrejbc`</a> |    <a href="https://github.com/fc106656" target="_blank">`github.com/fc106656`</a>    | <a href="https://github.com/MyLifeIsDamba" target="_blank">`github.com/MyLifeIsDamba`</a> |
