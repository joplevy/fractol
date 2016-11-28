/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:11:14 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/25 01:19:24 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_get_col(int y, int x, t_mlx *mlx)
{
	t_cpx	z;
	t_cpx	c;
	double	tmp;
	int		i;

	i = 0;
	z.r = (mlx->mouse.r / 1350) * 2.7 + X1;
	z.i = (mlx->mouse.i / 1200) * 2.4 + Y1;
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

int		ft_get_bar(int y, int x, t_mlx *mlx)
{
	t_cpx	z;
	t_cpx	c;
	double	tmp;
	int		i;

	i = 0;
	z.r = (mlx->mouse.r / 1350) * 2.7 + X1;
	z.i = (mlx->mouse.i / 1200) * 2.4 + Y1;
	c.r = ((float)x / 1350) * 2.7 * mlx->zoom + X1 + mlx->merge.r;
	c.i = ((float)y / 1200) * 2.4 * mlx->zoom + Y1 + mlx->merge.i;
	while (z.r * z.r + z.i * z.i < 4 && i < mlx->max_it)
	{
		tmp = z.r;
		z.i *= -1;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		i++;
	}
	return ((i * 0xFFFFFF / mlx->max_it) << mlx->c);
}

int		ft_get_jul(int y, int x, t_mlx *mlx)
{
	t_cpx	z;
	t_cpx	c;
	double	tmp;
	int		i;

	i = 0;
	c.r = (mlx->mouse.r / 1350) * 2.7 + X1;
	c.i = (mlx->mouse.i / 1200) * 2.4 + Y1;
	z.r = ((float)x / 1350) * 2.7 * mlx->zoom + X1 + mlx->merge.r;
	z.i = ((float)y / 1200) * 2.4 * mlx->zoom + Y1 + mlx->merge.i;
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
		else if (ft_strcmp(mlx->name, "Julia") == 0)
			col = ft_get_jul(i / 1350, i % 1350, mlx);
		else if (ft_strcmp(mlx->name, "Bar") == 0)
			col = ft_get_bar(i / 1350, i % 1350, mlx);
		else
			col = 0;
		(mlx->p)[i * 4] = (col & 0xFF);
		(mlx->p)[i * 4 + 1] = (col & 0xFF00) >> 8;
		(mlx->p)[i * 4 + 2] = (col & 0xFF0000) >> 16;
		(mlx->p)[i * 4 + 3] = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
