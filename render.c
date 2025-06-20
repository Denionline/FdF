/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:01:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/20 18:34:51 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void render(t_mlx * mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->map->size_y)
	{
		x = 0;
		while (x < mlx->map->size_x)
		{
			if (mlx->map->coordinates[y][x] != 0)
				mlx_pixel_put(
					mlx->connection,
					mlx->window->content,
					x,
					y,
					0xff0000);
			x++;
		}
		y++;
	}
	mlx_loop(mlx->connection);
}