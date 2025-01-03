/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:56:00 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/03 13:55:17 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*player;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*ground;
}			t_mlx;

typedef struct s_map
{
	t_mlx	*data;
	char	**map;
	char	**cpymap;
	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
	int		player[2];
	int		exit[2];
	int		movment;
	int		row;
	int		col;
}			t_map;

void		map_check(char *argv, t_map *game);
void		map_check_2(char *argv, t_map *game);
void		map(char *argv, t_map *game);
void		is_rectangle(t_map *game);
void		wall_check(t_map *game);
void		char_check(t_map *game);
void		char_check_2(t_map *game);
void		find_player_and_exit(t_map *game);
void		flood_fill(int x, int y, t_map *game);
void		flood_fill_check(t_map *game);
void		data_memory(t_map *game);
void		open_window(t_map *game);
void		put_image(t_map *game);
void		put_image_1(t_map *game, int i, int j);
void		ft_error(char *error, t_map *game);
void		ft_error_1(char *message, t_map *game);
void		ft_error_2(char *message, t_map *game);
void		ft_full_free(t_map *game);
void		ft_free_mlx(t_map *game);
int			key_press(int key_kode, t_map *game);
void		ft_finish(t_map *game);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);

#endif
