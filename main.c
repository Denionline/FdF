/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/22 15:02:03 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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
	init_program(&head, argv[1]);
	load_map(head, argv[1]);
	printf("Map %s loaded with size (%d, %d)\n", argv[1], head->map->size.x, head->map->size.y);
	hooks(head);
	// show_map(head->map->coordinates, head->map->size.y, head->map->size.x);
	init_fps(&head->fps);
	render(head);
	end(head);
	return (0);
}
