/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 20:26:07 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void projeta(int x, int y, int z, int * sx, int * sy, int pad, int offx, int offy)
{
	*sx = offx + x * pad;
	*sy = offy + y * pad - z;
}

static void bresenham(void * conn, void * win, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2;

	while (1)
	{
		mlx_pixel_put(conn, win, x0, y0, color);
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

void render(t_mlx * mlx)
{
	int pad = 20;
	int offx = mlx->window->vw / 3;
	int offy = mlx->window->vh / 3;
	int x, y;
	int sx0, sy0, sx1, sy1;
	int z0, z1;
	int color;

	y = 0;
	while (y < mlx->map->size_y)
	{
		x = 0;
		while (x < mlx->map->size_x)
		{
			z0 = mlx->map->coordinates[y][x];
			color = (z0 == 0 ? 0x00FF00 : 0x0000FF);
			projeta(x, y, z0, &sx0, &sy0, pad, offx, offy);
			mlx_pixel_put(mlx->connection, mlx->window->content, sx0, sy0, color);
			if (x + 1 < mlx->map->size_x)
			{
				z1 = mlx->map->coordinates[y][x + 1];
				projeta(x + 1, y, z1, &sx1, &sy1, pad, offx, offy);
				bresenham(mlx->connection, mlx->window->content, sx0, sy0, sx1, sy1, color);
			}
			if (y + 1 < mlx->map->size_y)
			{
				z1 = mlx->map->coordinates[y + 1][x];
				projeta(x, y + 1, z1, &sx1, &sy1, pad, offx, offy);
				bresenham(mlx->connection, mlx->window->content, sx0, sy0, sx1, sy1, color);
			}
			x++;
		}
		y++;
	}
	mlx_loop(mlx->connection);
}
