/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/15 10:23:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void get_pixel_values(t_head * head, int y, int x, t_pixel * s)
{
	const t_pixel pixel = head->map->coordinates[y][x];
	const double  center_x = (head->map->size.x - 1) / 2.0;
	const double  center_y = (head->map->size.y - 1) / 2.0;
	const int	  px = x - center_x;
	const int	  py = y - center_y;

	s->x = (head->draw->pad_x * head->draw->zoom) * px;
	s->y = (head->draw->pad_y * head->draw->zoom) * py;
	s->z = pixel.z * head->draw->zoom;
	s->color = pixel.color;
}

static t_pixel project_iso(t_head * head, int y, int x)
{
	t_pixel pixel;

	get_pixel_values(head, y, x, &pixel);
	pixel = mat_mult(rotate_x(head), pixel);
	pixel = mat_mult(rotate_y(head), pixel);
	pixel = mat_mult(rotate_z(head), pixel);
	pixel.x += head->draw->start.x;
	pixel.y += head->draw->start.y;
	return (pixel);
}

void draw(t_head * head, int y, int x)
{
	t_pixel point;
	t_pixel line;

	point = project_iso(head, y, x);
	if (x + 1 < head->map->size.x)
	{
		line = project_iso(head, y, x + 1);
		bresenham(head, point, line);
	}
	if (y + 1 < head->map->size.y)
	{
		line = project_iso(head, y + 1, x);
		bresenham(head, point, line);
	}
}