/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:02:07 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/08 14:12:05 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_movements(t_game *game)
{
	char	*moves;
	char	*phrase;
	char	*title;

	title = ft_strdup("Movements: ");
	moves = ft_itoa(game->movements);
	phrase = ft_strjoin(title, moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 40, 20, 99999, phrase);
	free(moves);
	free(phrase);
}

static void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite(game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		ft_render_sprite(game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_render_sprite(game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		ft_render_sprite(game, game->player_back, y, x);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.xpm_ptr, \
	column * sprite.x, line * sprite.y);
}

static void	ft_identify_sprite(t_game *game, int y, int x)
{
	if (x == game->map.exit_place.x && y == game->map.exit_place.y)
	{
		game->map.full[y][x] = MAP_EXIT;
		if (game->map.coins == 0)
			ft_render_sprite(game, game->open_exit, y, x);
		else
			ft_render_sprite(game, game->exit_closed, y, x);
	}
	else if (game->map.full[y][x] == WALL)
		ft_render_sprite(game, game->wall, y, x);
	else if (game->map.full[y][x] == FLOOR)
		ft_render_sprite(game, game->floor, y, x);
	else if (game->map.full[y][x] == COINS)
		ft_render_sprite(game, game->coins, y, x);
	else if (game->map.full[y][x] == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite(game, game->open_exit, y, x);
		else
			ft_render_sprite(game, game->exit_closed, y, x);
	}
	else if (game->map.full[y][x] == PLAYER)
		ft_render_player(game, y, x);
}

int	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}
