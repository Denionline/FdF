/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:35:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/08 15:11:04 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_axis mat_mult(double projection[2][3], t_axis values)
{
	double numbers[3];
	double buff[2];
	int	   x;
	int	   y;

	numbers[0] = values.x;
	numbers[1] = values.y;
	numbers[2] = values.z;
	y = 0;
	while (y < 2)
	{
		buff[y] = 0;
		x = 0;
		while (x < 3)
		{
			buff[y] += projection[y][x] * numbers[x];
			x++;
		}
		y++;
	}
	values.x = buff[0];
	values.y = buff[1];
	return (values);
}
