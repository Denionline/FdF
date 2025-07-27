/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 10:46:51 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 11:27:45 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	get_max_z(t_pixel **pixels, int size_x, int size_y)
{
	int	max_z;
	int	y;
	int	x;

	max_z = 0;
	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if (pixels[y][x].z > max_z)
				max_z = pixels[y][x].z;
			x++;
		}
		y++;
	}
	return (max_z);
}
