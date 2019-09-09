/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:48:05 by kzina             #+#    #+#             */
/*   Updated: 2019/09/09 19:58:02 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static double	recount(double start, double end, double fact)
{
	return (start + ((end - start) * fact));
}

void	reset_mlx(t_mlx *param)
{
	if (param->formula == julia)
		param->k = get_complex(-0.4, 0.6);
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
	t_complex fact;

	fact = get_complex(param->max.re - param->min.re, param->max.im - param->min.im);
	if (keycode == 53)
	{
		exit(0);
		mlx_del(param);
	}
	if (keycode == 125)
	{
		param->max.im += fact.im * 0.05;
		param->min.im += fact.im * 0.05;
	}
	if (keycode == 126)
	{
		param->max.im -= fact.im * 0.05;
		param->min.im -= fact.im * 0.05;
	}
	if (keycode == 123)
	{
		param->max.re -= fact.re * 0.05;
		param->min.re -= fact.re * 0.05;
	}
	if (keycode == 124)
	{
		param->max.re += fact.re * 0.05;
		param->min.re += fact.re * 0.05;
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
		param->k = get_complex(
        	4 * ((double)x / WIDTH - 0.5),
        	4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	else if (param->button)
	{
		param->x += (param->mouse.lastx - param->mouse.x) * param->z;
		param->y += (param->mouse.lasty - param->mouse.y) * param->z;
	}
	render(param);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *param)
{
	t_complex	mouse;
	double		fact;
	double		zoom;
	
	if (button == 1)
	{
		param->button = 1;
	}
	mouse = get_complex(
			(double)x / (WIDTH / (param->max.re - param->min.re))
				+ param->min.re,
			(double)y / (HEIGHT / (param->max.im - param->min.im))
				* -1 + param->max.im);
	if (button == 4 || button == 5)
	{
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
