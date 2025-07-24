/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/22 15:04:11 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int render(t_head * h)
{
	h->draw->start.x = VW / 2;
	h->draw->start.y = VH / 2;
	transform(h);
	draw(h);
	update_fps(h, &h->fps);
	mlx_loop(h->vars.mlx);
	return (0);
}
