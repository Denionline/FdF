/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/05 19:00:29 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void projeta(t_head * head, int x, int y, int z, int * sx, int * sy, int pad, int offx, int offy)
{
	int position_y;
	int position_x;
	int ang_x;
	int ang_y;

	position_y = head->draw->position.y;
	position_x = head->draw->position.x;
	*sx = offx + x * head->draw->pad_x + position_x;
	*sy = (offy + y * head->draw->pad_y - position_y) - z;
	if (z > 0)
		*sy -= head->draw->z;
}

static void bresenham(t_head * head, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while (TRUE)
	{
		mlx_pixel_put(head->vars.mlx, head->vars.win, x0 + , y0, color);
		if (x0 == x1 && y0 == y1)
			break;
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

static void draw_lines(t_head * head)
{
	int pad = head->draw->pad_x;
	int offx = (head->window->size.x / 2) - ((head->map->size.x * pad) / 2);
	int offy = (head->window->size.y / 2) - ((head->map->size.y * pad) / 2);
	int x, y;
	int sx0, sy0, sx1, sy1;
	int z0, z1;
	int color;

	y = 0;
	while (y < head->map->size.y)
	{
		x = 0;
		while (x < head->map->size.x)
		{
			z0 = head->map->coordinates[y][x].z;
			color = head->map->coordinates[y][x].color;
			projeta(head, x, y, z0, &sx0, &sy0, pad, offx, offy);
			mlx_pixel_put(
				head->vars.mlx,
				head->vars.win,
				sx0,
				sy0,
				color);
			if (x + 1 < head->map->size.x)
			{
				z1 = head->map->coordinates[y][x + 1].z;
				projeta(head, x + 1, y, z1, &sx1, &sy1, pad, offx, offy);
				color = head->map->coordinates[y][x + 1].color;
				bresenham(
					head,
					sx0,
					sy0,
					sx1,
					sy1,
					color);
			}
			if (y + 1 < head->map->size.y)
			{
				z1 = head->map->coordinates[y + 1][x].z;
				projeta(head, x, y + 1, z1, &sx1, &sy1, pad, offx, offy);
				color = head->map->coordinates[y + 1][x].color;
				bresenham(
					head,
					sx0,
					sy0,
					sx1,
					sy1,
					color);
			}
			x++;
		}
		y++;
	}
}

void render(t_head * head)
{
	draw_lines(head);
	mlx_loop(head->vars.mlx);
}
