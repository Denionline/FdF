/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/02 16:08:53 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void render(t_mlx * mlx)
{
	t_draw draw;
	int	   d;

	ft_bzero(&draw, sizeof(draw));
	draw.pad = 30;
	draw._.y = 0;
	while (draw._.y <= mlx->map->size.y * draw.pad)
	{
		draw._.x = 0;
		while (draw._.x <= mlx->map->size.x * draw.pad)
		{
			if (!(draw._.y % draw.pad))
				d = 0;
			d = mlx->map->coordinates[draw._.y / draw.pad][draw._.x / draw.pad];
			if (!(draw._.y % draw.pad) || !(draw._.x % draw.pad))
				mlx_pixel_put(mlx->connection, mlx->window->_, draw._.x, draw._.y, 0x00ff00);
			draw._.x++;
		}
		draw._.y++;
	}
	mlx_loop(mlx->connection);
}
