/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:47:59 by asaber            #+#    #+#             */
/*   Updated: 2023/04/12 22:25:15 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(str) - 4;
	tmp = &str[i];
	j = 0;
	if (ft_strncmp(&str[i], ".ber", 4))
	{
		write(2, "INVALID PATH\n", 13);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		j;
	char	**map;
	int		fd;
	int		length;
	t_coord	*for_p;

	if (argc < 1)
		return (0);
	check_path(argv[1]);
	fd = open(argv[1], O_RDWR);
	length = check_length(fd);
	check_map(argv[1], length);
	if_map_valid(argv[1], length);
}
