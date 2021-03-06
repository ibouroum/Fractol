/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:49:05 by ibouroum          #+#    #+#             */
/*   Updated: 2019/12/24 15:49:06 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# define W 800
# define H 800
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"

typedef struct		s_ml
{
	int			a;
	int			b;
	int			c;
	void		*ptr;
	void		*window;
	void		*img_ptr;
	int			*data;
	int			symjulia;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		zoom;
	int			iteration;
	double		maxre;
	double		mousere;
	double		mouseim;
	double		minre;
	double		maxim;
	double		minim;
	double		deplx;
	double		deply;
	char		*name;
	int			sym;
	int			mousewheel;
}					t_ml;

void				mandelbrot(t_ml *p);
void				ship(t_ml *p);
void				julia(t_ml *p);
int					ft_strcmp(const char *s1, const char *s2);
void				mm(t_ml *p);
void				change_color(int *data, t_ml *p);
void				applyzoom(t_ml *e, double mousere, double mouseim);
double				interpolate(double start, double end, double interpolation);
void				applydzoom(t_ml *e, double mousere, double mouseim);
void				error();
void				menu(char *s, t_ml *p);
void				mandel(t_ml *params);
void				draw(t_ml p);
void				burningship(t_ml *params);
void				julia(t_ml *params);
void				mm(t_ml *params);
void				change_fracts(t_ml *p);
void				infos(t_ml p);
void				destroy_img(t_ml *p);
void				intialiser_re_im(t_ml *p);
void				fract(t_ml *p, int key);
void				lets_go(t_ml *p);
void				ft_itir(int key, t_ml *p);

#endif

