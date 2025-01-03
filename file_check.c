/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:41:14 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/03 12:59:53 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	data_memory(t_map *game)
{
	game->data = malloc(sizeof(t_mlx));
	if (!game->data)
	{
		free(game->data);
		ft_error_2("Error: Memory problem!", game);
	}
}

void	flood_fill(int x, int y, t_map *game)
{
	if (game->cpymap[x][y] == '1')
		return ;
	game->cpymap[x][y] = '1';
	flood_fill(x + 1, y, game);
	flood_fill(x - 1, y, game);
	flood_fill(x, y + 1, game);
	flood_fill(x, y - 1, game);
}

void	open_window(t_map *game)
{
	int	h;
	int	w;

	game->data->mlx = mlx_init();
	game->data->window = mlx_new_window(game->data->mlx, (game->col) * 64,
			(game->row) * 64, "so_long");
	game->data->coin = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/coin.xpm", &h, &w);
	game->data->exit = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/exit.xpm", &h, &w);
	game->data->ground = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/ground.xpm", &h, &w);
	game->data->player = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/player.xpm", &h, &w);
	game->data->wall = mlx_xpm_file_to_image(game->data->mlx,
			"./textures/wall.xpm", &h, &w);
	if (!game->data->player || !game->data->exit || !game->data->coin
		|| !game->data->ground || !game->data->wall)
	{
		ft_error_2("Error:\nMissing image file!", game);
		exit(1);
	}
	put_image(game);
}

void	put_image(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col)
			put_image_1(game, i, j);
	}
}

void	put_image_1(t_map *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->ground, j * 64, i * 64);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->wall, j * 64, i * 64);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->coin, j * 64, i * 64);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->exit, j * 64, i * 64);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->data->mlx, game->data->window,
			game->data->player, j * 64, i * 64);
	return ;
}
