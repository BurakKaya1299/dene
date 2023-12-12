/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:11:01 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/12 12:51:12 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_fill_flood(t_game *game, int y, int x)
{
	if (game->map.check[y][x] != '1' && game->map.check[y][x] != 'F'
	&& game->map.check[y][x] != PLAYER)
	{
		game->map.check[y][x] = 'F';
		ft_fill_flood(game, y, x - 1);
		ft_fill_flood(game, y, x + 1);
		ft_fill_flood(game, y - 1, x);
		ft_fill_flood(game, y + 1, x);
	}
	if (game->map.check[y][x] == PLAYER)
	{
		game->map.check[y][x] = 'F';
		return (1);
	}
	return (0);
}

int	ft_is_reachable(t_game *game)
{
	int	y;
	int	x;
	int	exit_x;
	int	exit_y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == MAP_EXIT)
			{
				exit_x = x;
				exit_y = y;
			}
			x++;
		}
		y++;
	}
	ft_fill_flood(game, exit_y, exit_x);
	if (game->map.check[game->map.player.y][game->map.player.x] == 'F')
		return (ft_free_check(game), 1);
	return (ft_free_check(game), 0);
}

void	ft_count_letters(t_game *game, int y, int x)
{
	if (!ft_strchr("01CEP", game->map.full[y][x]))
		ft_error("Wrong map items only accept 01CEP.", game);
	else if (game->map.full[y][x] == PLAYER)
	{
		game->map.players++;
		game->map.player.x = x;
		game->map.player.y = y;
	}
	else if (game->map.full[y][x] == COINS)
		game->map.coins++;
	else if (game->map.full[y][x] == MAP_EXIT)
	{
		game->map.exit++;
		game->map.exit_place.x = x;
		game->map.exit_place.y = y;
	}
}
