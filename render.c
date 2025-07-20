/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/20 10:56:22 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init_render(t_head * head)
{
	double newzoom;
	head->draw->start.x = (head->window->size.x / 2);
	head->draw->start.y = (head->window->size.y / 2);
	newzoom = head->draw->zoom;
}

void render(t_head * h)
{
	int y;
	int x;

	create_new_image(h);
	init_render(h);
	y = 0;
	while (y < h->map->size.y)
	{
		x = 0;
		while (x < h->map->size.x)
		{
			draw(h, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, h->draw->image.img, 0, 0);
	mlx_loop(h->vars.mlx);
}
