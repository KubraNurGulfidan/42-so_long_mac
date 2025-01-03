/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:57:02 by kgulfida          #+#    #+#             */
/*   Updated: 2024/07/03 13:53:38 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	strlen_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

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
		ft_error("Error\nThe map is empty.", game);
	game->map = (char **)malloc(game->row * sizeof(char *));
	game->cpymap = (char **)malloc(game->row * sizeof(char *));
	if (game->map == NULL || game->cpymap == NULL)
		ft_error_1("Error:\nMemory problem!", game);
}

void	map(char *argv, t_map *game)
{
	int	i;
	int	fd;

	i = -1;
	fd = open(argv, O_RDONLY);
	while (++i < game->row)
		game->map[i] = get_next_line(fd);
	game->col = strlen_newline(game->map[0]);
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
		if (game->col != strlen_newline(game->map[i]))
			ft_error_1("Error:\nThe map is not rectangle.", game);
		i++;
	}
}
