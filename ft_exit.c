/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:36:53 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/08 09:56:48 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_win(t_game *game)
{
	ft_printf("Movements: %d", ++game->movements);
	ft_free_all_memory(game);
	exit(1);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Movements: %d", game->movements);
	ft_free_all_memory(game);
	exit(0);
}

int	ft_error(char *msg, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_game(game);
	free(game);
	ft_printf("%s\n", msg);
	exit(0);
}
