# so_long
My 5º project at 42SP, i loved to do my first game 2D, and understand how games works under the hood.
In this project, i use a extern tool calls [minilibx](https://github.com/42Paris/minilibx-linux), it is a library with function that can make a game work, feel free to enter the repository this library.
I compile this lib with the project on make, but you need to install somethings:
```shell
sudo apt-get install xorg libxext-dev zlib1g-dev
```
>This project was projecting to run in linux OS, so if happen any strange, maybe be your system.

## How it works?
This project is pretty simple, but you can do any map you want with any sprites. The flow of the project is read a file that you pass to him in moment of executation and the program will read this file and trate the chars reads in this file as sprites, and will print for you on the window, pretty cool huh?!  
But before you pass the map to him, exist some rules for to work:
* First, this map have to be a file .ber and the map format have to be a rectangular;
* The map must have walls on all edges;
* Must have at least one exit and one item;
* Must have one player;

you must was asking how you put these icons in the file, i will explain, each character is a content inside the game:
* P = player;
* E = exit;
* C = item;
* H = enemies;
* 0 = floar;
* 1 = walls;
>this chars must be uppercase.  

This is how the map looks like:
```text
1111111111111
10010000000C1
1000011111001
1P0011E0000H1
1111111111111
```
>popule your map as you wish;    
>**for this map works, can't have a newline in the end of the file.**

Fell free to clone this repository and change the sprites in folder sprites.
But the sprites have to be a file .xpm and must be 50x50;
>searching on google, you can find sites that transform files .png to .xpm. 

## About the project
i use some past projects to help me to create this project, like [get next line](https://github.com/jhonatan229/get_next_line) and some functions of the [libft](https://github.com/jhonatan229/libft_42) that i save on utils folder.

## How to play?
only thing that you need to do, after instal the tools sayed before, is junst clone the repository and run **make** into the tree of the project, this will make for you a file **so_long**, just run this exe with the path of the map (i saved some maps on map folder ), exemple:
```bash
./so_long map/map2.ber
```
:joystick: :joystick: I hope tha you enjoy this game :joystick: :joystick: