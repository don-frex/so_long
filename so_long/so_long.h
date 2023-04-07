/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:43:39 by asaber            #+#    #+#             */
/*   Updated: 2023/04/07 01:07:49 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct so_long
{
	int				x;
	int				y;
	struct so_long	*next;
}	t_coord;

int		ft_strlen(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
int		check_length(int fd);
void	check_map(int fd, int length);
void	check_border(int fd, int length);
void	min_condition(int fd, int length);
void	check_characters(char *path, int fd, int length);
t_coord	*search_map(char c, char *path, int length);

#endif