/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/01 14:21:01 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void render(t_mlx * mlx)
{
	t_draw drw;

	drw.pad = 20;
	drw.off.x = mlx->window->size.x / 3;
	drw.off.y = mlx->window->size.y / 3;
	drw._.y = 0;
	while (drw._.y < mlx->map->size.y)
	{
		drw._.x = 0;
		while (drw._.x < mlx->map->size.x)
		{
			draw(mlx, &drw);
			drw._.x++;
		}
		drw._.y++;
	}
	mlx_loop(mlx->connection);
}
