/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:31:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 17:22:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	end(t_head *head)
{
	int	i;

	mlx_destroy_image(head->vars.mlx, head->draw->image.img);
	mlx_destroy_window(head->vars.mlx, head->vars.win);
	mlx_destroy_display(head->vars.mlx);
	i = 0;
	while (head->map->points[0] && i < head->map->size.y)
		free(head->map->points[i++]);
	if (head->map->points)
		free(head->map->points);
	if (head->vars.mlx)
		free(head->vars.mlx);
	if (head->map)
		free(head->map);
	if (head->draw)
		free(head->draw);
	if (head)
		free(head);
	exit(0);
}
