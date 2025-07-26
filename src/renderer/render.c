/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 17:07:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	render(t_head *h)
{
	h->draw->start.x = (VW - MENU_W) / 2;
	h->draw->start.y = VH / 2;
	transform(h);
	draw_map(h);
	menu(h);
	update_fps(h, &h->fps);
	mlx_loop(h->vars.mlx);
	return (0);
}
