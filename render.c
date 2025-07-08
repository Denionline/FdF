/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/08 12:30:13 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void rot_x(double * y, double * z, double ang)
{
	double c;
	double s;
	double new_y;
	double new_z;

	c = cos(ang);
	s = sin(ang);
	new_y = (*y) * c - (*z) * s;
	new_z = (*y) * s + (*z) * c;
	// printf("new_y => (%f) * %f - (%f) * %f = %f\n", (*y), c, (*z), s, new_y);
	// printf("new_z => (%f) * %f - (%f) * %f = %f\n", (*y), s, (*z), c, new_z);
	*y = new_y;
	*z = new_z;
}
static void rot_y(double * x, double * z, double ang)
{
	double c;
	double s;
	double new_x;
	double new_z;

	c = cos(ang);
	s = sin(ang);
	new_x = (*x) * c + (*z) * s;
	new_z = -(*x) * s + (*z) * c;
	*x = new_x;
	*z = new_z;
}

void proj_persp(double x, double y, double z, int * sx_out, int * sy_out, double fov, int vw, int vh)
{
	const double camera_z = -1000.0;
	double		 fov_rad = fov * PI / 180.0;
	double		 f = (vw / 2.0) / tan(fov_rad / 2.0);

	double z_cam = z - camera_z;
	if (z_cam < 1.0)
		z_cam = 1.0;
	int sx = (int)(x * (f / z_cam) + (vw / 2.0));
	int sy = (int)(-y * (f / z_cam) + (vh / 2.0));

	*sx_out = sx;
	*sy_out = sy;
}

static void bresenham(t_head * head, int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int sx;
	int dy;
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

void rot_2d(double * x, double * y, double ang)
{
	double c;
	double s;
	double new_x;
	double new_y;

	c = cos(ang);
	s = sin(ang);
	new_x = (*x) * c - (*y) * s;
	new_y = (*x) * s + (*y) * c;
	*x = new_x;
	*y = new_y;
}

static void draw_lines(t_head * head)
{
	double ang_x, ang_y, ang_z;
	int	   pad, offx, offy, sx0, sy0, sx1, sy1, z0, z1, x, y, color;
	double center_x = (head->map->size.x - 1) * head->draw->pad_x / 2.0;
	double center_y = (head->map->size.y - 1) * head->draw->pad_y / 2.0;

	pad = head->draw->pad_x;
	center_x = (head->map->size.x - 1) * head->draw->pad_x / 2.0;
	center_y = (head->map->size.y - 1) * head->draw->pad_y / 2.0;
	offx = head->window->size.x / 2;
	offy = head->window->size.y / 2;
	y = 0;
	while (y < head->map->size.y)
	{
		x = 0;
		while (x < head->map->size.x)
		{
			color = head->map->coordinates[y][x].color;
			z0 = head->map->coordinates[y][x].z;
			ang_x = x * head->draw->pad_x - center_x;
			ang_y = y * head->draw->pad_y - center_y;
			ang_z = z0;
			rot_2d(&ang_x, &ang_y, head->draw->ang_2d);
			rot_x(&ang_y, &ang_z, head->draw->ang_x);
			rot_y(&ang_x, &ang_z, head->draw->ang_y);
			proj_persp(ang_x, ang_y, ang_z, &sx0, &sy0, 60, head->window->size.x, head->window->size.y);
			sx0 += head->draw->position.x;
			sy0 -= head->draw->position.y;
			if (x + 1 < head->map->size.x)
			{
				color = head->map->coordinates[y][x + 1].color;
				z1 = head->map->coordinates[y][x + 1].z;
				ang_x = (x + 1) * head->draw->pad_x - center_x;
				ang_y = y * head->draw->pad_y - center_y;
				ang_z = z1;
				rot_2d(&ang_x, &ang_y, head->draw->ang_2d);
				rot_x(&ang_y, &ang_z, head->draw->ang_x);
				rot_y(&ang_x, &ang_z, head->draw->ang_y);
				proj_persp(ang_x, ang_y, ang_z, &sx1, &sy1, 60, head->window->size.x, head->window->size.y);
				sx1 += head->draw->position.x;
				sy1 -= head->draw->position.y;
				bresenham(head, sx0, sy0, sx1, sy1, color);
			}
			if (y + 1 < head->map->size.y)
			{
				color = head->map->coordinates[y + 1][x].color;
				z1 = head->map->coordinates[y + 1][x].z;
				ang_x = x * head->draw->pad_x - center_x;
				ang_y = (y + 1) * head->draw->pad_y - center_y;
				ang_z = z1;
				rot_2d(&ang_x, &ang_y, head->draw->ang_2d);
				rot_x(&ang_y, &ang_z, head->draw->ang_x);
				rot_y(&ang_x, &ang_z, head->draw->ang_y);
				proj_persp(ang_x, ang_y, ang_z, &sx1, &sy1, 60, head->window->size.x, head->window->size.y);
				sx1 += head->draw->position.x;
				sy1 -= head->draw->position.y;
				bresenham(head, sx0, sy0, sx1, sy1, color);
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
