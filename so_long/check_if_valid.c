/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:04:45 by asaber            #+#    #+#             */
/*   Updated: 2023/04/13 02:30:27 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char *path, int length)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		j;

	map = (char **)malloc(length + 1);
	fd = open(path, O_RDWR);
	j = 0;
	while (j < length)
	{
		i = 0;
		line = get_next_line(fd);
		map[j] = (char *) malloc(ft_strlen(line) + 2);
		while (line[i])
		{
			map[j][i] = line[i];
			i++;
		}
		map[j][i] = '\0';
		free(line);
		j++;
	}
	close(fd);
	return (map);
}

void	print_in_map(char **map, char c, int x, int y)
{
	map[y][x] = c;
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

int	check_visited(t_coord *point, t_coord *stack)
{
	while (stack)
	{
		if (stack->x == point->x && stack->y == point->y)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	check_direc(char **map, t_coord *posetion, t_coord *to_visit, t_coord *visited)
{
	t_coord	*tmp;
	int		x;
	int		y;

	if (!check_top(posetion, map))
	{
		x = posetion->x;
		y = posetion->y - 1;
		tmp = ft_lstnew(x, y);
		if (!check_visited(tmp, visited))
		{
			prnt(tmp);
			to_visit = tmp;
			printf("x -- %d\n",visited->x);
		}
		else
			printf("visited\n");
	}
	else
		printf("closed\n");
}

void	find_exit(char **map, t_coord **visited, t_coord **to_visit)
{
	t_coord	*tmp;

	while (*to_visit != NULL)
	{
		tmp = poop_stack(to_visit);
		if (check_visited(tmp, *visited))
		{
			write(1, "already visited\n", 16);
			continue ;
		}
		ft_lstadd_back(*visited, tmp);
		check_direc(map, tmp, *to_visit, *visited);
	}
}

void	if_map_valid(char *path, int length)
{
	char	**map;
	int		i;
	t_coord	*p;
	t_coord	*visited;
	t_coord	*to_visit;

	visited = NULL;
	to_visit = NULL;
	map = copy_map(path, length);
	p = search_new_map('P', map, length);
	to_visit = p;
	p->next = NULL;
	find_exit(map, &visited, &to_visit);
}
