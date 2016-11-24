/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:07:58 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/19 02:22:17 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		ft_is_param(char *str)
{
	if (ft_strcmp(str, "Julia") == 0 || ft_strcmp(str, "Mandel") == 0)
		return (1);
	else
		return (0);
}

int		ft_get_col(int y, int x, t_mlx *mlx)
{
	t_cpx	z;
	t_cpx	c;
	double	tmp;
	int		i;

	i = 0;
	z.r = 0;
	z.i = 0;
	c.r = ((float)x / 1350) * 2.7 * mlx->zoom + X1 + mlx->merge.r;
	c.i = ((float)y / 1200) * 2.4 * mlx->zoom + Y1 + mlx->merge.i;
	while (z.r * z.r + z.i * z.i < 4 && i < mlx->max_it)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		i++;
	}
	return ((i * 0xFFFFFF / mlx->max_it) << mlx->c);
}

void	ft_put_fract(t_mlx *mlx)
{
	int			i;
	int			col;

	i = -1;
	while (++i < 1350 * 1200)
	{
		if (ft_strcmp(mlx->name, "Mandel") == 0)
			col = ft_get_col(i / 1350, i % 1350, mlx);
		else
			col = 0;
		(mlx->p)[i * 4] = (col & 0xFF);
		(mlx->p)[i * 4 + 1] = (col & 0xFF00) >> 8;
		(mlx->p)[i * 4 + 2] = (col & 0xFF0000) >> 16;
		(mlx->p)[i * 4 + 3] = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2 || !(ft_is_param(av[1])))
		ft_putstr(USAGE);
	else
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1350, 1200, "lem_in graphical viem");
		mlx.img = mlx_new_image(mlx.mlx, 1350, 1200);
		mlx.p = mlx_get_data_addr(mlx.img, &(mlx.bp), &(mlx.sl), &(mlx.endian));
		mlx.zoom = 1;
		mlx.name = av[1];
		mlx.merge.r = 0;
		mlx.merge.i = 0;
		mlx.max_it = 50;
		mlx.c = 0;
		ft_put_fract(&mlx);
		mlx_mouse_hook(mlx.win, my_mouse_func, &mlx);
		mlx_hook(mlx.win, 2, (1L<<0), my_key_func, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (1);
}
