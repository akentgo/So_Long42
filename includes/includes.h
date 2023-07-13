/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:09:02 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 13:11:30 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl_include/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESCAPE 53

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*coin;
	void	*door;
	void	*empty;

}	t_text;

typedef struct s_game
{
	int		map_height;
	int		map_width;
	int		n_coins;
	int		x;
	int		y;
	int		player;
	int		exit;
	int		moves;
	int		doors;
	char	*map_filename;
	void	*mlx_instance;
	void	*mlx_win;
	char	**map;
	t_text	*textures;
}	t_game;

void	read_map(t_game *game);
void	create_map(t_game *game);
void	map_sizes(t_game *game);
void	game_parser(t_game *game);
int		game_exit(t_game *game);
int		check_file_name(t_game *game);
int		check_closed_map(t_game *game);
int		check_symbols(t_game *game);
int		check_min_chars(t_game *game);
int		check_exits(t_game *game);
int		check_players(t_game *game);
int		key_setup(int keycode, t_game *game);
int		check_valid_path(t_game *game);
void	endgame(t_game *game);
void	count_coins(t_game *game);
void	put_player_img(t_game *game, int *j, int *i);
void	put_wall_img(t_game *game, int *j, int *i);	
void	put_coin_img(t_game *game, int *j, int *i);
void	put_empty_img(t_game *game, int *j, int *i);
void	put_door_img(t_game *game, int *j, int *i);

#endif