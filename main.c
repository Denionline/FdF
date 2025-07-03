/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/03 12:13:48 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init(t_mlx ** mlx)
{
	(*mlx) = malloc(sizeof(t_mlx));
	if (!(*mlx))
		return;
	(*mlx)->window = malloc(sizeof(t_window));
	if (!(*mlx)->window)
		return;
	(*mlx)->map = malloc(sizeof(t_map));
	if (!(*mlx)->map)
		return;
	(*mlx)->window->size.x = 1000;
	(*mlx)->window->size.y = 800;
	(*mlx)->connection = mlx_init();
	(*mlx)->window->_ = mlx_new_window(
		(*mlx)->connection,
		(*mlx)->window->size.x,
		(*mlx)->window->size.y,
		"FdF");
}

int main(int argc, char * argv[])
{
	t_mlx * mlx;

	if (argc != 2)
		return (0);
	init(&mlx);
	load_map(&mlx->map, argv[1]);
	hooks(mlx);
	render(mlx);
	return (free(mlx->window), free(mlx->map), free(mlx), 0);
}
