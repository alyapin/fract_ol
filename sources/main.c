/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:44 by kzina             #+#    #+#             */
/*   Updated: 2019/09/10 17:31:12 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	usage(void)
{
	ft_putendl("usage: ./fract_ol [type_fractol] [additional fractol]");
	ft_putendl("\t1 -------- Mandelbrot");
	ft_putendl("\t2 -------- Julia");
	ft_putendl("\t3 -------- Mandelbar");
	ft_putendl("\t4 -------- Perp Mandelbrot");
	ft_putendl("\t5 -------- Cubic Mandelbar");
	ft_putendl("\t6 -------- Heart Mandelbrot");
	ft_putendl("\t7 -------- Buffalo");
	ft_putendl("\t8 -------- Quasi Perp 3rd");
}

int		choose_fractol(t_mlx *win[2], char *str, int i)
{
	if (ft_strequ(str, "Mandelbrot") == 1 || ft_strequ(str, "1") == 1)
		win[i]->formula = mandelbrot;
	else if (ft_strequ(str, "Julia") == 1 || ft_strequ(str, "2") == 1)
		win[i]->formula = julia;
	else if (ft_strequ(str, "Mandelbar") == 1 || ft_strequ(str, "3") == 1)
		win[i]->formula = mandelbar;
	else if (ft_strequ(str, "Perp Mandelbrot") == 1 || ft_strequ(str, "4") == 1)
		win[i]->formula = mandelbrot_perp;
	else if (ft_strequ(str, "Cubic Mandelbar") == 1 || ft_strequ(str, "5") == 1)
		win[i]->formula = cubic_mandelbar;
	else if (ft_strequ(str, "Heart Mandelbrot") == 1
		|| ft_strequ(str, "6") == 1)
		win[i]->formula = heart_mandelbrot;
	else if (ft_strequ(str, "Buffalo") == 1 || ft_strequ(str, "7") == 1)
		win[i]->formula = buffalo;
	else if (ft_strequ(str, "Quasi Perp 3rd") == 1 || ft_strequ(str, "8") == 1)
		win[i]->formula = quasi_perpendicular_3rd;
	else
	{
		mlx_del(win);
		ft_putendl("wrong argument(s)");
		return (1);
	}
	return (0);
}

int		multi_window(char **str, int ac)
{
	t_mlx	*win[2];
	void	*mlx;
	int		i;

	i = -1;
	mlx = mlx_init();
	while (++i < ac - 1)
	{
		if ((win[i] = init_mlx(mlx)) == NULL)
			ft_putendl("error of initialization");
		if (choose_fractol(win, str[i + 1], i))
			return (1);
		controls(win[i]);
		render(win[i]);
	}
	mlx_loop(mlx);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
	{
		usage();
		return (1);
	}
	multi_window(av, ac);
	return (0);
}
