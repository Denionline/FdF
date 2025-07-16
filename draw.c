/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/16 17:02:45 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void get_pixel_values(t_head * head, int y, int x, t_pixel * s)
{
	const t_pixel pixel = head->map->coordinates[y][x];
	const double  center_x = (head->map->size.x) / 2.0;
	const double  center_y = (head->map->size.y) / 2.0;
	const int	  pixel_x = x - center_x;
	const int	  pixel_y = y - center_y;
	int			  pad_z;

	pad_z = 100 / head->map->size.x;
	if (pad_z < 1)
		pad_z = 1;
	s->x = (head->draw->pad_x * head->draw->zoom) * pixel_x;
	s->y = (head->draw->pad_y * head->draw->zoom) * pixel_y;
	s->z = (pad_z * head->draw->zoom) * pixel.z;
	s->color = pixel.color;
}

static t_pixel get_reference(t_head * head, int y, int x)
{
	t_pixel pixel;

	get_pixel_values(head, y, x, &pixel);
	pixel = mat_mult(rotate_x(head), pixel);
	pixel = mat_mult(rotate_y(head), pixel);
	pixel = mat_mult(rotate_z(head), pixel);
	pixel.x += head->draw->start.x + head->draw->position.x;
	pixel.y += head->draw->start.y + head->draw->position.y;
	return (pixel);
}

void draw(t_head * head, int y, int x)
{
	t_pixel s0;
	t_pixel s1;

	s0 = get_reference(head, y, x);
	if (x + 1 < head->map->size.x)
	{
		s1 = get_reference(head, y, x + 1);
		bresenham(head, s0, s1);
	}
	if (y + 1 < head->map->size.y)
	{
		s1 = get_reference(head, y + 1, x);
		bresenham(head, s0, s1);
	}
}