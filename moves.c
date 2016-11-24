/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 04:19:51 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/24 04:20:57 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_rlud(void *param, double m, double n)
{
	C_MLX->merge.r += m;
	C_MLX->merge.i += n;
	ft_put_fract(param);
}

int		my_key_func(int keycode, void *param)
{
	int		x;
	int		y;

	if (keycode == 53)
		exit(0);
	if (keycode == 8)
	{
		C_MLX->c += 8;
		if (C_MLX->c > 16)
			C_MLX->c = 0;
		ft_put_fract(param);
	}
	if (keycode == 67 || keycode == 75)
	{
		if (keycode == 67)
			C_MLX->max_it *= 1.5;
		else
			C_MLX->max_it /= (C_MLX->max_it > 2) ? 1.5 : 1;
		ft_put_fract(param);
	}
	if (keycode == 69 || keycode == 78)
	{
		mlx_mouse_get_pos(C_MLX->win, &x, &y);
		if (keycode == 69)
		{
			C_MLX->zoom *= 0.9;
			ft_move_rlud(param, (((double)x - 607.5) / 1350) * 2.7 * \
				C_MLX->zoom, (((double)y - 540) / 1200) * 2.4 * C_MLX->zoom);
		}
		else
		{
			C_MLX->zoom /= 0.9;
			ft_move_rlud(param, (((double)x - 675) / 1350) * 2.7 * C_MLX->zoom\
				- 67.5 * 2.7 * C_MLX->zoom / 1350, (((double)y - 600) / 1200) *\
				 2.4 * C_MLX->zoom -60 * 2.4 * C_MLX->zoom / 1200);
		}
	}
	if (keycode == 124)
		ft_move_rlud(param, 5.0 / 100, 0);
	if (keycode == 123)
		ft_move_rlud(param, -5.0 / 100, 0);
	if (keycode == 125)
		ft_move_rlud(param, 0, 5.0 / 100);
	if (keycode == 126)
		ft_move_rlud(param, 0, -5.0 / 100);
	return (0);
}

int		my_mouse_func(int keycode, int x, int y, void *param)
{
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 5)
		{
			C_MLX->zoom *= 0.95;
			ft_move_rlud(param, ((((double)x - 607.5) / 1350) * 2.7 * \
				C_MLX->zoom) / 2, ((((double)y - 540) / 1200) * 2.4 * \
				C_MLX->zoom) / 2);
		}
		else
		{
			C_MLX->zoom /= 0.95;
			ft_move_rlud(param, ((((double)x - 675) / 1350) * 2.7 * C_MLX->zoom\
			- 67.5 * 2.7 * C_MLX->zoom / 1350) / 2, ((((double)y - 600)\
			/ 1200) * 2.4 * C_MLX->zoom -60 * 2.4 * C_MLX->zoom / 1200) / 2);
		}
	}
	return (0);
}
