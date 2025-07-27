/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 15:27:43 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	get_pixel_values(t_head *head, int y, int x, t_pixel *s)
{
	const t_pixel	point = head->map->points[y][x];
	t_double_axis	center;
	t_pixel			pixel;
	double			big_side;
	double			value;

	center.x = (head->map->size.x) / 2.0;
	center.y = (head->map->size.y) / 2.0;
	pixel.x = x - center.x;
	pixel.y = y - center.y;
	big_side = head->map->size.y;
	if (head->map->size.x > head->map->size.y)
		big_side = head->map->size.x;
	value = (big_side - SMALLEST_SIZE) / (BIGGEST_SIZE - SMALLEST_SIZE);
	if (value < 0.0)
		value = 0.0;
	if (value > 1.0)
		value = 1.0;
	pixel.z = MAX_PADZ + (MIN_PADZ - MAX_PADZ) * value;
	s->z = pixel.z * head->draw->zoom * point.z;
	s->x = (head->draw->pad.x * head->draw->zoom) * pixel.x;
	s->y = (head->draw->pad.y * head->draw->zoom) * pixel.y;
	s->color = point.color;
}

static t_pixel	get_reference(t_head *head, int y, int x)
{
	int		ref_pos_x;
	int		ref_pos_y;
	t_pixel	pixel;

	get_pixel_values(head, y, x, &pixel);
	pixel = mat_mult(rotate_x(head), pixel);
	pixel = mat_mult(rotate_y(head), pixel);
	pixel = mat_mult(rotate_z(head), pixel);
	ref_pos_x = head->draw->position.x * (1 / head->draw->zoom);
	ref_pos_y = head->draw->position.y * (1 / head->draw->zoom);
	pixel.x += head->draw->start.x + ref_pos_x;
	pixel.y += head->draw->start.y + ref_pos_y;
	return (pixel);
}

void	draw_map(t_head *h)
{
	t_pixel	s0;
	int		x;
	int		y;

	create_new_image(h->vars.mlx, &h->draw->image, VW, VH);
	y = -1;
	while (++y < h->map->size.y)
	{
		x = -1;
		while (++x < h->map->size.x)
		{
			s0 = get_reference(h, y, x);
			if (x + 1 < h->map->size.x)
				bresenham(h, s0, get_reference(h, y, x + 1));
			if (y + 1 < h->map->size.y)
				bresenham(h, s0, get_reference(h, y + 1, x));
		}
	}
	mlx_put_image_to_window(h->vars.mlx,
		h->vars.win,
		h->draw->image.img,
		MENU_W,
		0);
}
