/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:35:42 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/03 17:03:39 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	game_exit(t_game *game)
{
	(void)*game;
	mlx_destroy_window (game->mlx_instance, game->mlx_win);
	exit(EXIT_SUCCESS);
}

void	game_parser(t_game *game)
{
	int	img_width;
	int	img_height;

	game->textures = malloc(sizeof(t_text));
	game->textures->player = mlx_xpm_file_to_image(game->mlx_instance, \
							"texture/legionario.xpm", &img_width, &img_height);
	game->textures->wall = mlx_xpm_file_to_image(game->mlx_instance, \
							"texture/wall.xpm", &img_width, &img_height);
	game->textures->door = mlx_xpm_file_to_image(game->mlx_instance, \
							"texture/door.xpm", &img_width, &img_height);
	game->textures->empty = mlx_xpm_file_to_image(game->mlx_instance, \
							"texture/Flooring.xpm", &img_width, &img_height);
	game->textures->coin = mlx_xpm_file_to_image(game->mlx_instance, \
							"texture/peseta.xpm", &img_width, &img_height);
}

void	create_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				put_wall_img(game, &j, &i);
			else if (game->map[i][j] == '0')
				put_empty_img(game, &j, &i);
			else if (game->map[i][j] == 'P')
				put_player_img(game, &j, &i);
			else if (game->map[i][j] == 'C')
				put_coin_img(game, &j, &i);
			else if (game->map[i][j] == 'E')
				put_door_img(game, &j, &i);
			j++;
		}
		i++;
		j = 0;
	}
}
