/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:01:18 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/01 14:23:28 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void get_axis(t_draw * drw, int y, int x, int ** coord)
{
	if (y == drw->_.y && x == drw->_.x)
	{
		drw->s0.x = drw->off.x + x * drw->pad;
		drw->s0.y = drw->off.y + y * drw->pad - coord[y][x];
		return;
	}
	drw->s1.x = drw->off.x + x * drw->pad;
	drw->s1.y = drw->off.y + y * drw->pad - coord[y][x];
}

static void draw_lines(t_mlx * mlx, t_draw * drw)
{
	int err;
	int dx;
	int dy;
	int x;
	int y;

	dx = drw->s1.x - drw->s0.x;
	dy = drw->s1.y - drw->s0.y;
	y = drw->s0.y;
	x = drw->s0.x;
	err = dy - (dx / 2);
	while (x < drw->s1.x)
	{
		mlx_pixel_put(mlx->connection, mlx->window->_, x, y, 0x0000FF);
		if (err < 0)
			err += dy;
		else
		{
			err += (dy - dx);
			y++;
		}
		x++;
	}
}

void draw(t_mlx * mlx, t_draw * drw)
{
	get_axis(drw, drw->_.y, drw->_.x, mlx->map->coordinates);
	if (drw->_.x + 1 < mlx->map->size.x)
	{
		get_axis(drw, drw->_.y, drw->_.x + 1, mlx->map->coordinates);
		draw_lines(mlx, drw);
	}
	if (drw->_.y + 1 < mlx->map->size.y)
	{
		get_axis(drw, drw->_.y + 1, drw->_.x, mlx->map->coordinates);
		draw_lines(mlx, drw);
	}
}
// static void draw_lines(t_mlx * mlx, t_draw * drw)
// {
// 	float x_inc;
// 	float y_inc;
// 	float dx;
// 	float dy;
// 	float y;
// 	float x;
// 	int	  steps;

// 	dx = drw->s1.x - drw->s0.x;
// 	dy = drw->s1.y - drw->s0.y;
// 	steps = abs(dy);
// 	if (abs(dx) > abs(dy))
// 		steps = abs(dx);
// 	x_inc = dx / steps;
// 	y_inc = dy / steps;
// 	x = drw->s0.x;
// 	y = drw->s0.y;
// 	ft_printf("Draw lines [%d]\n", steps);
// 	ft_printf("x: %d & x_inc: %d | y: %d & y_inc: %d \n", x + 0.5, x_inc, y + 0.5, y_inc);
// 	while (steps--)
// 	{
// 		mlx_pixel_put(mlx->connection, mlx->window->_, (int)(x + 0.5), (int)(y + 0.5), 0x0000FF);
// 		x += x_inc;
// 		y += y_inc;
// 	}
// }