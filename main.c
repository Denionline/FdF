/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/02 15:25:49 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init(t_mlx **mlx)
{
	(*mlx) = malloc(sizeof(t_mlx));
	if (!(*mlx))
		return ;
	(*mlx)->window = malloc(sizeof(t_window));
	if (!(*mlx)->window)
		return ;
	(*mlx)->map = malloc(sizeof(t_map));
	if (!(*mlx)->map)
		return ;
}

int main(int argc, char * argv[])
{
	t_mlx * mlx;

	if (argc != 2)
		return (0);
	init(&mlx);
	mlx->window->size.x = 1000;
	mlx->window->size.y = 800;
	mlx->map->path = ft_strdup(argv[1]);
	load_map(&mlx->map);
	mlx->connection = mlx_init();
	mlx->window->_ = mlx_new_window(
		mlx->connection,
		mlx->window->size.x,
		mlx->window->size.y,
		"New window");
	render(mlx);
	return (free(mlx->window), free(mlx), 0);
}
