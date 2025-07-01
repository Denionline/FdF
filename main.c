/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/29 16:46:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int argc, char * argv[])
{
	t_mlx * mlx;

	if (argc != 2)
		return (0);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	mlx->window = malloc(sizeof(t_window));
	if (!mlx->window)
		return (0);
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		return (0);
	mlx->window->size.x = 1000;
	mlx->window->size.y = 800;
	mlx->connection = mlx_init();
	mlx->window->_ = mlx_new_window(
		mlx->connection,
		mlx->window->size.x,
		mlx->window->size.y,
		"New window");
	mlx->map->path = ft_strdup(argv[1]);
	load_map(&mlx->map);
	render(mlx);
	return (free(mlx->window), free(mlx), 0);
}
