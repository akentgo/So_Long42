/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:35:35 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/03 17:50:53 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	map_sizes(t_game *game)
{
	char	*str;
	int		fd;

	fd = open(game->map_filename, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
	{
		ft_printf("Error\nEmpty map or read error");
		exit(EXIT_SUCCESS);
	}
	while (str[game->map_width] != '\0')
		game->map_width++;
	while (str)
	{
		if (((int)ft_strlen(str)) != game->map_width)
		{
			ft_printf("Error\ninvalid map size");
			exit(EXIT_FAILURE);
		}
		free(str);
		game->map_height++;
		str = get_next_line(fd);
	}
	close (fd);
}

void	read_map(t_game *game)
{
	int		fd;
	char	*map_line;
	int		i;

	fd = open(game->map_filename, O_RDONLY);
	map_line = get_next_line(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	i = 0;
	if (!game->map)
	{
		ft_printf("Error:\nread_map invalid");
		return ;
	}
	while (map_line)
	{
		game->map[i] = ft_strdup((const char *)map_line);
		free(map_line);
		map_line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
