/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:12:36 by asaber            #+#    #+#             */
/*   Updated: 2023/05/01 17:05:45 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_length(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	check_is_one(char *line)
{
	int	i;
	int	size;

	size = ft_strlen(line) - 1;
	i = 0;
	while (i <= size)
	{
		if (line[i] != '1')
		{
			write(2, "INVALID MAP\n", 12);
			free(line);
			exit(1);
		}
		i++;
	}
	free(line);
}

void	check_edges(char *line)
{
	int	end;

	end = ft_strlen(line) - 1;
	if (line[0] != '1' || line[end] != '1')
	{
		write(2, "INVALID MAP\n", 12);
		free(line);
		exit(1);
	}
	free(line);
}

void	check_border(int fd, int length)
{
	char	*line;
	int		size;

	line = get_next_line(fd);
	size = ft_strlen(line);
	free(line);
	while (length-- > 1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) != size)
		{
			write(2, "INVALID MAP BOR\n", 16);
			exit(1);
		}
		free(line);
	}
	close(fd);
}

void	check_map(char *path, int length)
{
	int	fd;
	int	i;

	fd = open(path, O_RDWR);
	i = 1;
	while (i <= length)
	{
		if (i == 1 || i == length)
			check_is_one(get_next_line(fd));
		else
			check_edges(get_next_line(fd));
		i++;
	}
	close(fd);
	check_border(open(path, O_RDWR), length);
	check_characters(path, length);
}
