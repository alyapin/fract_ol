/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:30:16 by kzina             #+#    #+#             */
/*   Updated: 2019/09/05 17:59:33 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include "mlx.h"
# include <math.h>
# include <sys/types.h>
# include "../libft/libft.h"
# define WIDTH 1200
# define HEIGHT 1200
# define NUM_THREADS 10
# define ABS(x) x > 0 ? x : -x

typedef enum
{
	Mandelbrot,
	Julia
}				t_factorial;

typedef struct	s_image
{
	void		*mlx;
	void		*w;
	int			*image;
	int			*data_address;
	int			bpp;
	int			line_size;
	int			endian;
}				t_image;

typedef	struct	s_cord
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_cord;

typedef	struct	s_res
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_res;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef	struct	s_mouse
{
	int			lastx;
	int			lasty;
	int			x;
	id_t		y;
}				t_mouse;


typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_image		*menu;
	int			dx;
	int			dy;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	t_complex	fact;
	t_mouse		mouse;
	int			(*formula)(struct s_mlx *fractol);
	int			m;
	int			start;
	int			finish;
	double		shift;
	int			button;
	double		z;
	int			x;
	int			y;
}				t_mlx;

t_mlx			*init_mlx(void);
t_complex		get_complx(double re, double im);
t_complex		get_fact(t_complex min, t_complex max);
double			size_vector(t_complex z);
t_complex		mandel(t_complex z, t_complex c);
void			render(t_mlx *win);
int				mandelbrot(t_mlx *win);
t_image			*init_img(t_mlx *win);
int				color(int iter, t_mlx *win);
void			controls(t_mlx *param, pid_t pid);
void			algorithm_fract(t_mlx *win);
int				julia(t_mlx *win);
int				mandelbar(t_mlx *win);
int				mandelbrot_perp(t_mlx *win);
void			mlx_del(t_mlx *win);
double			my_fabs(double x);

#endif
