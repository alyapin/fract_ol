/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:46:41 by kzina             #+#    #+#             */
/*   Updated: 2019/09/03 17:51:26 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fract_ol.h"

int		julia(t_mlx *win)
{
	int			iter;
	t_complex	z;
	
	iter = 0;
	z = get_complx(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->m)
	{
		z = get_complx(z.re * z.re - z.im * z.im + win->k.re,
		2.0 * z.re * z.im + win->k.im);
		iter++;
	}
	return (iter);	
}

int		mandelbrot(t_mlx *win)
{
	int 		iter;
	t_complex	z;

	iter = 0;
	z = get_complx(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->m)
	{
		z = get_complx(z.re * z.re - z.im * z.im + win->c.re,
		2.0 * z.re * z.im + win->c.im);
		iter++;
	}
	return (iter);
}

int		mandelbar(t_mlx *win)
{
	int 		iter;
	t_complex	z;

	iter = 0;
	z = get_complx(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->m)
	{
		z = get_complx(z.re * z.re - z.im * z.im + win->c.re,
		-2.0 * z.re * z.im + win->c.im);
		iter++;
	}
	return (iter);
}

int		mandelbrot_perp(t_mlx *win)
{
	int 		iter;
	t_complex	z;

	iter = 0;
	z = get_complx(win->c.re, win->c.im);
	while (size_vector(z) <= 4 && iter < win->m)
	{
		z = get_complx(z.re * z.re - z.im * z.im + win->c.re,
		-2.0 * fabs(z.re) * z.im + win->c.im);
		iter++;
	}
	return (iter);
}
