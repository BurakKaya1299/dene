/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:28:49 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/12 12:36:25 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define IMG_HEIGHT 32
# define IMG_WIDTH 32

# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define PLAYER 'P'
# define MAP_EXIT 'E'

# define FRONT 1
# define LEFT 2
# define RIGHT 3
# define BACK 4

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_UP  			126
# define KEY_LEFT  			123
# define KEY_RIGHT 			124
# define KEY_DOWN  			125

# define KEY_Q				17
# define KEY_ESC  			53

# define WALL_XPM			"assets/sprites/wall.xpm"
# define FLOOR_XPM			"assets/sprites/floor.xpm"
# define COINS_XPM			"assets/sprites/coin-bag.xpm"
# define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
# define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
# define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
# define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
# define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	char		**check;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
	t_positon	exit_place;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;
void	ft_check_args(int argc, char **argv, t_game *game);
int		ft_error(char *msg, t_game *game);
void	ft_init_vars(t_game *game);
void	ft_check_map(t_game *game);
void	ft_free_game(t_game *game);
void	ft_init_map(t_game *game, char *argv);
int		ft_render_map(t_game *game);
void	ft_free_all_memory(t_game *game);
void	ft_init_sprites(t_game *game);
int		ft_handle_input(int keysym, t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_render_sprite(t_game *game, t_image sprite, int line, int column);
int		ft_win(t_game *game);
int		ft_close_game(t_game *game);
int		ft_is_reachable(t_game *game);
void	ft_count_letters(t_game *game, int y, int x);
void	ft_free_check(t_game *game);

#endif