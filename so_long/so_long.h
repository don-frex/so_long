/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:43:39 by asaber            #+#    #+#             */
/*   Updated: 2023/04/13 02:02:42 by asaber           ###   ########.fr       */
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
void	check_map(char *path, int length);
void	check_border(int fd, int length);
void	min_condition(int fd, int length);
void	check_characters(char *path, int length);
t_coord	*search_map(char c, char *path, int length);
int		search_coord(int x, int y, char **map);
int		check_top(t_coord *coord, char **map);
int		check_low(t_coord *coord, char **map);
int		check_right(t_coord *coord, char **map);
int		check_left(t_coord *coord, char **map);
int		map_len(char *path);
char	**copy_map(char *path, int length);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	if_map_valid(char *path, int length);
t_coord	*search_new_map(char c, char **map, int length);
t_coord	*ft_lstnew(int x, int y);
void	ft_lstadd_back(t_coord *lst, t_coord *new);
void	prnt(t_coord *linked);

#endif