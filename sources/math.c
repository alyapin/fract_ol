/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:14:32 by kzina             #+#    #+#             */
/*   Updated: 2019/08/12 20:43:44 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

double		size_vector(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

t_complex	mandel(t_complex z, t_complex c)
{
	t_complex res;

	res.re = z.re * z.re - z.im * z.im + c.re;
	res.im = 2.0 * z.re * z.im + c.im;
	return (res); 
}

int			color(int iter, t_mlx *win)
{
	int		max;
	double 	t;

	max = win->m;
	t = (double)iter / (double) max;
	if (t < 0.3)
		return (0xFFFFFF);
	if (t > 0.3 && t < 1)
		return (0x00BFff);
	return (0);
}
