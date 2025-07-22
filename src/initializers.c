/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:57:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/22 18:05:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void init_draw(t_head * head)
{
	head->draw->pad.x = 20;
	head->draw->pad.y = 20;
	head->draw->position.x = 0;
	head->draw->position.y = 0;
	head->draw->ang.x = PI / 8;
	head->draw->ang.y = PI / -6;
	head->draw->ang.z = PI / 5;
	head->draw->distance = 1.0;
	head->draw->zoom = 1.0;
}

void init_program(t_head ** head, char * path)
{
	char ** path_sep;
	char *	fdf_file;
	int		i;

	(*head) = ft_calloc(1, sizeof(t_head));
	if (!head)
		return;
	(*head)->map = ft_calloc(1, sizeof(t_map));
	if (!(*head)->map)
		return;
	(*head)->draw = ft_calloc(1, sizeof(t_draw));
	if (!(*head)->draw)
		return;
	(*head)->vars.mlx = mlx_init();
	path_sep = ft_split(path, '/');
	fdf_file = NULL;
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
	if (!fdf_file)
		end(*head);
	(*head)->vars.win = mlx_new_window((*head)->vars.mlx, VW, VH, fdf_file);
	ft_bzero(&(*head)->controls, sizeof((*head)->controls));
	free(fdf_file);
	init_draw(*head);
	ft_memcpy((*head)->draw->projection,
			  (double[3][3]){
				  {1, 0, 0},
				  {0, 1, 0},
				  {0, 0, 1}},
			  sizeof(double) * 9);
}
