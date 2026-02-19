# so_long

A 2D graphical game project developed as part of the 42 curriculum, using MiniLibX.

The player must collect all items on the map and then reach the exit.  
Each move is counted and displayed in the terminal.

## Controls (keyboard QWERTY)
Move the player: [W] [A] [S] [D]  
or using arrow keys: Up, Down, Left, Right  

Quit the game: ESC or window close button

## Game Objective
The player must collect all collectibles (pickaxes) and break the door before being able to exit.

## Map Requirements
A valid map must:
- Be closed/surrounded by walls
- Contain exactly one player
- Contain exactly one exit
- Contain at least one collectible

## Compilation
```zsh
make
```
## Run the game
./so_long map_mini_valid.ber

## Cleanup After Compilation
```zsh
make clean
make fclean
make re
```
## Cleanup After Compilation

### Project Description
1. Map reading and validation
2. Path validation (flood fill)
3. MLX initialization
4. Texture loading
5. Dynamic rendering
6. Keyboard handling
7. Game execution
8. Proper program shutdown
9. Memory cleanup

### Project Structure
1. src/            → game logic
2. includes/       → headers
3. sprite/         → .xpm images
4. map/            → .ber maps
5. libft/          → custom functions
6. minilibx-linux/ → graphics library

## Notes
The libft and minilibx-linux libraries are automatically built and linked during compilation.
No manual installation or inclusion is required.