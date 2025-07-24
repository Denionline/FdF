/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:48:17 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/24 14:33:46 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void get_pixel_values(t_head * head, int y, int x, t_pixel * s)
{
	const t_pixel pixel = head->map->points[y][x];
	const double  center_x = (head->map->size.x) / 2.0;
	const double  center_y = (head->map->size.y) / 2.0;
	const int	  pixel_x = x - center_x;
	const int	  pixel_y = y - center_y;
	double		  big_side;
	double		  value;
	double		  pad_z;

	big_side = head->map->size.y;
	if (head->map->size.x > head->map->size.y)
		big_side = head->map->size.x;
	value = (big_side - SMALLEST_SIZE) / (BIGGEST_SIZE - SMALLEST_SIZE);
	if (value < 0.0)
		value = 0.0;
	if (value > 1.0)
		value = 1.0;
	pad_z = MAX_PADZ + (MIN_PADZ - MAX_PADZ) * value;

	s->z = pad_z * head->draw->zoom * pixel.z;
	s->x = (head->draw->pad.x * head->draw->zoom) * pixel_x;
	s->y = (head->draw->pad.y * head->draw->zoom) * pixel_y;
	s->color = pixel.color;
}

static t_pixel get_reference(t_head * head, int y, int x)
{
	t_pixel pixel;

	get_pixel_values(head, y, x, &pixel);
	pixel = mat_mult(rotate_x(head), pixel);
	pixel = mat_mult(rotate_y(head), pixel);
	pixel = mat_mult(rotate_z(head), pixel);
	pixel.x += head->draw->start.x + (head->draw->position.x * (1 / head->draw->zoom));
	pixel.y += head->draw->start.y + (head->draw->position.y * (1 / head->draw->zoom));
	return (pixel);
}

void draw(t_head * h)
{
	t_pixel s0;
	int		x;
	int		y;

	create_new_image(h->vars.mlx, &h->draw->image, VW - MENU_W, VH);
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
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, h->draw->image.img, MENU_W, 0);
}
