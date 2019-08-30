/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:44 by kzina             #+#    #+#             */
/*   Updated: 2019/08/30 19:31:29 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	multi_window(t_mlx *win, char *str)
{
	if ((win = init_mlx()) == NULL)
		ft_putendl("error of initialization");
	if (ft_strequ(str, "Mandelbrot") == 1)
		win->formula = mandelbrot;
	if (ft_strequ(str, "Julia") == 1)
		win->formula = julia;
	if (ft_strequ(str, "Mandelbar") == 1)
		win->formula = mandelbar;
	controls(win);
	render(win);
	mlx_loop(win->mlx);
}

int		main(int ac, char **av)
{
	t_mlx 	**win;
	pid_t	pid;

	pid = 1;
	(void)av;
	win = (t_mlx **)ft_memalloc(sizeof(t_mlx*) * 2);
	if (ac < 2 || ac > 3)
	{
		ft_putendl("usage: ./fract_ol [type_fractol]");
		return (1);
	}
	if (ac == 3)
		pid = fork();
	multi_window(win[pid == 0 ? 1 : 0], av[pid == 0 ? 2 : 1]);
	return (0);
}
