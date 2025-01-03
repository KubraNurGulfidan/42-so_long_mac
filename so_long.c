/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:56:04 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/03 13:44:16 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *game)
{
	ft_full_free(game);
	ft_free_mlx(game);
	write(1, "You closed the game.", 20);
	exit(0);
}

void	ft_free_mlx(t_map *game)
{
	mlx_destroy_image(game->data->mlx, game->data->coin);
	mlx_destroy_image(game->data->mlx, game->data->exit);
	mlx_destroy_image(game->data->mlx, game->data->ground);
	mlx_destroy_image(game->data->mlx, game->data->player);
	mlx_destroy_image(game->data->mlx, game->data->wall);
	mlx_destroy_window(game->data->mlx, game->data->window);
	free(game->data->mlx);
	ft_full_free(game);
}

int	main(int ac, char **av)
{
	t_map	*game;

	game = (t_map *)malloc(sizeof(t_map));
	if (game == NULL)
		ft_error("Memory allocation failed.", game);
	if (ac != 2)
		ft_error("Error: Invalid arguments.", game);
	game->movment = 0;
	map_check(av[1], game);
	map_check_2(av[1], game);
	map(av[1], game);
	is_rectangle(game);
	wall_check(game);
	char_check(game);
	char_check_2(game);
	data_memory(game);
	find_player_and_exit(game);
	flood_fill(game->player[0], game->player[1], game);
	flood_fill_check(game);
	open_window(game);
	mlx_hook(game->data->window, 2, (1L << 0), key_press, game);
	mlx_hook(game->data->window, 17, 0L, close_window, game);
	mlx_loop(game->data->mlx);
	ft_full_free(game);
	return (0);
}
