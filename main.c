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

char	ft_get_col(int y, int x, float zoom, t_cpx merge)
{
	t_cpx	z;
	t_cpx	c;
	double	tmp;
	int		i;

	i = 0;
	z.r = 0;
	z.i = 0;
	c.r = ((float)x / 1350) * 2.7 * zoom + X1 + merge.r;
	c.i = ((float)y / 1200) * 2.4 * zoom + Y1 + merge.i;
	while (z.r * z.r + z.i * z.i < 4 && i < 50)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		i++;
	}
	return (i * 255 / 50);
}

void	ft_put_fract(t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i < 1350 * 1200)
		(mlx->p)[i * 4] = ft_get_col(i / 1350, i % 1350, mlx->zoom, mlx->merge);
}

void	ft_move_rlud(void *param, double m, double n)
{
	C_MLX->merge.r += m;
	C_MLX->merge.i += n;
	ft_put_fract(param);
	mlx_put_image_to_window(C_MLX->mlx, C_MLX->win, C_MLX->img, 0, 0);
}

int		my_key_func(int keycode, void *param)
{
	int		x;
	int		y;

	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		mlx_mouse_get_pos(C_MLX->win, &x, &y);
		ft_printf("x = %d, y = %d\n", x, y);
		C_MLX->zoom *= 0.9;
		ft_move_rlud(param, (((double)x - 540) / 1350) * 2.7 * C_MLX->zoom, (((double)y - 607.5) / 1200) * 2.4 * C_MLX->zoom);
		// ft_move_rlud(param, 0, 0);
	}
	if (keycode == 78)
	{
		C_MLX->zoom /= 0.9;
		ft_move_rlud(param, 0, 0);
	}
	if (keycode == 123)
		ft_move_rlud(param, 5.0 / 100, 0);
	if (keycode == 124)
		ft_move_rlud(param, -5.0 / 100, 0);
	if (keycode == 126)
		ft_move_rlud(param, 0, 5.0 / 100);
	if (keycode == 125)
		ft_move_rlud(param, 0, -5.0 / 100);
	return (0);
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
		mlx.p = mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.sl), &(mlx.endian));
		mlx.zoom = 1;
		mlx.merge.r = 0;
		mlx.merge.i = 0;
		ft_put_fract(&mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
		mlx_hook(mlx.win, 2, (1L<<0), my_key_func, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (1);
}
