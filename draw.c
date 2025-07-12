/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/12 18:54:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void calc_axis(t_head * head, int y, int x, t_pixel * s)
{
	const t_pixel pixel = head->map->coordinates[y][x];
	const double  center_x = (head->map->size.x - 1) / 2.0;
	const double  center_y = (head->map->size.y - 1) / 2.0;
	const int	  px = x - center_x;
	const int	  py = y - center_y;

	s->x = head->draw->pad_x * px;
	s->y = head->draw->pad_y * py - pixel.z;
	s->z = pixel.z;
	s->color = pixel.color;
}

static void draw_lines(t_head *head, int y, int x, t_pixel *pixel)
{
	double projection[3][3];
	double z;

	calc_axis(head, y, x, pixel);
	*pixel = mat_mult(rotate_x(head), *pixel);
	*pixel = mat_mult(rotate_y(head), *pixel);
	*pixel = mat_mult(rotate_z(head), *pixel);
	z = 1 / (head->draw->distance - pixel->z);
	ft_memcpy(projection, (double[3][3]){\
		{z, 0, 0},\
		{0, z, 0},\
		{0, 0, z},\
	}, sizeof(double) * 9);
	*pixel = mat_mult(projection, *pixel);
	pixel->x += head->draw->start.x;
	pixel->y += head->draw->start.y;
	bresenham(head, head->draw->s0, *pixel);
}

void draw(t_head * head, int y, int x)
{
	draw_lines(head, y, x, &head->draw->s0);
	if (x + 1 < head->map->size.x)
		draw_lines(head, y, x + 1, &head->draw->s1);
	if (y + 1 < head->map->size.y)
		draw_lines(head, y + 1, x, &head->draw->s1);
}
