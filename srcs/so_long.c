/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:31:13 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/08 08:13:33 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

void	init_map(t_game *game, char *mapname)
{
	game->map_height = 0;
	game->map_width = 0;
	game->n_coins = 0;
	game->player = 0;
	game->x = 0;
	game->y = 0;
	game->moves = 0;
	game->exit = 0;
	game->map_filename = mapname;
}

int	ft_frames(t_game *game)
{
	mlx_clear_window(game->mlx_instance, game->mlx_win);
	create_map(game);
	if (game->n_coins == 0 && game->exit == 1)
		game_exit(game);
	return (0);
}

int	parser(t_game *game)
{
	if (!check_players(game) || !check_exits(game) || \
		!check_min_chars(game))
		return (0);
	if (!check_symbols(game))
	{
		ft_printf("Error\nInvalid symbols found");
		return (0);
	}
	if (check_closed_map(game) == 0)
	{
		ft_printf("Error\nMap not closed");
		return (0);
	}
	else if (check_valid_path(game) == 0)
	{
		ft_printf("Error\nCannot finish game, check path");
		return (0);
	}
	if (!check_file_name(game))
	{
		ft_printf("Error\nInvalid file extension");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	atexit(ft_leaks);
	if (argc == 2)
	{
		game.mlx_instance = mlx_init();
		init_map(&game, argv[1]);
		game_parser(&game);
		map_sizes(&game);
		read_map(&game);
		if (!parser(&game))
			return (EXIT_FAILURE);
		game.mlx_win = mlx_new_window(game.mlx_instance, game.map_width * 64, \
										game.map_height * 64, "so_long");
		mlx_hook(game.mlx_win, 17, 0, game_exit, &game);
		mlx_hook(game.mlx_win, 2, 0, key_setup, &game);
		mlx_loop_hook(game.mlx_instance, ft_frames, &game);
		mlx_loop(game.mlx_instance);
	}
	return (0);
}
