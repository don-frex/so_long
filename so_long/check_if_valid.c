/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:04:45 by asaber            #+#    #+#             */
/*   Updated: 2023/04/16 09:47:29 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char *path)
{
	char	*map;
	int		fd;

	fd = open(path, O_RDWR);
	map = malloc(buffer * sizeof(char));
	read(fd, map, buffer);
	close(fd);
	return (ft_split(map, '\n'));
}

t_coord	*poop_stack(t_coord **stack)
{
	t_coord	*next;
	t_coord	*tmp;

	next = (*stack)->next;
	tmp = *stack;
	tmp->next = NULL;
	*stack = next;
	return (tmp);
}

void	check_der(t_coord **stack, char **map)
{
	int	x;
	int	y;
	t_coord	*position;

	position = poop_stack(stack);
	if (!check_top(position, map))
	{
		x = position->x;
		y = position->y - 1;
		map[y][x] = 'P';
		ft_lstadd_back(stack, ft_lstnew(x, y));
	}
	if (!check_right(position, map))
	{
		x = position->x + 1;
		y = position->y;
		map[y][x] = 'P';
		ft_lstadd_back(stack, ft_lstnew(x, y));
	}
	if (!check_left(position, map))
	{
		x = position->x - 1;
		y = position->y;
		map[y][x] = 'P';
		ft_lstadd_back(stack, ft_lstnew(x, y));
	}
	if (!check_low(position, map))
	{
		x = position->x;
		y = position->y + 1;
		map[y][x] = 'P';
		ft_lstadd_back(stack, ft_lstnew(x, y));
	}
}

void	if_map_valid(char *path, int length)
{
	char	**map;
	t_coord	*visit;
	int	j;

	map = copy_map(path);
	j = 0;
	
	visit = srch_mp('P', map, length);
	while (t_nodeline(visit))
		check_der(&visit, map);
	
	if (check_char('E', map, length) || check_char('C', map, length))
	{
		printf("\npath invalid yohohoho!!!\n");
		exit(1);
	}
}
