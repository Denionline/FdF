/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/09 11:52:00 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void render(t_head * head)
{
	int y;
	int x;

	head->draw->start.x = (head->window->size.x / 2) - (head->map->size.x / 2);
	head->draw->start.y = (head->window->size.y / 2) - (head->map->size.y / 2);
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
	mlx_loop(head->vars.mlx);
}
