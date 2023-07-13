/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:01:35 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/01 13:49:26 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	put_player_img(t_game *game, int *j, int *i)
{
	mlx_put_image_to_window(game->mlx_instance, game->mlx_win, \
							game->textures->player, (*j) * 64, (*i) * 64);
	game->x = *j;
	game->y = *i;
}

void	put_wall_img(t_game *game, int *j, int *i)
{
	mlx_put_image_to_window(game->mlx_instance, game->mlx_win, \
							game->textures->wall, (*j) * 64, (*i) * 64);
}

void	put_coin_img(t_game *game, int *j, int *i)
{
	mlx_put_image_to_window(game->mlx_instance, game->mlx_win, \
							game->textures->coin, (*j) * 64, (*i) * 64);
}

void	put_empty_img(t_game *game, int *j, int *i)
{
	mlx_put_image_to_window(game->mlx_instance, game->mlx_win, \
							game->textures->empty, (*j) * 64, (*i) * 64);
}

void	put_door_img(t_game *game, int *j, int *i)
{
	mlx_put_image_to_window(game->mlx_instance, game->mlx_win, \
							game->textures->door, (*j) * 64, (*i) * 64);
}
