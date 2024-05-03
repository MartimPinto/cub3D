/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:19:45 by Axel              #+#    #+#             */
/*   Updated: 2024/05/03 14:12:53 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_UTILS_H
# define CUB3D_UTILS_H

# include <stdbool.h>

# define SCREEN_W		800
# define SCREEN_H		800
# define MAP_POS		50
# define TILE_SIZE		10
# define PLAYER_SIZE	5
# define TEXT_SIZE		64
# define RENDER_DIST	10
# define MOVESPEED		0.110
# define ROTSPEED		0.010
# define PI				3.14159265359
# define MOUSE_WRAP 	25

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define CYAN	0x0000FFFF
# define BLACK	0x00000000

# define ANSIRED	"\033[38;5;196m"
# define RESET		"\033[0m"

# define USAGE			"Usage: ./cub3D <file.cub>\n"
# define ALLOC_ERROR	"Bad allocation"
# define INVALID_EXT	"Invalid extension"
# define INVALID_COLOR	"Invalid color code"
# define FILE_NT_FOUND	"File not found"
# define MISS_TEXTURE	"Missing texture"
# define DUP_TEXTURE	"Duplicate texture coordinates"

# define INVALID_MAP	"Invalid map"
# define INVALID_WALLS	"Not surrounded by walls"
# define EMPTY_LINE		"Map contains empty line"
# define INVALID_CHAR	"Map contains invalid char"
# define MAP_FIRST		"Map at the beginning of file"
# define INVALID_PLAYER	"Map contains incorrect number of players"

# ifdef LINUX
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_DOWN 65364
#  define ESC 65307
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_W 119
#  define KEY_ENTER 65293

# else
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_Q	12
#  define KEY_ENTER 36
#  define ESC 53
#  define DESTROY_DISPLAY 

# endif

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'

typedef enum e_keys
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_DESTROY = 17,
	ON_MOTIONOTIFY = 6, //to use on Linux
	//ON_MOUSEMOVE = 6, //to use on MAC OS
}				t_keys;

typedef enum e_mask
{
	KEYPRESS_MASK = (1L << 0),
	KEYRELEASE_MASK = (1L << 1),
	DESTROY_MASK = (1L << 17),
	POINTERMOTION_MASK = (1L << 6),
}				t_mask;

typedef enum e_rotation
{
	RIGHT,
	LEFT,
}	t_rotation;

typedef enum e_text_index
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_text_index;

typedef struct s_point
{
	double			x;
	double			y;
}				t_pos;

typedef struct s_square
{
	t_pos		pos;
	int			width;
	int			color;
}				t_square;

typedef struct s_circle
{
	t_pos	pos;
	int		radius;
	int		color;
}	t_circle;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bbp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_map_info
{
	char	**arr;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	bool	render_map;
}			t_map_info;

typedef struct s_text_info
{
	int		c;
	int		f;
	int		size;
	int		index;
	double	step;
	double	pos;
	int		x;
	int		y;
}	t_text_info;

typedef struct s_player
{
	t_pos		pos;
	t_pos		dir;
	t_pos		camera;
	int			has_moved;
	bool		is_moving_up;
	bool		is_moving_down;
	bool		is_moving_left;
	bool		is_moving_right;
	int			move_x;
	int			move_y;
	int			rotate;
}				t_player;

typedef struct s_ray
{
	t_pos		pos;
	t_pos		dir;
	t_pos		step;
	t_pos		delta_dist;
	t_pos		side_dist;
	int			side;
	double		wall_dist;
	double		wall_x;
	int			line_height;
	int			start;
	int			end;
}	t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map_info	*map_info;
	char		**map;
	t_text_info	*text_info;
	int			**textures;
	t_img		screen_buff;
	t_player	player;
	bool		error;
}				t_game;

#endif
