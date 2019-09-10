/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:50:32 by kzina             #+#    #+#             */
/*   Updated: 2019/09/10 18:37:19 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int		move_via_keyboard(int keycode, t_mlx *param)
{
	t_complex fact;

	fact = get_complex(param->max.re - param->min.re,
		param->max.im - param->min.im);
	if (keycode == 125)
	{
		param->max.im -= fact.im * 0.02;
		param->min.im -= fact.im * 0.02;
	}
	if (keycode == 126)
	{
		param->max.im += fact.im * 0.02;
		param->min.im += fact.im * 0.02;
	}
	if (keycode == 123)
	{
		param->max.re -= fact.re * 0.02;
		param->min.re -= fact.re * 0.02;
	}
	if (keycode == 124)
	{
		param->max.re += fact.re * 0.02;
		param->min.re += fact.re * 0.02;
	}
	return (0);
}

int		change_fractol(int keycode, t_mlx *param)
{
	if (keycode == 18 && param->formula != mandelbrot)
		param->formula = mandelbrot;
	else if (keycode == 19 && param->formula != julia)
		param->formula = julia;
	else if (keycode == 20 && param->formula != mandelbar)
		param->formula = mandelbar;
	else if (keycode == 21 && param->formula != mandelbrot_perp)
		param->formula = mandelbrot_perp;
	else if (keycode == 23 && param->formula != cubic_mandelbar)
		param->formula = cubic_mandelbar;
	else if (keycode == 22 && param->formula != heart_mandelbrot)
		param->formula = heart_mandelbrot;
	else if (keycode == 26 && param->formula != buffalo)
		param->formula = buffalo;
	else if (keycode == 28 && param->formula != quasi_perpendicular_3rd)
		param->formula = quasi_perpendicular_3rd;
	reset_mlx(param);
	return (0);
}

int		key_release(int keycode, t_mlx *param)
{
	if (keycode == 4)
		param->help_button = 0;
	render(param);
	return (0);
}

int		key_press(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		exit(0);
		mlx_del(&param);
	}
	if (keycode == 78 || keycode == 69)
	{
		if (keycode == 78)
			if (param->max_iter > 0)
				param->max_iter--;
		if (keycode == 69)
			param->max_iter++;
	}
	if (keycode == 4)
		param->help_button = 1;
	if (keycode == 67)
		param->max_iter = 50;
	if (keycode == 125 || keycode == 126 || keycode == 123 || keycode == 124)
		move_via_keyboard(keycode, param);
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21 ||
	keycode == 22 || keycode == 23 || keycode == 26 || keycode == 28)
		change_fractol(keycode, param);
	render(param);
	return (0);
}
