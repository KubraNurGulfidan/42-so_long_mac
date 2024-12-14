/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgulfida <kgulfida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:20:50 by ekose             #+#    #+#             */
/*   Updated: 2024/07/01 20:31:22 by kgulfida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str, char *src)
{
	int		value;
	char	*tmp;

	while (1)
	{
		value = read(fd, str, BUFFER_SIZE);
		if (value == -1)
			return (NULL);
		else if (value == 0)
			break ;
		str[value] = '\0';
		if (src == NULL)
			src = ft_strdup("");
		tmp = src;
		src = ft_strjoin(tmp, str);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (src);
}

char	*ft_clean(char *line)
{
	int		i;
	char	*dst;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	dst = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (dst == NULL)
		return (NULL);
	if (dst[0] == '\0')
	{
		free(dst);
		dst = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*src;
	char		*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	line = ft_read(fd, str, src);
	free(str);
	if (line == NULL)
	{
		free(src);
		src = NULL;
		return (NULL);
	}
	src = ft_clean(line);
	return (line);
}
