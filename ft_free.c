/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:38:22 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/12 12:37:42 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coins.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
}

void	ft_free_all_memory(t_game *game)
{
	ft_destroy_image(game);
	ft_free_game(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	ft_free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}

void	ft_free_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.check[i++]);
	free(game->map.check);
}
