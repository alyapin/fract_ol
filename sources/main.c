/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:44 by kzina             #+#    #+#             */
/*   Updated: 2019/09/05 15:41:37 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	multi_window(t_mlx *win, char *str, pid_t pid)
{
	if ((win = init_mlx()) == NULL)
		ft_putendl("error of initialization");
	if (ft_strequ(str, "Mandelbrot") == 1 || ft_strequ(str, "1") == 1)
		win->formula = mandelbrot;
	else if (ft_strequ(str, "Julia") == 1 || ft_strequ(str, "2") == 1)
		win->formula = julia;
	else if (ft_strequ(str, "Mandelbar") == 1 || ft_strequ(str, "3") == 1)
		win->formula = mandelbar;
	else if (ft_strequ(str, "Perpendicular Mandelbrot") == 1 || ft_strequ(str, "4") == 1)
		win->formula = mandelbrot_perp;
	else
	{
		mlx_del(win);
		ft_putendl("wrong argument");
		return ;
	}
	controls(win, pid);
	render(win);
	mlx_loop(win->mlx);
}

int		main(int ac, char **av)
{
	t_mlx 	**win;
	pid_t	pid;

	pid = 1;
	win = (t_mlx **)ft_memalloc(sizeof(t_mlx*) * 2);
	if (ac < 2 || ac > 3)
	{
		ft_putendl("usage: ./fract_ol [type_fractol]");
		return (1);
	}
	if (ac == 3)
		pid = fork();
	printf("everything okey pid is %d\n", pid);
	multi_window(win[pid == 0 ? 1 : 0], av[pid == 0 ? 2 : 1], pid);
	return (0);
}
