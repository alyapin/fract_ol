/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_shape_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:59:17 by kzina             #+#    #+#             */
/*   Updated: 2019/09/10 18:13:29 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		cubic_mandelbar(t_mlx *win)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = get_complex(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->max_iter)
	{
		z = get_complex(-((z.re * z.re) - (z.im * z.im * 3)) * z.re + win->c.re,
		((z.re * z.re * 3) - z.im * z.im) * z.im + win->c.im);
		iter++;
	}
	return (iter);
}

int		heart_mandelbrot(t_mlx *win)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = get_complex(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->max_iter)
	{
		z = get_complex(z.re * z.re - z.im * z.im + win->c.re,
		fabs(z.re) * z.im * 2.0 + win->c.im);
		iter++;
	}
	return (iter);
}

int		buffalo(t_mlx *win)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = get_complex(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->max_iter)
	{
		z = get_complex(fabs(z.re * z.re - z.im * z.im) + win->c.re,
		fabs(z.re * z.im) * -2.0 + win->c.im);
		iter++;
	}
	return (iter);
}

int		quasi_perpendicular_3rd(t_mlx *win)
{
	int			iter;
	t_complex	z;

	iter = 0;
	z = get_complex(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->max_iter)
	{
		z = get_complex(((z.re * z.re) - (z.im * z.im * 3))
			* fabs(z.re) + win->c.re, -fabs((z.re * z.re * 3.0)
				- z.im * z.im) * z.im + win->c.im);
		iter++;
	}
	return (iter);
}
