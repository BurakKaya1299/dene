/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:52:05 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/08 13:59:12 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error("There should be wall int the first row.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_error("There should be wall int the last row.", game);
		i++;
	}
}

static void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error("There should be wall in the first column.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error("There should be wall in the last column.", game);
		i++;
	}
}

void	ft_check_letters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_count_letters(game, y, x);
			x++;
		}
		y++;
	}
}

static void	ft_check_letters_amount(t_game *game)
{
	if (game->map.coins == 0)
		ft_error("At least 1 coin shoul be.", game);
	else if (game->map.exit != 1)
		ft_error("Wrong amount of exit should be one.", game);
	else if (game->map.players != 1)
		ft_error("Wrong amount of players. should be one.", game);
}

void	ft_check_map(t_game *game)
{
	ft_check_rows(game);
	ft_check_columns(game);
	ft_check_letters(game);
	ft_check_letters_amount(game);
}
