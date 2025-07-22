/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:13:00 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/21 21:36:23 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int get_color_between(int color1, int color2, int step, int steps)
{
	const int	r1 = (color1 >> 16) & 0xFF;
	const int	g1 = (color1 >> 8) & 0xFF;
	const int	b1 = (color1 >> 0) & 0xFF;
	const int	r2 = (color2 >> 16) & 0xFF;
	const int	g2 = (color2 >> 8) & 0xFF;
	const int	b2 = (color2 >> 0) & 0xFF;
	double		percent;
	int			r;
	int			g;
	int			b;

	if (steps == 0)
		percent = 0.0;
	else
		percent = (double)step / (double)steps;
	r = r1 + (int)((r2 - r1) * percent);
	g = g1 + (int)((g2 - g1) * percent);
	b = b1 + (int)((b2 - b1) * percent);
	return ((r << 16) | (g << 8) | b);
}
