/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:54:15 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/18 16:31:12 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init_bresenham(t_bresenham * brese, t_pixel s0, t_pixel s1)
{
	brese->delta.x = absolute(s1.x - s0.x);
	brese->delta.y = -absolute(s1.y - s0.y);
	brese->direction.x = 1;
	if (s0.x > s1.x)
		brese->direction.x = -1;
	brese->direction.y = 1;
	if (s0.y > s1.y)
		brese->direction.y = -1;
	brese->base_decision = brese->delta.x + brese->delta.y;
}

static void calc_decision(int * err_curr, int * pos, int sum_err, int step)
{
	*err_curr += sum_err;
	*pos += step;
}

void bresenham(t_head * h, t_pixel s0, t_pixel s1)
{
	t_bresenham b;
	int			steps;
	int			step;
	int			color;

	init_bresenham(&b, s0, s1);
	steps = absolute(b.delta.x);
	if (absolute(b.delta.x) < absolute(b.delta.y))
		steps = absolute(b.delta.y);
	step = 0;
	while (s0.x != s1.x || s0.y != s1.y)
	{
		color = get_color_between(s0.color, s1.color, step, steps);
		put_pixel_image(&h->draw->image, s0.x, s0.y, color);
		b.decision = 2 * b.base_decision;
		if (b.decision >= b.delta.y)
			calc_decision(&b.base_decision, &s0.x, b.delta.y, b.direction.x);
		if (b.decision <= b.delta.x)
			calc_decision(&b.base_decision, &s0.y, b.delta.x, b.direction.y);
		step++;
	}
}
