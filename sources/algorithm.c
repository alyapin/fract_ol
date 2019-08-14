/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:45:04 by kzina             #+#    #+#             */
/*   Updated: 2019/08/14 18:45:12 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

void	algorithm_fract(t_mlx *win, int (*f)(t_mlx *))
{
	int 		y;
	int 		x;
	t_complex	fact;

	y = 0;
	fact = get_fact(win->min, win->max);
	while (y < HEIGHT)
	{
		win->c.im = win->max.im - (y - win->dy) * fact.im;
		x = 0;
		while (x < WIDTH)
		{
			win->c.re = win->min.re + (x - win->dx) * fact.re;
			win->img->data_address[x + (y * win->img->line_size)] = color((*f)(win), win);
			x++;
		}
		y++;
	}
}