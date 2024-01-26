[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/so_long/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/so_long/blob/master/README.fr.md)

# Project: So Long

## 🏁 Goal 🏁

Programming a small 2D game to learn window management, event handling, colors, textures, and so forth.

Tools used : the school graphical library: the MiniLibX. This library was developed internally and includes basic necessary tools to open a window, create images, and deal with keyboard and mouse events.

The other goals are similar to every other goal for this first year: being rigorous, level up in C programming, use basic algorithms, do some information research, and so forth.

## 🚀 Usage 🚀

### Requirements for Linux

- MinilibX only support TrueColor visual type (8,15,16,24 or 32 bits depth)
- `gcc`
- `make`
- X11 include files (package `xorg`)
- XShm extension must be present (package `libxext-dev`)
- Utility functions from BSD systems - development files (package `libbsd-dev`)

### How to run

```shell
> make
> ./so_long <map>
```
Maps are located in `maps/`.

## 💡 Learning 💡

### 🌐 Language: C 🌐

### 🔧 Development Practices and Tools 🔧

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

## 📋 Subject 📋

Solo project

### Common Instructions

- Your project must be written in C.
- Your project must be written in accordance with the Norm. 
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non-functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- You must submit a Makefile which will compile your source files to the required output with the flags `-Wall -Wextra` and `-Werror`, and your Makefile must not relink.
- Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- You must copy your `libft` sources and its associated Makefile in a `libft` folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile then compile the project.

### Mandatory part

#### 1. Game

- Program name: `so_long`
- Turn in files: `Makefile`, `*.h`, `*.c`, `maps`, `textures`
- Makefile: `NAME`, `all`, `clean`, `fclean`, `re`
- Arguments: A map in format `*.ber`
- External functs. allowed: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
  - All functions of the math library (`-lm` compiler option, `man man 3 math`)
  - All functions of the MiniLibX
  - `ft_printf` and any equivalent YOU coded
- Libft authorized: Yes
- Description: You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. Instead of a dolphin, fish, and the Earth, you can use any character, any collectible, and any place you want.

Your project must comply with the following rules:

- You must use the MiniLibX. Either the version available on the school machines or installing it using its sources.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Your program has to take as parameter a map description file ending with the `.ber` extension.
- The player’s goal is to collect every collectible present on the map then escape choosing the shortest possible route.
- The `W`, `A`, `S`, and `D` keys must be used to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.
- You have to use a 2D view (top-down or profile).
- The game doesn’t have to be real time.
- Although the given examples show a dolphin theme, you can create the world you want. If you prefer, you can use `ZQSD` or the arrow keys on your keyboard to move your main character.

#### 2. Graphic management

- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing `ESC` must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory.

#### 3. Map

- The map has to be constructed with 3 components: walls, collectibles, and free space.
- The map can be composed of only these 5 characters:
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
- If the map contains duplicate characters (exit/start), you should display an error message.
- The map must be rectangular.
- The map must be closed/surrounded by walls. If it’s not, the program must return an error.
- You have to check if there’s a valid path in the map.
- You must be able to parse any kind of map as long as it respects the above rules.
- Another example of a minimal `.ber` map:

```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

- If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way and return "Error\n" followed by an explicit error message of your choice.
