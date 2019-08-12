/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:17:04 by kzina             #+#    #+#             */
/*   Updated: 2019/08/12 20:27:21 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

void	mandelbrot(t_image *img, t_mlx *win)
{
	int 		y;
	int 		x;
	t_complex	c;
	t_complex	fact;
	int			iter;

	y = -1;
	fact = get_fact(win->min, win->max);
	while (y++ < HEIGHT)
	{
		c.im = win->max.im - y * fact.im;
		x = -1;
		iter = -1;
		while (x++ < WIDTH)
		{
			c.re = win->min.re + x * fact.re;
			win->z = get_complx(c.re, c.im);
			while (size_vector(win->z) <= 4 && ++iter < win->m)
				win->z = mandel(win->z, c);
			img->data_address[x + y * img->line_size] = color(iter, win);
		}
	}
}