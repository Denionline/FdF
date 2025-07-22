/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/22 10:27:06 by dximenes         ###   ########.fr       */
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

int render(t_head * h)
{
	init_render(h);
	transform(h);
	draw(h);
	update_fps(h, &h->fps);
	mlx_loop(h->vars.mlx);
}
