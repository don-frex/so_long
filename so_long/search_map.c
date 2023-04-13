/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:05:56 by asaber            #+#    #+#             */
/*   Updated: 2023/04/11 06:50:25 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_coord(int x, int y, char **map)
{
	if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C')
		return (0);
	return (1);
}

t_coord	*search_new_map(char c, char **map, int length)
{
	t_coord	*coord;
	int		i;
	int		j;

	j = 0;
	while (j < length)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				coord = malloc(sizeof(t_coord));
				coord->x = i;
				coord->y = j;
			}
			i++;
		}
		j++;
	}
	return (coord);
}
