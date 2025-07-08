/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/08 09:37:33 by dximenes         ###   ########.fr       */
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
	(*head)->draw->loop = TRUE;
	(*head)->draw->ang_x = PI / -4; // 30 graus
	(*head)->draw->ang_y = PI / -6; // 45 graus
	(*head)->draw->ang_2d = 0.7;	   // sem rotação 2D
}

static void show_map(t_point ** coor, int size_y, int size_x)
{
	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			ft_printf("%3d", coor[y][x].z);
		}
		ft_printf("\n");
	}
}

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
