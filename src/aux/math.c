/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:35:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 17:14:57 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	absolute(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

double	absolute_double(double number)
{
	if (number < 0)
		return (-number);
	return (number);
}

t_pixel	mat_mult(double projection[3][3], t_pixel values)
{
	double	numbers[3];
	double	buff[3];
	int		x;
	int		y;

	numbers[0] = values.x;
	numbers[1] = values.y;
	numbers[2] = values.z;
	y = 0;
	while (y < 3)
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
	values.z = buff[2];
	return (values);
}
