/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:07:58 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/25 01:39:43 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_is_param(char *str)
{
	if (ft_strcmp(str, "Julia") == 0 || ft_strcmp(str, "Mandel") == 0 \
		|| ft_strcmp(str, "Bar") == 0)
		return (1);
	else
		return (0);
}

void	ft_t_mlx_init(t_mlx *mlx)
{
	mlx->zoom = (ft_strcmp(mlx->name, "Mandel") == 0) ? 1 : 1.4;
	mlx->merge.r = (ft_strcmp(mlx->name, "Mandel") == 0) ? 0 : 0.27;
	mlx->merge.i = (ft_strcmp(mlx->name, "Mandel") == 0) ? 0 : -0.4;
	mlx->max_it = 50;
	mlx->c = 16;
	mlx->block = 0;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	int		r;
	int		i;

	if (ac != 2 || !(ft_is_param(av[1])))
		ft_putstr(USAGE);
	else
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1350, 1200, "lem_in graphical viem");
		mlx.img = mlx_new_image(mlx.mlx, 1350, 1200);
		mlx.p = mlx_get_data_addr(mlx.img, &(mlx.bp), &(mlx.sl), &(mlx.endian));
		mlx_mouse_get_pos(mlx.win, &r, &i);
		mlx.name = av[1];
		mlx.mouse.i = (float)i;
		mlx.mouse.r = (float)r;
		ft_t_mlx_init(&mlx);
		ft_put_fract(&mlx);
		mlx_mouse_hook(mlx.win, my_mouse_func, &mlx);
		mlx_hook(mlx.win, 2, (1L << 0), my_key_func, &mlx);
		mlx_hook(mlx.win, 6, (1L << 6), my_mouse_move_func, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (1);
}
