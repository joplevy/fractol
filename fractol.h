/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:10:13 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/25 01:35:51 by jplevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE "./fractol param\nparam : Mandel\n\tJulia\n\tBar\n"
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

typedef	struct		s_cpx
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
	t_cpx			mouse;
	int				max_it;
	int				c;
	int				block;
	char			*name;
}					t_mlx;

/*
** moves.c
*/
int					my_mouse_func(int keycode, int x, int y, void *param);
int					my_key_func(int keycode, void *param);
void				ft_move_rlud(void *param, double m, double n);
int					my_mouse_move_func(int x, int y, void *param);

/*
** fract.c
*/
void				ft_put_fract(t_mlx *mlx);
int					ft_get_col(int y, int x, t_mlx *mlx);
int					ft_get_bar(int y, int x, t_mlx *mlx);
int					ft_get_jul(int y, int x, t_mlx *mlx);

/*
** main.c
*/
int					ft_is_param(char *str);
void				ft_t_mlx_init(t_mlx *mlx);
#endif
