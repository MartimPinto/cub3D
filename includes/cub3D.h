/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:51:53 by Axel              #+#    #+#             */
/*   Updated: 2024/04/24 17:42:31 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3D_utils.h"
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/**
 * @brief Return a static instance of the game struct.
 *
 * @return t_game *
 */
t_game	*game(void);

// =============================================================================
//                               INIT_EXIT
// =============================================================================
// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief Initialize the game structure. allocate memory for the data contained 
 * in the file to parse.
 */

void	init_game(void);

/**
 * @brief load the textures init mlx instance and window, set the hook to 
 * handle keypress and keyrelease, init player related data and start the 
 * game loop
 */
void	start_game(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ INIT_PLAYER.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief init data related to player. set the position, direction, camera 
 * plane and move related variables.
 */
void	init_player(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ EXIT.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief exit the game by freeing appropriately data allocated on the 
 * heap. returns the exit_status passed as param.
 *
 * @param exit_status 
 */
void	exit_game(int exit_status);

/**
 * @brief prints the error message and the variable passed as arguments.
 *
 * @param err_msg
 * @param var
 */
void	exit_error(char *err_msg, char *var);

/**
 * @brief quit the game. The function is hooked to the mlx_loop and called upon
 * closing the window.
 */
int		quit_window(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ FREE.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief frees the info relative to the map. map_info stores the strings
 * contained in the file passed as argument when the program is runned.
 */
void	free_map_info(void);

/**
 * @brief free the memory associated with wall textures.
 */
void	free_textures(void);

// =============================================================================
//                                 RENDER
// =============================================================================
// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ FRAME.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief renders on the screen buffer and send it to screen. Minimap, player
 * and 3D scene will be rendered on screen.
 *
 * @return 
 */
int		render_frame(void);

/**
 * @brief shades a single pixel based on the distance at which it stands from
 * the player position. the function uses linear interpolation to calculate 
 * a attenuation coefficient and multiplies each component of the current 
 * color of the pixel by it and returns the updated color value.
 * if wall_dist > RENDER_DIST, the function returns the color black.
 *
 * @param wall_dist 
 * @param color 
 * @return 
 */
int		shader(double wall_dist, int color);

/**
 * @brief performs the same computations as shader function. this time, pixels 
 * are increasingly shaded as we get closer to the horizon line.
 *
 * @param dist 
 * @param color 
 * @return 
 */
int		shader_ceiling(int dist, int color);

/**
 * @brief performs the same computations as shader function. this time, pixels 
 * are increasingly shaded as we get closer to the horizon line.
 *
 * @param dist 
 * @param color 
 * @return 
 */
int		shader_floor(int dist, int color);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ BASIC_RENDERING.C \_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief Combines the RGB color values into a single integer representation.
 *
 * This function takes the individual color values (red, green,
 * blue) as arguments and combines them into a single integer representation.
 * The color values should be in the range of 0 to 255 (1 byte).
 *
 * @param r The red color value.
 * @param g The green color value.
 * @param b The blue color value.
 * @return An integer representation of the combined RGB color values.
 */
int		create_trgb(int t, int r, int g, int b);

/**
 * @brief Write a single colored pixel to the img buffer at position pos.
 *
 * @param pos
 * @param color
 */
void	render_pixel(t_pos	pos, int color);

/**
 * @brief Write a square to the img buffer. the [x,y] position of the square
 * correspond to its upper left corner.
 *
 * @param square
 */
void	render_square(t_square square);

/**
 * @brief Write a line to the img buffer.
 *
 * @param start 
 * @param dir 
 * @param length 
 * @param color 
 */
void	render_line(t_pos start, t_pos dir, int length, int color);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MINIMAP.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief renders minimap on the screen buffer.
 */
void	render_minimap(void);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ TEXTURES.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief make correspondance between pixels of the wall curently beeing 
 * rendered ad the pixels of the texture. initial position int the texture
 * (text->x), current position in the texture (text->pos) and steping value 
 * (text->step) are calculated. the step is proportional to dist 
 * of the wall. the greater the distance is the bigger is the step.
 *
 * @param ray 
 * @param curr_x 
 */
void	render_texture(t_ray *ray, int curr_x);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ RAYCASTING.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief performs the digital differential analyzer algorithm. The algo 
 * consists in casting rays by looping across the width of the screen. The 
 * algorithm increments the curr ray by x_side or y_side depending on the
 * ray direction, effectively adding exactly to its length the missing 
 * distance between its current position and the next grid intersection.
 * Once on an intersection, it checks if a wall was hit. If so, the height
 * of the wall (on screen) that was hit is calculated based on the 
 * distance that separates the player and the wall.
 */
void	raycaster(void);

// =============================================================================
//                                  EVENTS
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ EVENTS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief listen for keypress and moves the player of the camera appropriately
 * depending on which key was pressed.
 *
 * @param keycode 
 * @return 
 */
int		key_press(int keycode);

/**
 * @brief listen for keyrelease and moves the player of the camera appropriately
 * depending on which key was released.
 *
 * @param keycode 
 * @return 
 */
int		key_release(int keycode);

/**
 * @brief check if the new position is a valid one (if it is a walkable tile)
 *
 * @param new_x 
 * @param new_y 
 * @return 
 */
int		validate_move(t_pos next_pos);

/**
 * @brief move the player according to player information.
 *
 * @return 
 */
int		move_player(void);

/**
 * @brief rotate the camera plane an player direction by applying trigonometric
 * transformation.
 *
 * @param direction 
 * @return 
 */
int		rotate_camera(t_rotation direction);

/**
 * @brief listen for mouse movement and rotate the camera and plane accordingly 
 *
 * @param x
 * @param y
 * @return 
 */
int		mouse_handler(int x, int y);

// =============================================================================
//                                   UTILS
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MAP_UTILS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
bool	is_player(char c);
bool	is_floor(char c);
bool	is_wall(char c);
bool	ft_is_digit(char *str);
bool	is_map_row(char *line);
char	*ft_strstr(char *str, char *to_find);
bool	ft_isspace(char c);
char	*trim_elements(char *str, char **chars);
void	cleaner(char *str, char **var);
bool	order_check(void);
void	initialize_chars(char **chars);
bool	check_player(char **map);
void	replace_map_space(void);
int		get_col_size(void);
int		get_row_size(int y);
bool	only_spaces(char *str);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ MATRIX_UTILS.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
size_t	get_matrix_len(char **matrix);
void	free_matrix(char **matrix);
void	matrix_append(char ***matrix_ptr, char *to_append);
void	trim_matrix(char **map);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ DEBUG.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief prints the map highlighting in red the position passed as arg.
 *
 * @param err_pos position at which error occured.
 */
void	print_map(t_pos err_pos);
void	print_player_pos(void);
void	print_text_info(t_text_info *info, t_ray *ray, int curr_x);
void	print_ray_info(t_ray *ray, int x);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ POSITION_UTILS.C \_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief converts the pos on the map to real pos on screen.
 *
 * @param pos 
 * @return 
 */
t_pos	to_screen_pos(t_pos pos);

/**
 * @brief converts the pos on screen to the corresponding one in the map.
 *
 * @param pos	position to convert.
 * @return		converted position.
 */
t_pos	to_map_pos(t_pos pos);

/**
 * @brief reverse a direction vector / returns opposite of a point.
 *
 * @param dir 
 * @return 
 */
t_pos	reverse_dir(t_pos dir);

/**
 * @brief add two positions and return the result.
 *
 * @param p1
 * @param p2
 * @return
 */
t_pos	add_pos(t_pos p1, t_pos p2);

/**
 * @brief Centers a given position on the screen by offsetting it.This function
 * aims to adjust the position to ensure that the center of an object aligns with
 * the specified position.
 *
 * @param pos  The original position to be centered.
 * @param size The size of the object to be centered, used to compute the offset.
 * @return     The centered position.
 */

t_pos	center_position(t_pos pos, int size);

// =============================================================================
//                                  PARSER
// =============================================================================
//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ PARSE_FILE.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief checks if the file extension is a supported extension.
 *
 * @param str 
 * @param ext 
 * @param alt 
 */
void	check_file(char *str, char *ext);

/**
 * @brief parses each elements of the file and stores it appropriately in the 
 * mape_info structure. Ultimately, performs check on the elements of the file 
 * and assess if elements exist or if some elements can not be handle by the 
 * program.
 *
 * @param file 
 */
void	parse_file(char	*file);

//! _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ CHECK_MAP.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief performs check on maps. check if the map is closed by walls, if it has
 * invalid chars, and it has empty lines.
 *
 * @param map 
 */
void	check_map(char	**map);

// _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/ LOAD_TEXTURES.C \_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
/**
 * @brief load the textures into the game structure. textures a trasfered into 
 * 2D int buffer where each element correspond to a colored pixel.
 */
void	load_textures(void);

#endif
