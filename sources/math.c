/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:14:32 by kzina             #+#    #+#             */
/*   Updated: 2019/08/15 17:51:05 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double		size_vector(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

int			color(int iter, t_mlx *win)
{
	int		max;
	double 	t;

	max = win->m;
	t = (double)iter / (double) max;
	//if (t < 1)
	//	return (0xFFFFFF);
	/*if (t < 0.8 && t >= 0.7)
		return (0xFF0000);*/
	//return ((int)(9 * (1 - t) * t * t * t * 255));
	return ((1.0 - t) * 0.98 * 0xFFFFFF);
	//return (6905501);
}
