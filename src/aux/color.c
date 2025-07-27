/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:13:00 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 11:26:52 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	set_color_top(t_pixel **pixels, int size_x, int size_y)
{
	const int	max_z = get_max_z(pixels, size_x, size_y);
	int			y;
	int			x;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			if (pixels[y][x].z == max_z)
				if (pixels[y][x].color == COLOR)
					pixels[y][x].color = HIGH_COLOR;
			x++;
		}
		y++;
	}
}

int	get_color_between(int c1, int c2, int step, int steps)
{
	double		percent;
	int			r;
	int			g;
	int			b;

	if (steps == 0)
		percent = 0.0;
	else
		percent = (double)step / (double)steps;
	r = ((c1 >> 16) & 0xFF);
	r += (int)((((c2 >> 16) & 0xFF) - r) * percent);
	g = ((c1 >> 8) & 0xFF);
	g += (int)((((c2 >> 8) & 0xFF) - g) * percent);
	b = ((c1 >> 0) & 0xFF);
	b += (int)((((c2 >> 0) & 0xFF) - b) * percent);
	return ((r << 16) | (g << 8) | b);
}
