/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:04:45 by asaber            #+#    #+#             */
/*   Updated: 2023/05/02 15:49:05 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char *path)
{
	char	*map;
	char	**push;
	int		fd;

	fd = open(path, O_RDWR);
	map = malloc(BUFFER * sizeof(char));
	read(fd, map, BUFFER);
	close(fd);
	push = ft_split(map, '\n');
	free(map);
	return (push);
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
	t_coord	*position;

	position = poop_stack(stack);
	if (!check_top(position, map))
	{
		map[position->y - 1][position->x] = 'P';
		ft_lstadd_back(stack, ft_lstnew(position->x, position->y - 1));
	}
	if (!check_right(position, map))
	{
		map[position->y][position->x + 1] = 'P';
		ft_lstadd_back(stack, ft_lstnew(position->x + 1, position->y));
	}
	if (!check_left(position, map))
	{
		map[position->y][position->x - 1] = 'P';
		ft_lstadd_back(stack, ft_lstnew(position->x - 1, position->y));
	}
	if (!check_low(position, map))
	{
		map[position->y + 1][position->y] = 'P';
		ft_lstadd_back(stack, ft_lstnew(position->x, position->y + 1));
	}
	free(position);
}

void	if_map_valid(char *path, int length)
{
	char	**map;
	t_coord	*visit;
	int		j;

	map = copy_map(path);
	j = 0;
	visit = srch_mp('P', map, length);
	while (t_nodeline(visit))
		check_der(&visit, map);
	free(visit);
	if (check_char('E', map, length) || check_char('C', map, length))
	{
		printf("\npath invalid yohohoho!!!\n");
		exit(1);
	}
	j = 0;
	while (length--)
	{
		free(map[j]);
		j++;
	}
	free(map);
}
