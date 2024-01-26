[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/so_long/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/so_long/blob/master/README.fr.md)

# Projet : So Long

## 🏁 Objectif 🏁

Programmer un petit jeu en 2D pour apprendre la gestion des fenêtres, la gestion des événements, les couleurs, les textures, etc.

Outils utilisés : la bibliothèque graphique de l'école : la MiniLibX. Cette bibliothèque a été développée en interne et inclut les outils de base nécessaires pour ouvrir une fenêtre, créer des images et gérer les événements du clavier et de la souris.

Les autres objectifs sont similaires à tous les autres objectifs de cette première année : être rigoureux, progresser en programmation en C, utiliser des algorithmes de base, faire des recherches d'informations, etc.

## 🚀 Utilisation 🚀

### Prérequis pour Linux

- MinilibX supporte uniquement le type visuel TrueColor (profondeur de 8, 15, 16, 24 ou 32 bits)
- `gcc`
- `make`
- Fichiers headers X11 (paquet `xorg`)
- L'extension XShm doit être présente (paquet `libxext-dev`)
- Fonctions utilitaires des systèmes BSD - fichiers de développement (paquet `libbsd-dev`)

### Comment exécuter

```
> make
> ./so_long <carte>
```
Les cartes sont situées dans `maps/`


## 💡 Apprentissage 💡

1. **Gestion des fenêtres et des événements :**
   - Créer et gérer des fenêtres en utilisant la bibliothèque MiniLibX
   - Rendre des graphiques dans une fenêtre
   - Gérer les événements tels que les entrées clavier et la fermeture de fenêtre

2. **Travail avec la 2D graphique :**
   - Dessiner, gérer les textures

3. **Compréhension et mise en œuvre de la mécanique du jeu :**
   - Mouvement du joueur, détection des collisions, objectifs du jeu (collecter des objets et atteindre la sortie)

4. **Analyse et validation des cartes :**
   - Lire et analyser les fichiers de cartes, s'assurer qu'ils répondent à des critères spécifiques (forme rectangulaire, entourés de murs, contenant les éléments nécessaires)
   - Gestion des erreurs pour les problèmes de configuration des cartes, s'assurer que le programme se ferme proprement avec un message d'erreur informatif

5. **Gestion de la mémoire :**
   - Gérer la mémoire en allouant et libérant correctement l'espace, s'assurer qu'il n'y a pas de fuites de mémoire
   - Importance de la robustesse dans la conception logicielle, en particulier dans la gestion des situations imprévues comme les segfault ou les bus error

6. **Makefile et organisation du projet :**
   - Automatiser le processus de compilation, gérer efficacement les dépendances et les flags de compilation
   - Comprendre l'importance d'organiser le code en fichiers et dossiers séparés pour la clarté et la maintenabilité

7. **Évaluation par les pairs et contrôle de version :**
   - Soumettre mon travail sur un repo Git
   - Me préparer pour l'évaluation par les pairs en m'assurant que mon code est lisible, bien documenté et respecte les normes du projet

## 📋 Sujet 📋

Projet individuel.

### Instructions communes

- Votre projet doit être écrit en C.
- Votre projet doit être rédigé conformément à la Norme.
- Vos fonctions ne doivent pas se terminer de manière inattendue (segfault, bus error, double free, etc.) en dehors des comportements indéfinis. Si cela se produit, votre projet sera considéré comme non fonctionnel et recevra un 0 lors de l'évaluation.
- Tout espace mémoire alloué sur le tas doit être correctement libéré lorsque cela est nécessaire. Aucune fuite ne sera tolérée.
- Vous devez soumettre un Makefile qui compilera vos fichiers source en un binaire avec les drapeaux `-Wall -Wextra` et `-Werror`, et votre Makefile ne doit pas relink.
- Votre Makefile doit contenir au moins les règles `$(NAME)`, `all`, `clean`, `fclean` et `re`.
- Vous devez copier vos sources de `libft` et son Makefile associé dans un dossier `libft`. Le Makefile de votre projet doit compiler la bibliothèque en utilisant son Makefile, puis compiler le projet.

### Partie obligatoire

#### 1. Jeu

- Nom du programme : `so_long`
- Fichiers à rendre : `Makefile`, `*.h`, `*.c`, `maps`, `textures`
- Makefile : `NAME`, `all`, `clean`, `fclean`, `re`
- Arguments : Une carte au format `*.ber`
- Fonctions externes autorisées : `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
  - Toutes les fonctions de la bibliothèque mathématique (`-lm` option du compilateur, `man man 3 math`)
  - Toutes les fonctions de la MiniLibX
  - `ft_printf` et tout équivalent que VOUS avez codé
- Libft autorisé : Oui
- Description : Vous devez créer un jeu 2D basique dans lequel un dauphin s'échappe de la Terre après avoir mangé des poissons. Au lieu d'un dauphin, de poissons et de la Terre, vous pouvez utiliser n'importe quel personnage, n'importe quel collectible et n'importe quel lieu que vous voulez.

Votre projet doit respecter les règles suivantes :

- Vous devez utiliser la MiniLibX. Soit la version disponible sur les machines de l'école, soit en l'installant à partir de ses sources.
- Vous devez rendre un Makefile qui compilera vos fichiers source. Il ne doit pas relink.
- Votre programme doit prendre en paramètre un fichier de description de carte se terminant par l'extension `.ber`.
- L'objectif du joueur est de collecter chaque collectible présent sur la carte puis de s'échapper en choisissant l'itinéraire le plus court possible.
- Les touches `W`, `A`, `S` et `D` doivent être utilisées pour déplacer le personnage principal.
- Le joueur doit être capable de se déplacer dans ces 4 directions : haut, bas, gauche, droite.
- Le joueur ne doit pas pouvoir entrer dans les murs.
- À chaque déplacement, le nombre actuel de mouvements doit être affiché dans le shell.
- Vous devez utiliser une vue 2D (vue de dessus ou de profil).
- Le jeu n'a pas besoin d'être en temps réel.

#### 2. Gestion graphique

- Votre programme doit afficher l'image dans une fenêtre.
- La gestion de votre fenêtre doit rester fluide (changement vers une autre fenêtre, minimisation, etc.).
- Appuyer sur `ESC` doit fermer la fenêtre et quitter le programme de manière propre.
- Cliquer sur la croix du cadre de la fenêtre doit fermer la fenêtre et quitter le programme de manière propre.
- L'utilisation des images de la MiniLibX est obligatoire.

#### 3. Carte

- La carte doit être construite avec 3 composants : les murs, les collectibles et l'espace libre.
- La carte ne peut être composée que de ces 5 caractères :
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
- Si la carte contient des caractères en double (sortie/départ), vous devez afficher un message d'erreur.
- La carte doit être rectangulaire.
- La carte doit être fermée/entourée de murs. Si ce n'est pas le cas, le programme doit retourner une erreur.
- Vous devez vérifier s'il y a un chemin valide dans la carte.
- Vous devez être capable d'analyser tout type de carte tant qu'elle respecte les règles ci-dessus.
- Un autre exemple de carte `.ber` minimale :

```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

- Si une mauvaise configuration de tout type est rencontrée dans le fichier, le programme doit se fermer proprement et retourner "Error\n" suivi d'un message d'erreur explicite de votre choix.