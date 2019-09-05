/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:48:05 by kzina             #+#    #+#             */
/*   Updated: 2019/09/05 18:13:07 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	reset_mlx(t_mlx *param)
{
	if (param->formula == julia)
		param->k = get_complx(-0.4, 0.6);
	param->m = 50;
	param->x = 0;
	param->y = 0;
	param->z = 1.0;
	param->min.re = -2.0;
	param->min.im = -2.0;
	param->max.re = 2.0;
	param->max.im = param->min.im +
	(param->max.re - param->min.re) * HEIGHT / WIDTH;
}

int		key_press(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		exit(0);
		mlx_del(param);
	}
	if (keycode == 125)
		param->y -= 5 / param->z;
	if (keycode == 126)
		param->y += 5 / param->z;
	if (keycode == 123)
		param->x += 5 / param->z;
	if (keycode == 124)
		param->x -= 5 / param->z;
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
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21)
	{
		if (keycode == 18 && param->formula != mandelbrot)
			param->formula = mandelbrot;
		if (keycode == 19 && param->formula != julia)
			param->formula = julia;
		if (keycode == 20 && param->formula != mandelbar)
			param->formula = mandelbar;
		if (keycode == 21 && param->formula != mandelbrot_perp)
			param->formula = mandelbrot_perp;
		reset_mlx(param);
	}
	render(param);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *param)
{
	param->mouse.lastx = param->mouse.x;
	param->mouse.lasty = param->mouse.y;
	param->mouse.x = x;
	param->mouse.y = y;
	if (param->button && param->formula == julia)
		param->k = get_complx(
        	4 * ((double)x / WIDTH - 0.5),
        	4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	else if (param->button)
	{
		param->x += param->mouse.lastx - param->mouse.x;
		param->y += param->mouse.lasty - param->mouse.y;
	}
	render(param);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *param)
{
	if (button == 1)
	{
		param->button = 1;
	}
	if (button == 5)
	{
		param->z *= 0.8;
		param->max.re *= 0.8;
		param->max.im *= 0.8;
		param->min.im *= 0.8;
		param->min.re *= 0.8;
		if (param->x > 0 && param->x < HEIGHT)
			param->x += x - HEIGHT / 2;
		if (param->y > 0 && param->y < WIDTH)
			param->y += y - WIDTH / 2; 
	}
	if (button == 4)
	{
		param->z *= 1.2;
		param->max.re *= 1.2;
		param->max.im *= 1.2;
		param->min.im *= 1.2;
		param->min.re *= 1.2;
		if (param->x > 0 && param->x < HEIGHT)
			param->x += x - HEIGHT / 2;
		if (param->y > 0 && param->y < WIDTH)
			param->y += y - WIDTH / 2; 
	}
	render(param);
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

void	controls(t_mlx *param, pid_t pid)
{
	mlx_hook(param->win, 2, 0, key_press, param);
	mlx_hook(param->win, 4, 0, mouse_press, param);
	mlx_hook(param->win, 6, 0, mouse_move, param);
	mlx_hook(param->win, 5, 0, mouse_release, param);
	printf("everything okey pid is %d --- controls", pid);
}
