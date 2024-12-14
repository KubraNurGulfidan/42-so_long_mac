/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:57:02 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/01 21:33:30 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(char *argv, t_map *game)
{
	int	fd;
	int	len;

	fd = open(argv, O_RDWR);
	if (fd <= 0)
	{
		close(fd);
		ft_error("Error: File can not open.", game);
	}
	close(fd);
	len = ft_strlen(argv);
	if (argv[len - 1] == 'r' && argv[len - 2] == 'e' && argv[len - 3] == 'b'
		&& argv[len - 4] == '.')
		return ;
	else
		ft_error("Error: The map is not '.ber' extension.", game);
}

void	map_check_2(char *argv, t_map *game)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	game->row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->row++;
		free(line);
	}
	close(fd);
	free(line);
	if (game->row == 0)
		ft_error("Error: The map is empty.", game);
	game->map = (char **)malloc(game->row * sizeof(char *));
	game->cpymap = (char **)malloc(game->row * sizeof(char *));
	if (game->map == NULL || game->map == NULL)
		ft_error_1("Error: Memory problem!", game);
}

void	map(char *argv, t_map *game)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(argv, O_RDONLY);
	while (++i < game->row)
		game->map[i] = get_next_line(fd);
	game->col = ft_strlen(game->map[0]);
	close(fd);
	fd = open(argv, O_RDONLY);
	i = -1;
	while (++i < game->row)
		game->cpymap[i] = get_next_line(fd);
	close(fd);
}

void	is_rectangle(t_map *game)
{
	int	i;

	i = 1;
	while (i < game->row)
	{
		if (game->col != ft_strlen(game->map[i]))
			ft_error_1("Error: The map is not rectangle.", game);
		i++;
	}

}

void	wall_check(t_map *game)
{
	int	i;

	i = -1;
	while (++i < (game->col - 1))
	{
		if (game->map[0][i] != '1' || game->map[game->row - 1][i] != '1')
			ft_error_1("Error: The map must be enclosed by a wall.", game);
	}
	i = 1;
	while (i < (game->row - 1))
	{
		if (game->map[i][0] != '1' || game->map[i][game->col - 2] != '1')
			ft_error_1("Error: The map must be enclosed by a wall.", game);
		i++;
	}
	if (game->row >= 23 || game->col >= 42)
		ft_error_1("Error: The map does not fit on the screen!", game);
}
