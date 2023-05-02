/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:23:37 by asaber            #+#    #+#             */
/*   Updated: 2023/05/02 19:14:57 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mov_hor(t_mlx *mlx, int i)
{
	if (!ischar(mlx->p->x + i, mlx->p->y, '1', game.map))
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bs,
			mlx->p->x * 32, mlx->p->y * 32);
		if (i == -1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ple,
				(mlx->p->x + i) * 32, mlx->p->y * 32);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player,
				(mlx->p->x + i) * 32, mlx->p->y * 32);
		mlx->p->x += i;	
	}
}

void	mov_ver(t_mlx *mlx, int j)
{
	if (!ischar(mlx->p->x, mlx->p->y + j, '1', game.map))
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bs,
			mlx->p->x * 32, mlx->p->y * 32);
		if (j == -1)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pt,
				mlx->p->x * 32, (mlx->p->y + j) * 32);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->pl,
				mlx->p->x * 32, (mlx->p->y + j) * 32);
		mlx->p->y += j;
	}
}

void	print(t_mlx *m, void *img, int x, int y)
{
	mlx_put_image_to_window(m->mlx, m->win, img, x * 32, y * 32);
}
