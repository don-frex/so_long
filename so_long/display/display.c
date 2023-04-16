/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:48 by asaber            #+#    #+#             */
/*   Updated: 2023/04/16 22:30:47 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	drawing(t_mlx *mlx)
{
	int	j;
	int	i;

	j = 0;
	while (gameinfo.map[j])
	{
		i = 0;
		while (gameinfo.map[j][i])
		{
			if (gameinfo.map[j][i] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
			else if (gameinfo.map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->border, i * 32, j * 32);
			else if (gameinfo.map[j][i] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->coins, i * 32, j * 32);
			}
			else if (gameinfo.map[j][i] == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, i * 32, j * 32);
				mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->player, i * 32, j * 32);
			}
			else if (gameinfo.map[j][i] == 'E')
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
	if (keycode == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_window, vars->player, 3 * 64, 5 * 32);
	}
	return (0);
}

void	display(char *path, int lenght)
{
	t_mlx 	*mlx;

	gameinfo.map = copy_map(path);
	mlx = malloc(sizeof(t_mlx));
	mlx->width = 32 * ft_strlen(gameinfo.map[0]);
    mlx->height = 32 * lenght;
    mlx->mlx = mlx_init();
    mlx->mlx_window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "My Window");
    mlx->base = mlx_xpm_file_to_image(mlx->mlx, "src/ard.xpm", &mlx->width, &mlx->height);
	mlx->border = mlx_xpm_file_to_image(mlx->mlx, "src/wall.xpm", &mlx->width, &mlx->height);
	mlx->coins = mlx_xpm_file_to_image(mlx->mlx, "src/coin.xpm", &mlx->width, &mlx->height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "src/exit.xpm", &mlx->width, &mlx->height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "src/jooseph.xpm", &mlx->width, &mlx->height);
	mlx_key_hook(mlx->mlx_window, key_hook, &mlx);
    drawing(mlx);
    mlx_loop(mlx->mlx);

}
