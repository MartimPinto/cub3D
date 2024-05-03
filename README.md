# Cub3D
>Perspective, Raycasting and Wolfenstein3D

</p>
<p align="center">
	<a href="#about">About</a> •
	<a href="#usage">Usage</a> •
   <a href="#implementation">Implementation</a> •
	<a href="#norme">Norme</a>
</p>


## About
Cub3D is an implementation of raycasting to render a 2D map in 3D. Raycasting is a rendering technique used to create a 3D perspective in a 2D map.

## Usage
`git clone` this project `cd` into it. If your OS is macOS, simply `make`. if your running on linux, `make re OS=linux`.
the program is executed as so:

```shell
./Cub3D <map.cub>
```

You will find maps and textures in the assets directory. feel free to customize maps or add you own textures. The program will open a window and display the controls on your terminal. the player is moved with the W,A,S,D key and point the camera is rotated with the left and right arrows as well as with mouse movements in the bonus part. The bonus also adds the minimap feature which can be accessed by pressing enter.

<img src="demo.gif" width="100%"/>

## Implementation
The raycasting algorithm in Cub3D can be broken down into several key steps:

1. Ray Initialization:
   - The `init_ray()` function initializes a ray with the appropriate starting position and direction based on the player's position and camera settings.

2. Side Distances Calculation:
   - The `set_side_dist()` function calculates the side distances to determine the next intersection with a grid boundary in the map.

3. Digital Differential Analyzer (DDA):
   - The `perform_dda()` function implements the DDA algorithm to trace the path of the ray through the map, checking for intersections with walls.

4. Line Height Calculation:
   - The `get_line_height()` function calculates the height of the wall that the ray hits, which determines how much of the wall will be displayed on the screen.

5. Rendering:
   - The `raycaster()` function iterates through each column of the screen, casting rays and rendering the corresponding wall segments using the calculated line heights.

This process is repeated for each frame to continuously update the displayed scene as the player moves through the map. 

## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function


