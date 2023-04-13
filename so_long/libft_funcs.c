/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:58:59 by asaber            #+#    #+#             */
/*   Updated: 2023/04/13 02:18:05 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0' && c[i] != '\n')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	i = 0;
	while ((ptrs1[i] || ptrs2[i]) && i < n)
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}

void	ft_lstadd_back(t_coord *lst, t_coord *new)
{
	t_coord	*end;

	end = lst;
	if (lst == NULL)
	{
		printf("\no_o\n");
		lst = new;
		return ;
	}
	else
		while (end->next)
			end = end->next;
		end->next = new;
		new->next = NULL;
}

t_coord	*ft_lstnew(int x, int y)
{
	t_coord	*begin;

	begin = NULL;
	begin = (t_coord *) malloc(sizeof(t_coord));
	if (begin == 0)
		return (NULL);
	begin->x = x;
	begin->y = y;
	begin->next = NULL;
	return (begin);
}

void	prnt(t_coord *linked)
{
	printf("\n|||||||||||||");
	while (linked)
	{
		printf("\n(x = %d y = %d)", linked->x, linked->y);
		linked = linked->next;
	}
}
