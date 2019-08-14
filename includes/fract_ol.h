/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzina <kzina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:30:16 by kzina             #+#    #+#             */
/*   Updated: 2019/08/14 19:03:26 by kzina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define WIDTH 2000
# define HEIGHT 1400

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

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_image		*menu;
	t_cord		**cord;
	int			coloms;
	int			lines;
	int			fact;
	int			dx;
	int			dy;
	int			dz;
	double		x;
	double		y;
	int			color1;
	int			color2;
	int			color3;
	int			mid;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	t_factorial	type;
	int			m;
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
void			controls(t_mlx *param);
void			algorithm_fract(t_mlx *win, int (*f)(t_mlx *));
int				julia(t_mlx *win);
void			mlx_del(t_mlx *win);

#endif
