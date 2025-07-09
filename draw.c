/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/09 12:24:23 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void calc_axis(t_draw * drw, int y, int x, t_pixel * s)
{
	s->y = (drw->start.y + drw->pad_y * y) - s->z;
	s->x = drw->start.x + drw->pad_x * x;
}

void draw(t_head * head, int y, int x)
{
	head->draw->s0.z = head->map->coordinates[y][x].z;
	head->draw->s0.color = head->map->coordinates[y][x].color;
	calc_axis(head->draw, y, x, &head->draw->s0);
	if (x + 1 < head->map->size.x)
	{
		head->draw->s1.z = head->map->coordinates[y][x + 1].z;
		head->draw->s1.color = head->map->coordinates[y][x + 1].color;
		calc_axis(head->draw, y, x + 1, &head->draw->s1);
		bresenham(head, head->draw->s0, head->draw->s1);
	}
	if (y + 1 < head->map->size.y)
	{
		head->draw->s1.z = head->map->coordinates[y + 1][x].z;
		head->draw->s1.color = head->map->coordinates[y + 1][x].color;
		calc_axis(head->draw, y + 1, x, &head->draw->s1);
		bresenham(head, head->draw->s0, head->draw->s1);
	}
}