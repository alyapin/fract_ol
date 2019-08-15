/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:48:05 by kzina             #+#    #+#             */
/*   Updated: 2019/08/15 18:35:28 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		key_press(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		exit(0);
		mlx_del(param);
	}
	if (keycode == 125)
		param->dy -= 10;
	if (keycode == 126)
		param->dy += 10;
	if (keycode == 123)
		param->dx += 10;
	if (keycode == 124)
		param->dx -= 10;
	if (keycode == 89 || keycode == 91)
	{
		if (keycode == 89)
		{
			param->k.re -= 0.005;
			param->k.im -= 0.005;
		}
		if (keycode == 91)
		{
			param->k.re += 0.005;
			param->k.im += 0.005;
		}
	}
	if (keycode == 78 || keycode == 69)
	{
		if (keycode == 78)
			if (param->m > 0)
				param->m--;
		if (keycode == 69)
			param->m++;
	}
	if (keycode == 18 || keycode == 19)
	{
		if (keycode == 18 && param->formula != mandelbrot)
		{
			param->formula = mandelbrot;
			param->m = 50;
		}
		if (keycode == 19 && param->formula != julia)
		{
			param->formula = julia;
			param->m = 50;
			param->k = get_complx(-0.4, 0.6);
		}
	}
	render(param);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *param)
{
	if (param->button)
		param->k = get_complx(
        	4 * ((double)x / WIDTH - 0.5),
        	4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	render(param);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *param)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		param->button = 1;
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_mlx *param)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		param->button = 0;
	}
	return (0);
}

void	controls(t_mlx *param)
{
	mlx_hook(param->win, 2, 0, key_press, param);
	mlx_hook(param->win, 4, 0, mouse_press, param);
	mlx_hook(param->win, 6, 0, mouse_move, param);
	mlx_hook(param->win, 5, 0, mouse_release, param);
}
