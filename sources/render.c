/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:24:36 by kzina             #+#    #+#             */
/*   Updated: 2019/08/14 18:47:07 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

void	render(t_mlx *win)
{
	ft_bzero(win->img->data_address, WIDTH * HEIGHT * 4);
	if (win->type == Julia)
		algorithm_fract(win, julia);
	if (win->type == Mandelbrot)
		algorithm_fract(win, mandelbrot);
	mlx_put_image_to_window(win->mlx, win->win, win->img->image, 0, 0);
}