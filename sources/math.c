/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:14:32 by kzina             #+#    #+#             */
/*   Updated: 2019/09/10 18:13:10 by kzina            ###   ########.fr       */
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
	double	t;

	max = win->max_iter;
	t = (double)iter / (double)max;
	return ((1.0 - t) * 0.98 * 0xFFFFFF);
}

void		interpolation_mouse(t_mlx *param, t_complex fact)
{
	param->max.re += fact.re * (param->mouse.lastx - param->mouse.x) /
		(WIDTH * param->z);
	param->max.im -= fact.im * (param->mouse.lasty - param->mouse.y) /
		(HEIGHT * param->z);
	param->min.re += fact.re * (param->mouse.lastx - param->mouse.x) /
		(WIDTH * param->z);
	param->min.im -= fact.im * (param->mouse.lasty - param->mouse.y) /
		(HEIGHT * param->z);
}

double		recount(double start, double end, double fact)
{
	return (start + ((end - start) * fact));
}

void		reset_mlx(t_mlx *param)
{
	if (param->formula == julia)
		param->k = get_complex(-0.4, 0.6);
	param->x = 0;
	param->y = 0;
	param->z = 1.0;
	param->min.re = -2.0;
	param->min.im = -2.0;
	param->max.re = 2.0;
	param->max.im = param->min.im +
	(param->max.re - param->min.re) * HEIGHT / WIDTH;
}
