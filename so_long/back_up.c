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