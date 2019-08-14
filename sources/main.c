/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:44 by kzina             #+#    #+#             */
/*   Updated: 2019/08/14 18:51:20 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fract_ol.h"
#include "mlx.h"

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
	if (ft_strequ(av[1], "Mandelbroot") == 1)
		win->type = Mandelbrot;
	if (ft_strequ(av[1], "Julia") == 1)
		win->type = Julia;
	controls(win);
	render(win);
	mlx_loop(win->mlx);
	return (0);
}
