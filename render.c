/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/24 22:22:19 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void projeta(int x, int y, int z, int * sx, int * sy, int pad, int offx, int offy)
{
	*sx = offx + x * pad;
	*sy = offy + y * pad;
}

void dda(t_mlx *mlx, int X0, int Y0, int X1, int Y1, int color)
{
	// calculate dx & dy
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	// calculate steps required for generating pixels
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// calculate increment in x & y for each steps
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	// Put pixel for each step
	float x = X0;
	float y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(mlx->connection, mlx->window->content, x, y, color);
		x += Xinc;
		y += Yinc;
	}
}

void render(t_mlx * mlx)
{
	int pad = 20;
	int offx = mlx->window->size.x / 3;
	int offy = mlx->window->size.y / 3;
	int x, y;
	int sx0, sy0, sx1, sy1;
	int z0, z1;
	int color;

	y = 0;
	while (y < mlx->map->size.y)
	{
		x = 0;
		while (x < mlx->map->size.x)
		{
			z0 = mlx->map->coordinates[y][x];
			color = (z0 == 0 ? 0x00FF00 : 0x0000FF);

			// projeta o ponto atual
			projeta(x, y, z0, &sx0, &sy0, pad, offx, offy);

			// vizinho à direita
			if (x + 1 < mlx->map->size.x)
			{
				z1 = mlx->map->coordinates[y][x + 1];
				projeta(x + 1, y, z1, &sx1, &sy1, pad, offx, offy);
				dda(mlx, sx0, sy0, sx1, sy1, color);
			}
			// vizinho abaixo
			if (y + 1 < mlx->map->size.y)
			{
				z1 = mlx->map->coordinates[y + 1][x];
				projeta(x, y + 1, z1, &sx1, &sy1, pad, offx, offy);
				dda(mlx, sx0, sy0, sx1, sy1, color);
			}
			x++;
		}
		y++;
	}
	mlx_loop(mlx->connection);
}
