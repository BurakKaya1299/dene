/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:30:48 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/12 12:52:46 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	ft_check_args(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_vars(game);
	ft_check_map(game);
	if (!ft_is_reachable(game))
		ft_error("Player can not reach to exit.", game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_render_map(game);
	mlx_hook(game->win_ptr, 17, 1, ft_close_game, game);
	mlx_key_hook(game->win_ptr, ft_handle_input, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_memory(game);
}
