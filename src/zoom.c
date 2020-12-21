/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 00:04:31 by ibouroum          #+#    #+#             */
/*   Updated: 2019/12/26 00:04:32 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	applyzoom(t_ml *e, double mousere, double mouseim)
{
	e->minre = interpolate(mousere, e->minre, 0.95);
	e->minim = interpolate(mouseim, e->minim, 0.95);
	e->maxre = interpolate(mousere, e->maxre, 0.95);
	e->maxim = interpolate(mouseim, e->maxim, 0.95);
}

void	applydzoom(t_ml *e, double mousere, double mouseim)
{
	e->minre = interpolate(mousere, e->minre, 1.01);
	e->minim = interpolate(mouseim, e->minim, 1.01);
	e->maxre = interpolate(mousere, e->maxre, 1.01);
	e->maxim = interpolate(mouseim, e->maxim, 1.01);
}
