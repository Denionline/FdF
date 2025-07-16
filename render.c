/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/16 12:14:21 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init_render(t_head * head)
{
	double newzoom;
	head->draw->start.x = (head->window->size.x / 2);
	head->draw->start.y = (head->window->size.y / 2);
	// newzoom = ;m
	newzoom = head->draw->zoom;
	// newzoom = head->map->size.x;
	printf("%f\n", newzoom);
}

void render(t_head * head)
{
	int y;
	int x;

	create_new_image(head);
	init_render(head);
	y = 0;
	while (y < head->map->size.y)
	{
		x = 0;
		while (x < head->map->size.x)
		{
			draw(head, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(head->vars.mlx, head->vars.win, head->draw->image.img, 0, 0);
	mlx_loop(head->vars.mlx);
}
