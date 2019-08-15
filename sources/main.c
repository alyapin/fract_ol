/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:44 by kzina             #+#    #+#             */
/*   Updated: 2019/08/15 16:47:26 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

typedef struct	s_color
{
	int8_t x[4];
} 				t_color;

int		main(int ac, char **av)
{
	t_mlx 	*win;

	if (ac != 2)
	{
		ft_putendl("usage: ./fract_ol [type_fractol]");
		return (1);
	}
	if ((win = init_mlx()) == NULL)
		ft_putendl("error of initialization");
	if (ft_strequ(av[1], "Mandelbrot") == 1)
		win->formula = mandelbrot;
	if (ft_strequ(av[1], "Julia") == 1)
		win->formula = julia;
	controls(win);
	render(win);
	mlx_loop(win->mlx);
	return (0);
}
