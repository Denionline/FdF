/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/10 16:29:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init(t_head ** head)
{
	(*head) = malloc(sizeof(t_head));
	if (!(*head))
		return;
	(*head)->window = malloc(sizeof(t_window));
	if (!(*head)->window)
		return;
	(*head)->map = malloc(sizeof(t_map));
	if (!(*head)->map)
		return;
	(*head)->draw = malloc(sizeof(t_draw));
	if (!(*head)->draw)
		return;
	(*head)->window->size.x = 1000;
	(*head)->window->size.y = 800;
	(*head)->vars.mlx = mlx_init();
	(*head)->vars.win = mlx_new_window(
		(*head)->vars.mlx,
		(*head)->window->size.x,
		(*head)->window->size.y,
		"FdF");
	(*head)->draw->pad_x = 10;
	(*head)->draw->pad_y = 10;
	(*head)->draw->z = 0;
	(*head)->draw->position.x = 0;
	(*head)->draw->position.y = 0;
	(*head)->draw->ang_x = PI / 8;
	(*head)->draw->ang_y = PI / -6;
	(*head)->draw->ang_z = PI / 5;
	(*head)->draw->ang_2d = 0.7;

	(*head)->draw->projection[0][0] = 1;
	(*head)->draw->projection[0][1] = 0;
	(*head)->draw->projection[0][2] = 0;

	(*head)->draw->projection[1][0] = 0;
	(*head)->draw->projection[1][1] = 1;
	(*head)->draw->projection[1][2] = 0;

	(*head)->draw->projection[2][0] = 0;
	(*head)->draw->projection[2][1] = 0;
	(*head)->draw->projection[2][2] = 1;
}

// static void show_map(t_point ** coor, int size_y, int size_x)
// {
// 	for (int y = 0; y < size_y; y++)
// 	{
// 		for (int x = 0; x < size_x; x++)
// 		{
// 			ft_printf("%3d", coor[y][x].z);
// 		}
// 		ft_printf("\n");
// 	}
// }

int main(int argc, char * argv[])
{
	t_head * head;

	if (argc != 2)
		return (0);
	init(&head);
	load_map(&head->map, argv[1]);
	hooks(head);
	// show_map(head->map->coordinates, head->map->size.y, head->map->size.x);
	render(head);
	return (free(head->window), free(head->map), free(head), 0);
}
