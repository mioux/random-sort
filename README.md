# random-sort

Tente de trier un tableau de longueur donnée en choisissant aléatoirement les éléments du tableau pour les trier.

## Compiler

Le makefile est géré à la main. Il nécessite d'avoir clang++ installé pour compiler le programme. La compilation fonctionnant très bien avec gcc, il est possible de remplacer la variable CC par `CC=g++`.

Pour obtenir une version débuggable du fichier, lancer `make debug`.

Il n'y a pas d'installation, étant donné le caractère ridicule du programme.

## Usage

Il suffit de lancer le programme avec le nombre d'éléments que l'on souhaite trier. Par exemple, en lançant `./random-sort 5`, le programme va essayer de trier les nombres de 0 à 4.

Chaque étape intermédiaire est affichée pour information.

Chaque tableau trié est le précédent obtenu.
