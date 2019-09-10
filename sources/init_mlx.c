/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:37:48 by kzina             #+#    #+#             */
/*   Updated: 2019/09/10 19:08:37 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void		mlx_del(t_mlx **win)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (win[i]->win != NULL)
			mlx_destroy_window(win[i]->mlx, win[i]->win);
		if (win[i]->img != NULL)
		{
			if (win[i]->img->image != NULL)
				mlx_destroy_image(win[i]->mlx, win[i]->img->image);
			ft_memdel((void **)win[i]->img);
		}
	}
}

t_mlx		*init_mlx(void *mlx)
{
	t_mlx *window;

	if ((window = (t_mlx *)ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	window->mlx = mlx;
	window->win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "Fract'ol");
	init_image(window);
	window->min.re = -2.0;
	window->min.im = -2.0;
	window->max.re = 2.0;
	window->max.im = window->min.im +
	(window->max.re - window->min.re) * HEIGHT / WIDTH;
	window->max_iter = 50;
	window->k = get_complex(-0.4, 0.6);
	window->z = 1.0;
	window->x = 0;
	window->y = 0;
	window->mouse.x = HEIGHT / 2;
	window->mouse.y = WIDTH / 2;
	return (window);
}

void		init_image(t_mlx *ses)
{
	t_image	*img;
	t_image	*menu;
	int		width;
	int		height;

	width = 1200;
	height = 1200;
	if ((img = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
		return ;
	if ((img->image = mlx_new_image(ses->mlx, WIDTH, HEIGHT)) == NULL)
		return ;
	if ((menu = (t_image *)ft_memalloc(sizeof(t_image))) == NULL)
		return ;
	if ((menu->image = mlx_xpm_file_to_image(ses->mlx,
	"menu/menu.xpm", &width, &height)) == NULL)
		return ;
	img->data_address = (int *)mlx_get_data_addr(img->image,
	&img->bpp, &img->line_size, &img->endian);
	img->line_size /= 4;
	ses->menu = menu;
	ses->img = img;
}

t_complex	get_complex(double re, double im)
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
