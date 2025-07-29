/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:57:54 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:58:41 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	init_menu(t_head *head)
{
	ft_bzero(&head->menu, sizeof(head->menu));
	get_logo_art(&head->menu.arts);
	get_aux_arts(&head->menu.arts);
	get_title_art(&head->menu.arts);
	get_zoom_arts(&head->menu.arts);
	get_move_arts(&head->menu.arts);
	get_rotation_arts_1(&head->menu.arts);
	get_rotation_arts_2(&head->menu.arts);
}

void	init_draw(t_head *head)
{
	head->draw->pad.x = 20;
	head->draw->pad.y = 20;
	head->draw->position.x = 0;
	head->draw->position.y = 0;
	head->draw->ang.x = 0.15;
	head->draw->ang.y = -0.08;
	head->draw->ang.z = 0.63;
	head->draw->zoom = 1.0;
	head->draw->plane_mode = 0;
}

void	init_program(t_head **head, char *path)
{
	char	*fdf_file;

	(*head) = ft_calloc(1, sizeof(t_head));
	if (!head)
		return ;
	(*head)->map = ft_calloc(1, sizeof(t_map));
	if (!(*head)->map)
		return ;
	(*head)->draw = ft_calloc(1, sizeof(t_draw));
	if (!(*head)->draw)
		return ;
	(*head)->vars.mlx = mlx_init();
	fdf_file = get_map_name(path);
	if (!fdf_file)
		end(*head);
	(*head)->vars.win = mlx_new_window((*head)->vars.mlx, VW, VH, fdf_file);
	free(fdf_file);
	ft_bzero(&(*head)->controls, sizeof((*head)->controls));
	init_draw(*head);
	ft_memcpy((*head)->draw->projection,
		(double [3][3]){
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{0.0, 0.0, 1.0}},
		sizeof(double) * 9);
}
