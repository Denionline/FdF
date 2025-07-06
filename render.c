/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/06 19:44:25 by dximenes         ###   ########.fr       */
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
	printf("new_y => (%f) * %f - (%f) * %f = %f\n", (*y), c, (*z), s, new_y);
	printf("new_z => (%f) * %f - (%f) * %f = %f\n", (*y), s, (*z), c, new_z);
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

static void projeta(t_head * head, int x, int y, int z, int * sx, int * sy, int pad, int offx, int offy)
{
	double position_x;
	double position_y;

	position_x = x ;//* head->draw->pad_x;
	position_y = y ;//* head->draw->pad_y;

	// rot_x(&position_y, (double *)&z, head->draw->ang_x);
	// rot_y(&position_x, (double *)&z, head->draw->ang_y);
	*sx = offx + position_x + head->draw->position.x;
	*sy = (offy + position_y - head->draw->position.y) - z;
	if (z > 0)
		*sy -= head->draw->z;
	// ft_printf("%d | %d\n", sy, sx);
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
	while (TRUE)
	{
		mlx_pixel_put(head->vars.mlx, head->vars.win, x0, y0, color);
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
	double ang_x;
	double ang_y;
	double ang_z;

	y = 0;
	while (y < head->map->size.y)
	{
		x = 0;
		while (x < head->map->size.x)
		{
			color = head->map->coordinates[y][x].color;
			z0 = head->map->coordinates[y][x].z;
			ang_x = x * head->draw->pad_x;
			ang_y = y * head->draw->pad_y;
			ang_z = z0;
			rot_x(&ang_y, &ang_z, head->draw->ang_x);
			rot_y(&ang_x, &ang_z, head->draw->ang_y);
			projeta(head, ang_x, ang_y, ang_z, &sx0, &sy0, pad, offx, offy);
			if (x + 1 < head->map->size.x)
			{
				color = head->map->coordinates[y][x + 1].color;
				z1 = head->map->coordinates[y][x + 1].z;
				ang_x = (x + 1) * head->draw->pad_x;
				ang_y = y * head->draw->pad_y;
				ang_z = z1;
				rot_x(&ang_y, &ang_z, head->draw->ang_x);
				rot_y(&ang_x, &ang_z, head->draw->ang_y);
				projeta(head, ang_x, ang_y, ang_z, &sx1, &sy1, pad, offx, offy);
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
				color = head->map->coordinates[y + 1][x].color;
				z1 = head->map->coordinates[y + 1][x].z;
				ang_x = x * head->draw->pad_x;
				ang_y = (y + 1) * head->draw->pad_y;
				ang_z = z1;
				rot_x(&ang_y, &ang_z, head->draw->ang_x);
				rot_y(&ang_x, &ang_z, head->draw->ang_y);
				projeta(head, ang_x, ang_y, ang_z, &sx1, &sy1, pad, offx, offy);
				bresenham(
					head,
					sx0,
					sy0,
					sx1,
					sy1,
					color);
			}
			// ft_printf("(%d, %d) ", sx0, sy0);
			x++;
		}
		// ft_printf("\n");
		y++;
	}
}

void render(t_head * head)
{
	draw_lines(head);
	mlx_loop(head->vars.mlx);
}
