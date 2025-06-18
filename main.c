/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/18 23:03:23 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "FdF.h"

int	main(void)
{
	t_window	window;

	window.viewport_x = 1000;
	window.viewport_y = 800;
	void	*mlx_connection;
	void	*mlx_window;
	
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(
		mlx_connection,
		window.viewport_x,
		window.viewport_y,
		"New window"
	);
	window.square_min_x = 0;
	window.square_max_x = window.viewport_x - 1;
	window.square_min_y = 0;
	window.square_max_y = window.viewport_y - 1;
	for (int x = window.square_min_x; x <= window.square_max_x; x++) {
		for (int y = window.square_min_y; y <= window.square_max_y; y++) {
			if ((x == window.square_min_x || y == window.square_min_y) || (x == window.square_max_x || y == window.square_max_y)) {
				mlx_pixel_put(
					mlx_connection,
					mlx_window,
					x,
					y,
					0xff000ff
				);
			}
		}
	}
	mlx_loop(mlx_connection);
}