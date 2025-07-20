/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/19 10:14:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void init(t_head ** head, char * path)
{
	char ** path_sep;
	char *	fdf_file;
	int		i;

	(*head) = ft_calloc(1, sizeof(t_head));
	if (!(*head))
		return;
	(*head)->window = ft_calloc(1, sizeof(t_window));
	if (!(*head)->window)
		return;
	(*head)->map = ft_calloc(1, sizeof(t_map));
	if (!(*head)->map)
		return;
	(*head)->draw = ft_calloc(1, sizeof(t_draw));
	if (!(*head)->draw)
		return;
	(*head)->window->size.x = VW;
	(*head)->window->size.y = VH;
	(*head)->vars.mlx = mlx_init();
	path_sep = ft_split(path, '/');
	i = 0;
	while (path_sep[i])
	{
		if (ft_strnstr(path_sep[i], ".fdf", ft_strlen(path_sep[i])))
			fdf_file = path_sep[i];
		else
			free(path_sep[i]);
		i++;
	}
	free(path_sep);
	(*head)->vars.win = mlx_new_window((*head)->vars.mlx, VW, VH, fdf_file);
	(*head)->draw->pad_x = 20;
	(*head)->draw->pad_y = 20;
	(*head)->draw->position.x = 0;
	(*head)->draw->position.y = 0;
	(*head)->draw->ang_x = PI / 8;
	(*head)->draw->ang_y = PI / -6;
	(*head)->draw->ang_z = PI / 5;
	(*head)->draw->distance = 1.0;
	(*head)->draw->margin = 0.8;
	(*head)->draw->zoom = 1.0;
	free(fdf_file);
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
	init(&head, argv[1]);
	load_map(&head->map, argv[1]);
	printf("Map %s loaded with size (%d, %d)\n", argv[1], head->map->size.x, head->map->size.y);
	hooks(head);
	// show_map(head->map->coordinates, head->map->size.y, head->map->size.x);
	render(head);
	end(head);
	return (0);
}
