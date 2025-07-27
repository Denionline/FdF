/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 23:30:59 by dximenes         ###   ########.fr       */
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
	return (0);
}
