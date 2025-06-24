/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/24 22:58:50 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void draw_lines(t_mlx * mlx, t_draw draw, int x1, int y1)
{
	float increment_x;
	float increment_y;
	int	  distance_x;
	int	  distance_y;
	int	  pixels;
	float x;
	float y;
	int	  i;

	distance_x = abs(x1 - draw.dot.x);
	distance_y = abs(y1 - draw.dot.y);
	pixels = distance_x;
	if (distance_y > distance_x)
		pixels = distance_y;
	increment_x = distance_x / pixels;
	increment_y = distance_y / pixels;
	x = draw.dot.x;
	y = draw.dot.y;
	while (i <= pixels)
	{
		mlx_pixel_put(mlx->connection, mlx->window->content, x * draw.pad, y * draw.pad, draw.color);
		x += increment_x;
		y += increment_y;
	}
}

static void draw_points(t_mlx * mlx, t_draw draw)
{
	int y;
	int x;

	y = draw.dot.y;
	x = draw.dot.x;
	if (mlx->map->coordinates[y][x] == 0)
		mlx_pixel_put(
			mlx->connection,
			mlx->window->content,
			x * draw.pad,
			y * draw.pad,
			0x00ff00);
	else
		mlx_pixel_put(
			mlx->connection,
			mlx->window->content,
			x * draw.pad,
			y * draw.pad,
			0x0000ff);
}

void render(t_mlx * mlx)
{
	t_draw draw;
	draw.pad = 30;

	draw.dot.y = 0;
	while (draw.dot.y < mlx->map->size.y)
	{
		draw.dot.x = 0;
		while (draw.dot.x < mlx->map->size.x)
		{
			draw_points(mlx, draw);
			draw_lines(mlx, draw, draw.dot.x + 1, draw.dot.y);
			draw_lines(mlx, draw, draw.dot.x, draw.dot.y + 1);
			draw.dot.x++;
		}
		draw.dot.y++;
	}
	mlx_loop(mlx->connection);
}
