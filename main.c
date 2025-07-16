/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/16 17:03:05 by dximenes         ###   ########.fr       */
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
	(*head)->window->size.x = VW;
	(*head)->window->size.y = VH;
	(*head)->vars.mlx = mlx_init();
	(*head)->vars.win = mlx_new_window(
		(*head)->vars.mlx,
		(*head)->window->size.x,
		(*head)->window->size.y,
		"FdF");
	(*head)->draw->pad_x = 20;
	(*head)->draw->pad_y = 20;
	(*head)->draw->position.x = 0;
	(*head)->draw->position.y = 0;
	(*head)->draw->ang_x = PI / 8;
	(*head)->draw->ang_y = PI / -6;
	(*head)->draw->ang_z = PI / 5;
	(*head)->draw->distance = 1.0;
	(*head)->draw->margin = 0.8;

	ft_memcpy((*head)->draw->projection,
			  (double[3][3]){
				  {1, 0, 0},
				  {0, 1, 0},
				  {0, 0, 1}},
			  sizeof(double) * 9);
}

// static void show_map(t_pixel ** coor, int size_y, int size_x)
// {
// 	for (int y = 0; y < size_y; y++)
// 	{
// 		for (int x = 0; x < size_x; x++)
// 		{
// 			printf("%3d", coor[y][x].z);
// 		}
// 		printf("\n");
// 	}
// }

int main(int argc, char * argv[])
{
	t_head * head;

	if (argc != 2)
		return (0);
	init(&head);
	load_map(&head->map, argv[1]);
	printf("Map %s loaded with size (%d, %d)\n", argv[1], head->map->size.x, head->map->size.y);
	hooks(head);
	// show_map(head->map->coordinates, head->map->size.y, head->map->size.x);
	head->draw->zoom = 1;
	// head->draw->zoom = ((head->window->size.x * 0.8) / head->map->size.x);
	render(head);
	end(head);
	return (0);
}
