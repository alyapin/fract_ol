/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:45:04 by kzina             #+#    #+#             */
/*   Updated: 2019/09/05 17:40:52 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fract_ol.h"

void	algorithm_fract(t_mlx *win)
{
	int 		y;
	int 		x;
	t_complex	fact;

	y = win->start;
	fact = get_fact(win->min, win->max);
	while (y < win->finish)
	{
		win->c.im = win->max.im - (y + win->y) * fact.im;
		x = 0;
		while (x < WIDTH)
		{
			win->c.re = win->min.re + (x + win->x) * fact.re;
			win->img->data_address[x + (y * win->img->line_size)] = color(win->formula(win), win);
			x++;
		}
		y++;
	}
}