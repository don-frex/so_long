/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:12:38 by asaber            #+#    #+#             */
/*   Updated: 2022/11/23 16:05:42 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_sln(char *str);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
char	*ft_calloc(int count, int size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif