/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:24:36 by kzina             #+#    #+#             */
/*   Updated: 2019/08/12 20:36:37 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

void	render(t_mlx *win)
{
	ft_memset(win->img->data_address, 0xFFFFFF, WIDTH * HEIGHT);
	mandelbrot(win->img, win);
	mlx_put_image_to_window(win->mlx, win->win, win->img->image, 0, 0);
}