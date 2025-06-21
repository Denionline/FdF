/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/21 18:42:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void draw_lines(t_mlx * mlx)
{
}

static void draw_points(t_mlx * mlx, int x, int y, int pad)
{
	if (mlx->map->coordinates[y][x] == 0)
		mlx_pixel_put(
			mlx->connection,
			mlx->window->content,
			x * pad,
			y * pad,
			0x00ff00);
	else
		mlx_pixel_put(
			mlx->connection,
			mlx->window->content,
			x * pad,
			y * pad,
			0x0000ff);
}

void render(t_mlx * mlx)
{
	int pad;
	int x;
	int y;

	pad = 30;
	y = 0;
	while (y < mlx->map->size_y)
	{
		x = 0;
		while (x < mlx->map->size_x)
		{
			draw_points(mlx, x, y, pad);
			x++;
		}
		y++;
	}
	mlx_loop(mlx->connection);
}
