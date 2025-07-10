/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/10 16:54:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void calc_axis(t_head * head, int y, int x, t_pixel * s)
{
	const t_pixel pixel = head->map->coordinates[y][x];
	const double  center_x = (head->map->size.x - 1) / 2.0;
	const double  center_y = (head->map->size.y - 1) / 2.0;
	const int	  px = x - center_x;
	const int	  py = y - center_y;

	s->x = head->draw->pad_x * px;
	s->y = head->draw->pad_y * py - pixel.z;
	s->z = pixel.z;
	s->color = pixel.color;
}

void draw(t_head * head, int y, int x)
{
	calc_axis(head, y, x, &head->draw->s0);
	head->draw->s0 = mat_mult(rotate_x(head), head->draw->s0);
	head->draw->s0 = mat_mult(rotate_y(head), head->draw->s0);
	head->draw->s0 = mat_mult(rotate_z(head), head->draw->s0);
	head->draw->s0.x += head->draw->start.x;
	head->draw->s0.y += head->draw->start.y;
	if (x + 1 < head->map->size.x)
	{
		calc_axis(head, y, x + 1, &head->draw->s1);
		head->draw->s1 = mat_mult(rotate_x(head), head->draw->s1);
		head->draw->s1 = mat_mult(rotate_y(head), head->draw->s1);
		head->draw->s1 = mat_mult(rotate_z(head), head->draw->s1);
		head->draw->s1.x += head->draw->start.x;
		head->draw->s1.y += head->draw->start.y;
		bresenham(head, head->draw->s0, head->draw->s1);
	}
	if (y + 1 < head->map->size.y)
	{
		calc_axis(head, y + 1, x, &head->draw->s1);
		head->draw->s1 = mat_mult(rotate_x(head), head->draw->s1);
		head->draw->s1 = mat_mult(rotate_y(head), head->draw->s1);
		head->draw->s1 = mat_mult(rotate_z(head), head->draw->s1);
		head->draw->s1.x += head->draw->start.x;
		head->draw->s1.y += head->draw->start.y;
		bresenham(head, head->draw->s0, head->draw->s1);
	}
}
