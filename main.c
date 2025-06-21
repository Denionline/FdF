/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/21 16:38:45 by dximenes         ###   ########.fr       */
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
	mlx->window->vw = 1000;
	mlx->window->vh = 800;
	mlx->connection = mlx_init();
	mlx->window->content = mlx_new_window(
		mlx->connection,
		mlx->window->vw,
		mlx->window->vh,
		"New window");
	mlx->map->path = ft_strdup(argv[1]);
	load_map(&mlx->map);
	render(mlx);
	return (free(mlx->window), free(mlx), 0);
}
