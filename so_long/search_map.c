/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:05:56 by asaber            #+#    #+#             */
/*   Updated: 2023/04/07 01:40:46 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*search_map(char c, char *path, int length)
{
	t_coord	*coordinates;
	char	*line;
	int		fd;
	int		i;
	int		j;

	fd = open(path, O_RDWR);
	j = 1;
	while (j <= length)
	{
		i = 0;
		line = get_next_line(fd);
		while (line[i])
		{
			if (line[i] == c)
			{
				coordinates = malloc(sizeof(t_coord));
				coordinates->x = i + 1;
				coordinates->y = j;
			}
			i++;
		}
		j++;
	}
	return (coordinates);
}
