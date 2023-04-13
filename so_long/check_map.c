/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:12:36 by asaber            #+#    #+#             */
/*   Updated: 2023/04/09 13:13:27 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_length(int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		i++;
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
			exit(1);
		}
		i++;
	}
}

void	check_edges(char *line)
{
	int	end;

	end = ft_strlen(line) - 1;
	if (line[0] != '1' || line[end] != '1')
	{
		write(2, "INVALID MAP\n", 12);
		exit(1);
	}
}

void	check_border(int fd, int length)
{
	int	size;

	size = ft_strlen(get_next_line(fd));
	while (length-- > 1)
	{
		if (ft_strlen(get_next_line(fd)) != size)
		{
			write(2, "INVALID MAP BOR\n", 16);
			exit(1);
		}
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
