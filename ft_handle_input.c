/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:13:21 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/12 10:33:58 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_move(t_game *game, int new_y, int new_x, int p_sprite)
{
	int	last_y;
	int	last_x;

	game->player_sprite = p_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.coins == 0)
		ft_win(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
	|| (game->map.full[new_y][new_x] == COINS)
	|| game->map.full[new_y][new_x] == MAP_EXIT)
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.full[new_y][new_x] = PLAYER;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->movements++;
		ft_printf("movement: %d\n", game->movements);
		ft_render_map(game);
	}
}

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	else if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	else if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	else if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	else if (keysym == KEY_ESC)
		ft_close_game(game);
	return (0);
}
