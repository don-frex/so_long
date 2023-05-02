/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:48 by asaber            #+#    #+#             */
/*   Updated: 2023/05/02 19:14:57 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	drawing(t_mlx *m)
{
	int	j;
	int	i;

	j = 0;
	while (game.map[j])
	{
		i = 0;
		while (game.map[j][i])
		{
			if (game.map[j][i] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->bo, i * 32, j * 32);
			else if (game.map[j][i] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->cn, i * 32, j * 32);
			else if (game.map[j][i] == 'P')
				mlx_put_image_to_window(m->mlx, m->win,
					m->player, i * 32, j * 32);
			else if (game.map[j][i] == 'E')
				mlx_put_image_to_window(m->mlx, m->win,
					m->exit, i * 32, j * 32);
			i++;
		}
		j++;
	}
}

void	not_finsish(t_mlx *mlx, int	n)
{
	if (!ischar(mlx->p->x + 1, mlx->p->y, 'E', game.map) && (n == 2 || n == 124))
		mov_hor(mlx, 1);
	else if (!ischar(mlx->p->x, mlx->p->y - 1,
			'E', game.map) && (n == 13 || n == 126))
		mov_ver(mlx, -1);
	else if (!ischar(mlx->p->x, mlx->p->y + 1,
			'E', game.map) && (n == 1 || n == 125))
		mov_ver(mlx, 1);
	else if (!ischar(mlx->p->x - 1, mlx->p->y, 'E', game.map)
		&& (n == 0 || n == 123))
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
	if (ischar(mlx->p->x, mlx->p->y, 'E', game.map))
	{
		free(mlx);
		exit(0);
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (ischar(mlx->p->x, mlx->p->y, 'C', game.map))
	{
		mlx->cs--;
		game.map[mlx->p->y][mlx->p->x] = '0';
	}
	printf("%d\n", keycode);
	if (!mlx->cs)
		finish(mlx, keycode);
	else
		not_finsish(mlx, keycode);
	return (0);
}

void	display(char *path, int lenght)
{
	t_mlx	*m;

	(void) *path;
	m = malloc(sizeof(t_mlx));
	m->p = srch_mp('P', game.map, lenght);
	m->cs = count_char('C', game.map);
	m->wi = 32 * ft_strlen(game.map[0]);
	m->he = 32 * lenght;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->wi, m->he, "S0_l0ng");
	m->bs = mlx_xpm_file_to_image(m->mlx, "src/ard.xpm", &m->wi, &m->he);
	m->bo = mlx_xpm_file_to_image(m->mlx, "src/wall.xpm", &m->wi, &m->he);
	m->cn = mlx_xpm_file_to_image(m->mlx, "src/coin.xpm", &m->wi, &m->he);
	m->exit = mlx_xpm_file_to_image(m->mlx, "src/exit.xpm", &m->wi, &m->he);
	m->player = mlx_xpm_file_to_image(m->mlx, "src/pac.xpm", &m->wi, &m->he);
	m->pt = mlx_xpm_file_to_image(m->mlx, "src/pac_top.xpm", &m->wi, &m->he);
	m->ple = mlx_xpm_file_to_image(m->mlx, "src/pac_left.xpm", &m->wi, &m->he);
	m->pl = mlx_xpm_file_to_image(m->mlx, "src/pac_low.xpm", &m->wi, &m->he);
	drawing(m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_hook(m->win, 17, 0, __exit, NULL);
	mlx_loop(m->mlx);
}
