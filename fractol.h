/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:10:13 by jplevy            #+#    #+#             */
/*   Updated: 2016/11/19 02:52:31 by jplevy           ###   ########.fr       */
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
	int				bpp;
	int				sl;
	int				endian;
	float			zoom;
	t_cpx			merge;
}					t_mlx;

#endif