/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:08:47 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/03 17:50:42 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	move_up(t_game *game)
{
	if (game->map[game->y - 1][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
		game->n_coins--;
	}
	else if (game->map[game->y - 1][game->x] == '0')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
	}
	else if (game->map[game->y - 1][game->x] == 'E' && game->n_coins == 0)
		game->exit = 1;
	game->y--;
	game->moves++;
	printf("Moves-> %i\n", game->moves);
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] == 'C')
	{
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
		game->n_coins--;
	}
	else if (game->map[game->y + 1][game->x] == '0')
	{
		game->map[game->y + 1][game->x] = 'P';
		game->map[game->y][game->x] = '0';
	}
	else if (game->map[game->y + 1][game->x] == 'E' && game->n_coins == 0)
		game->exit = 1;
	game->y++;
	game->moves++;
	printf("Moves-> %i\n", game->moves);
}

void	move_right(t_game *game)
{
	if (game->map[game->y][game->x + 1] == 'C')
	{
	game->map[game->y][game->x + 1] = 'P';
		game->map[game->y][game->x] = '0';
		game->n_coins--;
	}
	else if (game->map[game->y][game->x + 1] == '0')
	{
		game->map[game->y][game->x + 1] = 'P';
		game->map[game->y][game->x] = '0';
	}
	else if (game->map[game->y][game->x + 1] == 'E' && game->n_coins == 0)
		game->exit = 1;
	game->x++;
	game->moves++;
	printf("Moves-> %i\n", game->moves);
}

void	move_left(t_game *game)
{
	if (game->map[game->y][game->x - 1] == 'C')
	{
		game->map[game->y][game->x - 1] = 'P';
		game->map[game->y][game->x] = '0';
		game->n_coins--;
	}
	else if (game->map[game->y][game->x - 1] == '0')
	{
		game->map[game->y][game->x - 1] = 'P';
		game->map[game->y][game->x] = '0';
	}
	else if (game->map[game->y][game->x - 1] == 'E' && game->n_coins == 0)
		game->exit = 1;
	game->x--;
	game->moves++;
	ft_printf("Moves-> %i\n", game->moves);
}

int	key_setup(int keycode, t_game *game)
{
	if (keycode == UP && game->map[game->y - 1][game->x] != '1')
		move_up(game);
	else if (keycode == DOWN && game->map[game->y + 1][game->x] != '1')
		move_down(game);
	else if (keycode == LEFT && game->map[game->y][game->x - 1] != '1')
		move_left(game);
	else if (keycode == RIGHT && game->map[game->y][game->x + 1] != '1')
		move_right(game);
	else if (keycode == ESCAPE)
		game_exit(game);
	return (1);
}
