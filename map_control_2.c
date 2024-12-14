/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:02:12 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/01 20:50:54 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_check(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < (game->col - 1))
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E')
				ft_error_1("Error: The map has unwanted charecter.", game);
			j++;
		}
		i++;
	}
}

void	char_check_2(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	game->c = 0;
	game->e = 0;
	game->p = 0;
	while (++i < game->row)
	{
		j = -1;
		while (++j < (game->col - 1))
		{
			if (game->map[i][j] == 'P')
				game->p++;
			else if (game->map[i][j] == 'C')
				game->c++;
			else if (game->map[i][j] == 'E')
				game->e++;
		}
	}
	if (game->e != 1 || game->p != 1)
		ft_error_1("Error: There can only one player and one exit.", game);
	else if (game->c < 1)
		ft_error_1("Error: The map must have least one collectable coin.",
			game);
}

void	find_player_and_exit(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < (game->col - 1))
		{
			if (game->map[i][j] == 'P')
			{
				game->player[0] = i;
				game->player[1] = j;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit[0] = i;
				game->exit[1] = j;
			}
		}
	}
}

void	flood_fill_check(t_map *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col - 1)
		{
			if (game->cpymap[i][j] == 'E' || game->cpymap[i][j] == 'C')
				ft_error_2("Error: The map is not playable.", game);
		}
	}
}
