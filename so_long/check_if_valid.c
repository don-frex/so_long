/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:04:45 by asaber            #+#    #+#             */
/*   Updated: 2023/04/14 02:07:21 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char *path, int length)
{
	char	**map;
	int		fd;
	int		j;

	map = (char **)malloc(length + 1);
	fd = open(path, O_RDWR);
	j = 0;
	while (j < length)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	close(fd);
	return (map);
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

	map = copy_map(path, length);
	visit = srch_mp('P', map, length);
	while (t_nodeline(visit))
		check_der(&visit, map);
	j = 0;
	while (j < length)
	{
		printf("%s", map[j]);
		j++;
	}
	if (check_char('E', map, length) || check_char('C', map, length))
	{
		printf("\npath invalid yohohoho!!!\n");
		exit(1);
	}
}
