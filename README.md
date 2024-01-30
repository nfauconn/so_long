[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/so_long/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/so_long/blob/master/README.fr.md)

# So Long

A small 2D game to learn window management, event handling, colors, textures, and so forth.

- Tools used: The school graphical library: the MiniLibX. This library was developed internally and includes basic necessary tools to open a window, create images, and deal with keyboard and mouse events.

## Usage

### Requirements for Linux

- MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
- X11 include files (package `xorg`)
- XShm extension must be present (package `libxext-dev`)
- Utility functions from BSD systems - development files (package `libbsd-dev`)

### How to run

```shell
git clone git@github.com:nfauconn/so_long.git
cd so_long/Project
make
```

```shell
./so_long <map.ber>
```

Maps are located in `maps/`.
You can write your own if you want. The map must have the `.ber` extension. Here are the rules to follow:

- The map has to be constructed with 3 components: walls, collectibles, and free space
- The map can be composed of these 5 characters:
  - `0` for an empty space
  - `1` for a wall
  - `C` for a collectible
  - `E` for a map exit
  - `P` for the player’s starting position.

Here is a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- If the map can't contain duplicate characters (exit/start).
- The map must be rectangular.
- The map must be closed/surrounded by walls. 
- The character must have a valid path to escape.

Another example of a minimal `.ber` map:

```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Gameplay
- The goal is to collect every collectible present on the map then escape choosing the shortest possible route.
- Use the `W`, `A`, `S`, and `D` keys to move the main character.

## Description


| Program name | `so_long` |
| --- | --- |
| Language | C |
| Turn in files | `Makefile`, `*.h`, `*.c`, `maps`, `textures` |
| Makefile | `NAME`, `all`, `clean`, `fclean`, `re` |
| Arguments | A map in format `*.ber` |
| External functs. allowed | `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`<br>All functions of the math library (`-lm` compiler option, `man man 3 math`)<br>All functions of the MiniLibX<br> |


## Skills

1. **Window Management and Event Handling:**
   - Create and manage windows using the MiniLibX library
   - Rendering graphics inside a window
   - Handling events like keyboard inputs and window closing

2. **Working with 2D Graphics:**
   - Drawing, managing textures

3. **Understanding and Implementing Game Mechanics:**
   - Player movement, collision detection, game objectives (collecting items and reaching the exit)

4. **Map Parsing and Validation:**
   - Reading and parsing map files, ensuring they meet specific criteria (rectangular shape, enclosed by walls, contains necessary elements)
   - Error handling for map configuration issues, ensuring the program exits cleanly with an informative error message

5. **Memory Management:**
   - Managing memory by properly allocating and freeing space, ensuring no memory leaks occurred
   - Importance of robustness in software design, especially in handling unexpected situations like segmentation faults or bus errors

6. **Makefile and Project Organization:**
   - Automate the compilation process, managing dependencies and compilation flags effectively
   - Understood the importance of organizing code into separate files and folders for clarity and maintainability

7. **Peer-Evaluation and Version Control:**
   - Submitting my work to a Git repository
   - Preparing for peer-evaluation by ensuring my code is readable, well-documented, and adheres to the project's coding standards
