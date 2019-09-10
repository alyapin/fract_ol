/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:48:05 by kzina             #+#    #+#             */
/*   Updated: 2019/09/10 18:14:34 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	interpolation(t_mlx *param, t_complex mouse, int button)
{
	double		fact;
	double		zoom;

	if (button == 4)
		zoom = 0.80;
	else
		zoom = 1.20;
	fact = 1.0 / zoom;
	param->min.re = recount(mouse.re, param->min.re, fact);
	param->min.im = recount(mouse.im, param->min.im, fact);
	param->max.re = recount(mouse.re, param->max.re, fact);
	param->max.im = recount(mouse.im, param->max.im, fact);
}

int		mouse_move(int x, int y, t_mlx *param)
{
	t_complex fact;

	fact = get_complex(param->max.re - param->min.re,
		param->max.im - param->min.im);
	param->mouse.lastx = param->mouse.x;
	param->mouse.lasty = param->mouse.y;
	param->mouse.x = x;
	param->mouse.y = y;
	if (param->mouse_button && param->formula == julia)
		param->k = get_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	else if (param->mouse_button)
		interpolation_mouse(param, fact);
	render(param);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *param)
{
	t_complex	mouse;

	if (button == 1)
	{
		param->mouse_button = 1;
	}
	mouse = get_complex(
			(double)x / (WIDTH / (param->max.re - param->min.re))
				+ param->min.re,
			(double)y / (HEIGHT / (param->max.im - param->min.im))
				* -1 + param->max.im);
	if (button == 4 || button == 5)
		interpolation(param, mouse, button);
	render(param);
	return (0);
}

int		mouse_release(int button, int x, int y, t_mlx *param)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		param->mouse_button = 0;
	}
	return (0);
}

void	controls(t_mlx *param)
{
	mlx_hook(param->win, 2, 0, key_press, param);
	mlx_hook(param->win, 3, 0, key_release, param);
	mlx_hook(param->win, 4, 0, mouse_press, param);
	mlx_hook(param->win, 6, 0, mouse_move, param);
	mlx_hook(param->win, 5, 0, mouse_release, param);
}
