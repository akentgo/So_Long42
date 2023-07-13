/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:39:46 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/08 08:08:35 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	check_closed_map(t_game *game)
{
	int	i;
	int	fin;

	fin = 0;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || \
			game->map[i][game->map_width - 2] != '1')
			fin++;
		i++;
	}
	i = 0;
	while (i < game->map_width - 2)
	{
		if (game->map[0][i] != '1' || \
			game->map[game->map_height - 1][i] != '1')
				fin++;
		i++;
	}
	if (fin > 0)
		return (0);
	return (1);
}

int	check_symbols(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_height)
	{
		while (i < game->map_width - 1)
		{
			if (game->map[j][i] != '1' && game->map[j][i] != 'C' && \
				game->map[j][i] != '0' && \
				game->map[j][i] != 'E' && game->map[j][i] != 'P' && \
				game->map[j][i])
				return (0);
			if (game->map[j][i] == 'C')
				game->n_coins++;
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_min_chars(t_game *game)
{
	if (game->player == 0)
	{
		ft_printf("Error\nNo players on map");
		return (0);
	}
	if (game->n_coins == 0)
	{
		ft_printf("Error\nNo coins on map");
		return (0);
	}
	if (game->doors == 0)
	{
		ft_printf("Error\nNo exits on map");
		return (0);
	}
	return (1);
}

int	check_exits(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width - 1)
		{
			if (game->map[j][i] == 'E')
				game->doors++;
			if (game->doors > 1)
			{
				ft_printf("Error\nMore than one exit");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	check_players(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width - 1)
		{
			if (game->map[j][i] == 'P')
				game->player++;
			if (game->player > 1)
			{
				ft_printf("Error\nMore than one player");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}
