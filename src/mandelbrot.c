/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:49:35 by ibouroum          #+#    #+#             */
/*   Updated: 2019/12/26 00:06:55 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	mandel1(t_ml *p, int i, int j)
{
	int o;

	o = 0;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && o < p->iteration)
	{
		p->tmp = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_r * p->z_i + p->c_i;
		p->z_r = p->tmp;
		o++;
	}
	if (o < p->iteration)
		p->data[j * W + i] = 0x140A58 + (o * 1248518);
}

void		mandel(t_ml *p)
{
	int i;
	int j;
	int o;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			p->c_r = p->minre + ((p->maxre - p->minre) / W) * i + p->deplx;
			p->c_i = p->minim + ((p->maxim - p->minim) / H) * j + p->deply;
			o = 0;
			p->z_r = 0;
			p->z_i = 0;
			mandel1(p, i, j);
			j++;
		}
		i++;
	}
	p->sym = 1;
	mlx_put_image_to_window(p->ptr, p->window, p->img_ptr, 0, 0);
}
