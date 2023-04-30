/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:48 by asaber            #+#    #+#             */
/*   Updated: 2023/04/30 03:03:39 by asaber           ###   ########.fr       */
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

void	not_finsish(t_mlx *mlx, int	keycode)
{
	if (!ischar(mlx->p->x + 1, mlx->p->y, 'E', gameinfo.map) && (keycode == 2 || keycode == 124))
		mov_hor(mlx, 1);
	else if (!ischar(mlx->p->x, mlx->p->y - 1, 'E', gameinfo.map) && (keycode == 13 || keycode == 126))
		mov_ver(mlx, -1);
	else if (!ischar(mlx->p->x, mlx->p->y + 1, 'E', gameinfo.map) && (keycode == 1 || keycode == 125))
		mov_ver(mlx, 1);
	else if (!ischar(mlx->p->x - 1, mlx->p->y, 'E', gameinfo.map) &&  (keycode == 0 || keycode == 123))
		mov_hor(mlx, -1);
}

void	finish(t_mlx *mlx, int keycode)
{
	if (keycode == 2 || keycode == 124)
		mov_hor(mlx, 1);
	else if (keycode == 13 || keycode == 126)
		mov_ver(mlx, -1);
	else if (keycode == 1 || keycode == 125)
		mov_ver(mlx, 1);
	else if (keycode == 0 || keycode == 123)
		mov_hor(mlx, -1);
	if (ischar(mlx->p->x, mlx->p->y, 'E', gameinfo.map))
		exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if(ischar(mlx->p->x, mlx->p->y, 'C', gameinfo.map))
	{
		mlx->ncoins--;
		gameinfo.map[mlx->p->y][mlx->p->x] = '0';
	}
	if (!mlx->ncoins)
		finish(mlx, keycode);
	else
		not_finsish(mlx, keycode);
	return (0);
}

void	display(char *path, int lenght)
{
	t_mlx 	*mlx;

	(void) *path;
	mlx = malloc(sizeof(t_mlx));
	mlx->p = srch_mp('P', gameinfo.map, lenght);
	mlx->ncoins = count_char('C', gameinfo.map);
	mlx->width = 32 * ft_strlen(gameinfo.map[0]);
    mlx->height = 32 * lenght;
    mlx->mlx = mlx_init();
    mlx->mlx_window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "S0_l0ng");
    mlx->base = mlx_xpm_file_to_image(mlx->mlx, "src/ard.xpm", &mlx->width, &mlx->height);
	mlx->border = mlx_xpm_file_to_image(mlx->mlx, "src/wall.xpm", &mlx->width, &mlx->height);
	mlx->coins = mlx_xpm_file_to_image(mlx->mlx, "src/coin.xpm", &mlx->width, &mlx->height);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "src/exit.xpm", &mlx->width, &mlx->height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, "src/jooseph.xpm", &mlx->width, &mlx->height);
    drawing(mlx);
	mlx_key_hook(mlx->mlx_window, key_hook, mlx);
    mlx_loop(mlx->mlx);

}
