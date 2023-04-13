/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:08:52 by asaber            #+#    #+#             */
/*   Updated: 2023/04/13 01:23:03 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top(t_coord *coord, char **map)
{
	int	x;
	int	y;

	if (coord->y == 1)
		return (1);
	x = coord->x;
	y = coord->y - 1;
	if (search_coord(x, y, map))
		return (1);
	return (0);
}

int	check_low(t_coord *coord, char **map)
{
	int	x;
	int	y;

	if (coord->y == 1)
		return (1);
	x = coord->x;
	y = coord->y + 1;
	if (search_coord(x, y, map))
		return (1);
	return (0);
}

int	check_right(t_coord *coord, char **map)
{
	int	x;
	int	y;

	if (coord->y == 1)
		return (1);
	x = coord->x + 1;
	y = coord->y;
	if (search_coord(x, y, map))
		return (1);
	return (0);
}

int	check_left(t_coord *coord, char **map)
{
	int	x;
	int	y;

	if (coord->y == 1)
		return (1);
	x = coord->x - 1;
	y = coord->y;
	if (search_coord(x, y, map))
		return (1);
	return (0);
}
