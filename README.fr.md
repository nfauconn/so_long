[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/so_long/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/so_long/blob/master/README.fr.md)

*Langage de programmation C* • *Compréhension et mise en œuvre de mécaniques de jeu* • *Travail avec des graphiques 2D* • *Gestion de fenêtres et de évènements* • *Parsing et validation de carte* • *Gestion de la mémoire* • *Makefile et organisation du projet*

# So Long

Un petit jeu 2D pour apprendre la gestion des fenêtres, le traitement des événements, les couleurs, les textures, etc.

- Outils utilisés : La bibliothèque graphique de l'école : la MiniLibX. Cette bibliothèque a été développée en interne et comprend les outils de base nécessaires pour ouvrir une fenêtre, créer des images et gérer les événements clavier et souris.

| Clé | Valeur |
| --- | --- |
| Nom du programme | `so_long` |
| Langage | C |
| Fichiers à rendre | `Makefile`, `*.h`, `*.c`, `maps`, `textures` |
| Makefile | `NAME`, `all`, `clean`, `fclean`, `re` |
| Arguments | Une carte au format `*.ber` |
| Fonct. externes autorisées | `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`<br>Toutes les fonctions de la bibliothèque de mathématiques (`-lm` option du compilateur, `man man 3 math`)<br>Toutes les fonctions de la MiniLibX<br> |
| Variable globale autorisée | Aucune |

## Utilisation

### Prérequis pour Linux

- MinilibX prend uniquement en charge le type visuel TrueColor (profondeur de 8, 15, 16, 24 ou 32 bits)
- Fichiers d'inclusion X11 (paquet `xorg`)
- L'extension XShm doit être présente (paquet `libxext-dev`)
- Fonctions utilitaires des systèmes BSD - fichiers de développement (paquet `libbsd-dev`)

### Comment exécuter

```shell
git clone git@github.com:nfauconn/so_long.git
cd so_long/Projet
make
```

```shell
./so_long <map.ber>
```

- Le but est de collecter tous les collectibles présents sur la carte puis de s'échapper en choisissant l'itinéraire le plus court possible.
- Utilisez les touches `W`, `A`, `S` et `D` pour déplacer le personnage principal.

Les cartes se trouvent dans `maps/`.
Vous pouvez écrire la vôtre si vous le souhaitez. La carte doit avoir l'extension `.ber`. Voici les règles à suivre :

- La carte doit être construite avec 3 composants : murs, collectibles et espace libre
- La carte peut être composée de ces 5 caractères :
  - `0` pour un espace vide
  - `1` pour un mur
  - `C` pour un collectible
  - `E` pour une sortie de carte
  - `P` pour la position de départ du joueur.

Voici une carte valide simple :
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

- La carte doit contenir 1 sortie, au moins 1 collectible et 1 position de départ pour être valide.
- La carte ne peut pas contenir de caractères en double (sortie/départ).
- La carte doit être rectangulaire.
- La carte doit être fermée/entourée de murs.
- Le personnage doit avoir un chemin valide pour s'échapper.

Un autre exemple de carte `.ber` minimale :

```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```