/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:05:56 by asaber            #+#    #+#             */
/*   Updated: 2023/04/14 02:07:06 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_coord(int x, int y, char **map)
{
	if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C')
		return (0);
	return (1);
}

int	check_char(char c, char **map, int length)
{
	int	i;
	int	j;

	j = 0;
	while (j < length)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

t_coord	*srch_mp(char c, char **map, int length)
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
				coord->next = NULL;
			}
			i++;
		}
		j++;
	}
	return (coord);
}
