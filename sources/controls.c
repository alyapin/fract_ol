/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 18:48:05 by kzina             #+#    #+#             */
/*   Updated: 2019/08/14 19:03:12 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include "../libft/libft.h"
#include "mlx.h"

int		key_press(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		exit(0);
		mlx_del(param);
	}
	if (keycode == 125)
		param->dx -= 10;
	if (keycode == 126)
		param->dx += 10;
	if (keycode == 123)
		param->dy += 10;
	if (keycode == 124)
		param->dy -= 10;
	if (keycode == 89 || keycode == 91)
	{
		if (keycode == 89)
		{
			param->k.re -= 0.05;
			param->k.im -= 0.05;
		}
		if (keycode == 91)
		{
			param->k.re += 0.05;
			param->k.im += 0.05;
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
	render(param);
	return (0);
}

void	controls(t_mlx *param)
{
	mlx_hook(param->win, 2, 0, key_press, param);
}
