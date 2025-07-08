/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/08 18:15:01 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void bresenham(t_head * head, int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	sx = 1;
	if (x0 > x1)
		sx = -1;
	dy = -abs(y1 - y0);
	sy = 1;
	if (y0 > y1)
		sy = -1;
	err = dx + dy;
	printf("[%d][%d] => [%d][%d]\n", y0, x0, y1, x1);
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(head->vars.mlx, head->vars.win, x0, y0, color);
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static void calc_axis(t_draw * drw, int y, int x, t_axis * s)
{
	s->y = (drw->start.y + drw->pad_y * y) - s->z;
	s->x = drw->start.x + drw->pad_x * x;
}

static void draw(t_head * head, int y, int x)
{
	head->draw->s0.z = head->map->coordinates[y][x].z;
	head->draw->s0.color = head->map->coordinates[y][x].color;
	calc_axis(head->draw, y, x, &head->draw->s0);
	if (x + 1 < head->map->size.x)
	{
		head->draw->s1.z = head->map->coordinates[y][x + 1].z;
		head->draw->s1.color = head->map->coordinates[y][x + 1].color;
		calc_axis(head->draw, y, x + 1, &head->draw->s1);
		bresenham(head, head->draw->s1.x, head->draw->s1.y, head->draw->s1.x, head->draw->s1.y, head->draw->s1.color);
	}
	if (y + 1 < head->map->size.y)
	{
		head->draw->s1.z = head->map->coordinates[y + 1][x].z;
		head->draw->s1.color = head->map->coordinates[y + 1][x].color;
		calc_axis(head->draw, y + 1, x, &head->draw->s1);
		bresenham(head, head->draw->s1.x, head->draw->s1.y, head->draw->s1.x, head->draw->s1.y, head->draw->s1.color);
	}
}

void render(t_head * head)
{
	int y;
	int x;

	head->draw->start.x = (head->window->size.x / 2) - (head->map->size.x / 2);
	head->draw->start.y = (head->window->size.y / 2) - (head->map->size.y / 2);
	y = 0;
	while (y < head->map->size.y)
	{
		x = 0;
		while (x < head->map->size.x)
		{
			draw(head, y, x);
			x++;
		}
		y++;
	}
	// mat_mult(head->draw->projection, );
	mlx_loop(head->vars.mlx);
}
