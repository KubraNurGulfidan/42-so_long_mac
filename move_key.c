/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:52:19 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/01 21:16:13 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_map *game)
{
	if (game->map[game->player[0] - 1][game->player[1]] != '1')
	{
		write(1, "Movement Count = ", 17);
		ft_putnbr_fd(++game->movment, 1);
		write(1, "\n", 1);
		if (game->map[game->player[0] - 1][game->player[1]] == 'C')
			game->c--;
		if (game->player[0] - 1 == game->exit[0]
			&& game->player[1] == game->exit[1] && game->c == 0)
			ft_finish(game);
		if (game->player[0] == game->exit[0]
			&& game->player[1] == game->exit[1])
		{
			game->map[game->player[0]][game->player[1]] = 'E';
			put_image(game);
			game->player[0]--;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
		else
		{
			game->map[game->player[0]][game->player[1]] = '0';
			game->player[0]--;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
	}
}

static void	move_down(t_map *game)
{
	if (game->map[game->player[0] + 1][game->player[1]] != '1')
	{
		write(1, "Movement Count = ", 17);
		ft_putnbr_fd(++game->movment, 1);
		write(1, "\n", 1);
		if (game->map[game->player[0] + 1][game->player[1]] == 'C')
			game->c--;
		if (game->map[game->player[0] + 1][game->player[1]] == 'E'
			&& game->c == 0)
			ft_finish(game);
		if (game->player[0] == game->exit[0]
			&& game->player[1] == game->exit[1])
		{
			game->map[game->player[0]][game->player[1]] = 'E';
			put_image(game);
			game->player[0]++;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
		else
		{
			game->map[game->player[0]][game->player[1]] = '0';
			game->player[0]++;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
	}
}

static void	move_left(t_map *game)
{
	if (game->map[game->player[0]][game->player[1] - 1] != '1')
	{
		write(1, "Movement Count = ", 17);
		ft_putnbr_fd(++game->movment, 1);
		write(1, "\n", 1);
		if (game->map[game->player[0]][game->player[1] - 1] == 'C')
			game->c--;
		if (game->map[game->player[0]][game->player[1] - 1] == 'E'
			&& game->c == 0)
			ft_finish(game);
		if (game->player[0] == game->exit[0]
			&& game->player[1] == game->exit[1])
		{
			game->map[game->player[0]][game->player[1]] = 'E';
			put_image(game);
			game->player[1]--;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
		else
		{
			game->map[game->player[0]][game->player[1]] = '0';
			game->player[1]--;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
	}
}

static void	move_right(t_map *game)
{
	if (game->map[game->player[0]][game->player[1] + 1] != '1')
	{
		write(1, "Movement Count = ", 17);
		ft_putnbr_fd(++game->movment, 1);
		write(1, "\n", 1);
		if (game->map[game->player[0]][game->player[1] + 1] == 'C')
			game->c--;
		if (game->map[game->player[0]][game->player[1] + 1] == 'E'
			&& game->c == 0)
			ft_finish(game);
		if (game->player[0] == game->exit[0]
			&& game->player[1] == game->exit[1])
		{
			game->map[game->player[0]][game->player[1]] = 'E';
			put_image(game);
			game->player[1]++;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
		else
		{
			game->map[game->player[0]][game->player[1]] = '0';
			game->player[1]++;
			game->map[game->player[0]][game->player[1]] = 'P';
		}
	}
}

int	key_press(int key_code, t_map *game)
{
	if (key_code == 53)
	{
		write(1, "Game closed!", 12);
		ft_full_free(game);
		ft_free_mlx(game);
		exit(0);
	}
	if (key_code == 13 || key_code == 126)
		move_up(game);
	else if (key_code == 1 || key_code == 125)
		move_down(game);
	else if (key_code == 0 || key_code == 123)
		move_left(game);
	else if (key_code == 2 || key_code == 124)
		move_right(game);
	put_image(game);
	return (0);
}
