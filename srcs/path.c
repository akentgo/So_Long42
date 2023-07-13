/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:08:43 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/08 08:13:00 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

static void	free_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

char	**map_copy(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)(ft_calloc(sizeof(char *), (game->map_height + 1)));
	while (i < game->map_height)
	{
		copy[i] = ft_substr(game->map[i], 0, ft_strlen(game->map[i]));
		i++;
	}
	return (copy);
}

char	**flood_fill(char **c, int y, int x)
{
	if (c[y][x + 1] == '0' || c[y][x + 1] == 'E' || c[y][x + 1] == 'C')
	{
		c[y][x + 1] = 'f';
		flood_fill(c, y, x + 1);
	}
	if (c[y - 1][x] == '0' || c[y - 1][x] == 'E' || c[y - 1][x] == 'C')
	{
		c[y - 1][x] = 'f';
		flood_fill(c, y - 1, x);
	}
	if (c[y][x - 1] == '0' || c[y][x - 1] == 'E' || c[y][x - 1] == 'C')
	{
		c[y][x - 1] = 'f';
		flood_fill(c, y, x - 1);
	}
	if (c[y + 1][x] == '0' || c[y + 1][x] == 'E' || c[y + 1][x] == 'C')
	{
		c[y + 1][x] = 'f';
		flood_fill(c, y + 1, x);
	}
	return (c);
}

int	check_valid_path(t_game *game)
{
	char	**copy;
	int		y;
	int		x;
	int		coins;

	coins = 0;
	copy = map_copy(game);
	copy = flood_fill(copy, game->y + 1, game->x + 1);
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width - 1)
		{
			if (game->map[y][x] == 'E' && copy[y][x] != 'f')
				return (0);
			else if (game->map[y][x] == 'C' && copy[y][x] == 'f')
				coins++;
		}
	}
	free_copy(copy);
	if (coins != game->n_coins)
		return (0);
	return (1);
}

int	check_file_name(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_filename[i] != '\0')
		i++;
	if (game->map_filename[i - 1] != 'r' || \
	game->map_filename[i - 2] != 'e' || game->map_filename[i - 3] != 'b' || \
	game->map_filename[i - 4] != '.')
		return (0);
	return (1);
}
