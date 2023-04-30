/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:05:56 by asaber            #+#    #+#             */
/*   Updated: 2023/04/29 09:43:37 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_coord(int x, int y, char **map)
{
	if (map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C')
		return (0);
	return (1);
}

int	search_coordmap(int x, int y, char c, char **map)
{
	if (map[y][x] == '0' || map[y][x] == c|| map[y][x] == 'P')
		return (0);
	return (1);
}

int	ischar(int x, int y, char c, char **map)
{
	if(map[y][x] == c)
		return (1);
	return(0);
}

int	count_char(char c, char **map)
{
	int count;
	int	i;
	int	j;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
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
