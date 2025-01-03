/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:39:36 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/02 16:34:25 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_full_free(t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
		free(game->map[i]);
	free(game->map);
	i = -1;
	while (++i < game->row)
		free(game->cpymap[i]);
	free(game->cpymap);
	free(game->data);
	free(game);
	exit(1);
}

void	ft_error(char *message, t_map *game)
{
	write(2, message, ft_strlen(message));
	write(1, "\n", 1);
	free(game);
	exit(1);
}

void	ft_error_1(char *message, t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
		free(game->map[i]);
	free(game->map);
	i = -1;
	while (++i < game->row)
		free(game->cpymap[i]);
	free(game->cpymap);
	free(game);
	write(2, message, ft_strlen(message));
	write(1, "\n", 1);
	exit(1);
}

void	ft_error_2(char *message, t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->row)
		free(game->map[i]);
	free(game->map);
	i = -1;
	while (++i < game->row)
		free(game->cpymap[i]);
	free(game->cpymap);
	free(game->data);
	free(game);
	write(2, message, ft_strlen(message));
	write(1, "\n", 1);
	exit(1);
}

void	ft_finish(t_map *game)
{
	write(1, "The game is complated.", 22);
	ft_full_free(game);
	ft_free_mlx(game);
	exit(1);
}
