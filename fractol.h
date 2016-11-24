/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:10:13 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/24 04:27:17 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE "./fractol param\nparam : Mandel\n\tJulia\n"
# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2
# define C_MLX ((t_mlx*)(param))

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <float.h>
# include <math.h>

typedef	struct 		s_cpx
{
	double			r;
	double			i;
}					t_cpx;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*p;
	int				bp;
	int				sl;
	int				endian;
	float			zoom;
	t_cpx			merge;
	int				max_it;
	int				c;
	char			*name;
}					t_mlx;

/*
** moves.c
*/
int					my_mouse_func(int keycode, int x, int y, void *param);
int					my_key_func(int keycode, void *param);
void				ft_move_rlud(void *param, double m, double n);

/*
** main.c
*/
int					ft_is_param(char *str);
void				ft_put_fract(t_mlx *mlx);
int					ft_get_col(int y, int x, t_mlx *mlx);
#endif