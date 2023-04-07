/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 02:16:21 by asaber            #+#    #+#             */
/*   Updated: 2023/04/05 18:18:51 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_intruder(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'E' && line[i] != 'C' && line[i] != 'P')
		{
			write(2, "INVALID MAP\n", 12);
			exit(1);
		}
		i++;
	}
}

int	check_ecp(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	min_condition(int fd, int length)
{
	char	*line;
	int		end;
	int		e;
	int		c;
	int		p;

	e = 0;
	c = 0;
	p = 0;
	end = length;
	while (length)
	{
		if (length == end || length == 1)
			get_next_line(fd);
		else
		{
			line = get_next_line(fd);
			e += check_ecp(line, 'E');
			c += check_ecp(line, 'C');
			p += check_ecp(line, 'P');
		}
		length--;
	}
	if (e > 1 || c == 0 || p > 1)
	{
		write(2, "INVALID MAP dup\n", 16);
		exit(1);
	}
}

void	check_characters(char *path, int fd, int length)
{
	int	end;
	int	length_min;

	end = length;
	length_min = length;
	while (length)
	{
		if (length == end || length == 1)
			get_next_line(fd);
		else
			check_intruder(get_next_line(fd));
		length--;
	}
	close(fd);
	fd = open(path, O_RDWR);
	min_condition(fd, length_min);
}
