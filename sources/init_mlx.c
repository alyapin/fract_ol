/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:37:48 by kzina             #+#    #+#             */
/*   Updated: 2019/08/12 19:44:49 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

t_mlx		*init_mlx(void)
{
	t_mlx *window;

	if ((window = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Fract'ol");
	if ((window->img = init_img(window)) == NULL)
		return (NULL);
	window->min.re = -2.0;
	window->min.im = -2.0;
	window->max.re = 2.0;
	window->max.im = window->min.im +
	(window->max.re - window->min.re) * HEIGHT / WIDTH;
	return (window);
}

t_image		*init_img(t_mlx *win)
{
	t_image *img;

	if ((img = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	if ((img->image  = mlx_new_image(win->mlx, WIDTH, HEIGHT)) ==  NULL)
		return (NULL);
	img->data_address = (int *)mlx_get_data_addr(img->image, &img->bpp,
	&img->line_size, &img->endian);
	img->line_size /= 4;
	return (img);
}

t_complex	get_complx(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	get_fact(t_complex min, t_complex max)
{
	t_complex fact;

	fact.re = (max.re - min.re) / (WIDTH - 1);
	fact.im = (max.im - min.im) / (HEIGHT - 1);
	return (fact);
}