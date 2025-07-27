/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:31:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/28 00:11:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	end(t_head *head)
{
	int	i;

	if (head->menu.image.img)
		mlx_destroy_image(head->vars.mlx, head->menu.image.img);
	if (head->draw->image.img)
		mlx_destroy_image(head->vars.mlx, head->draw->image.img);
	mlx_destroy_window(head->vars.mlx, head->vars.win);
	mlx_destroy_display(head->vars.mlx);
	i = 0;
	while (head->map->points && i < head->map->size.y)
		free(head->map->points[i++]);
	if (head->map->points)
		free(head->map->points);
	free(head->map);
	free(head->draw);
	free(head->vars.mlx);
	free(head);
	exit(0);
}
