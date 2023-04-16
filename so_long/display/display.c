/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:48 by asaber            #+#    #+#             */
/*   Updated: 2023/04/16 11:58:06 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	drawing(char **map, t_mlx *mlx)
{
	int	j;
	int	i;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
			else if (map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->border, i * 32, j * 32);
			else if (map[j][i] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->coins, i * 32, j * 32);
			}
			else if (map[j][i] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->player, i * 32, j * 32);
			}
			else if (map[j][i] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->exit, i * 32, j * 32);
			}
			i++;
		}
		j++;
	}
}

int	key_hook(int keycode, t_mlx *vars)
{
	(void) vars;
	printf("Hello from key_hook!  %d\n", keycode);
	return (0);
}

void	display(char *path, int lenght)
{
	t_mlx 	*mlx;
	char	**map;

	map = copy_map(path);
	mlx = malloc(sizeof(t_mlx));
	mlx->width = 32 * ft_strlen(map[0]);
    mlx->height = 32 * lenght;
    mlx->mlx = mlx_init();
    mlx->mlx_window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "My Window");
    mlx->base = mlx_xpm_file_to_image(mlx->mlx, "src/ard.xpm", &mlx->width, &mlx->height);
	mlx->border = mlx_xpm_file_to_image(mlx->mlx, "src/wall.xpm", &mlx->width, &mlx->height);
	mlx->coins = mlx_xpm_file_to_image(mlx->mlx, "src/coin.xpm", &mlx->width, &mlx->height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "src/exit.xpm", &mlx->width, &mlx->height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "src/jooseph.xpm", &mlx->width, &mlx->height);
	mlx_key_hook(mlx->mlx_window, key_hook, &mlx);
    drawing(map, mlx);
    mlx_loop(mlx->mlx);

}
