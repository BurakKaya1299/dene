/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:32:09 by burkaya           #+#    #+#             */
/*   Updated: 2023/12/12 12:28:19 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv, t_game *game)
{
	int	len_par;

	game->map_alloc = false;
	if (argc > 2)
		ft_error("Wrong usage: ./so_long [Map Path]", game);
	if (argc < 2)
		ft_error("Wrong usage: ./so_long [Map Path]", game);
	len_par = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len_par - 4], ".ber", 4))
		ft_error("Map has to end with .ber", game);
}

static void	ft_check_lines(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n' || map[ft_strlen(map) - 1] == '\n')
	{
		free(map);
		ft_error("Map should not have empty line.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error("Map should not have empty line.", game);
		}
		i++;
	}
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*tmp_map;
	char	*tmp_line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("File could not open.", game);
	tmp_map = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		tmp_line = get_next_line(fd);
		if (!tmp_line)
			break ;
		tmp_map = ft_strjoin(tmp_map, tmp_line);
		free(tmp_line);
		game->map.rows++;
	}
	close(fd);
	ft_check_lines(tmp_map, game);
	game->map.full = ft_split(tmp_map, '\n');
	game->map.check = ft_split(tmp_map, '\n');
	game->map_alloc = true;
	free(tmp_map);
}
