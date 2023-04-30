/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:23:37 by asaber            #+#    #+#             */
/*   Updated: 2023/04/30 01:52:57 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_hor(t_mlx *mlx, int i)
{
	if (!ischar(mlx->p->x + i, mlx->p->y, '1', gameinfo.map))
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, mlx->p->x * 32, mlx->p->y * 32);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->player, (mlx->p->x + i) * 32, mlx->p->y * 32);
		mlx->p->x += i;	
	}
}

void	mov_ver(t_mlx *mlx, int j)
{
	if (!ischar(mlx->p->x, mlx->p->y + j, '1', gameinfo.map) && !ischar(mlx->p->x, mlx->p->y + j, 'E', gameinfo.map))
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->base, mlx->p->x * 32, mlx->p->y * 32);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->player, mlx->p->x * 32, (mlx->p->y + j) * 32);
		mlx->p->y += j;
	}
}