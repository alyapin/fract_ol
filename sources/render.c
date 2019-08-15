/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 18:24:36 by kzina             #+#    #+#             */
/*   Updated: 2019/08/15 17:49:11 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	render(t_mlx *win)
{
	pthread_t	threads[NUM_THREADS];
	t_mlx		fact[NUM_THREADS];
	int			i;

	i = 0;
	ft_bzero(win->img->data_address, WIDTH * HEIGHT * 4);
	while (i < NUM_THREADS)
	{
		fact[i] = *win;
		fact[i].start = i * (HEIGHT / NUM_THREADS);
		fact[i].finish = (i + 1) * (HEIGHT / NUM_THREADS);
		if (pthread_create(&threads[i], NULL, (void *(*)(void *))algorithm_fract, (void *)&fact[i]))
		{
			ft_putendl("thread error");
			return ;
		}
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			ft_putendl("join error");
	algorithm_fract(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img->image, 0, 0);
}
