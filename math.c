/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:35:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/18 16:31:52 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int absolute(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

t_pixel mat_mult(double projection[3][3], t_pixel values)
{
	double numbers[3];
	double buff[3];
	int	   x;
	int	   y;

	ft_memcpy(numbers, (double[3]){values.x, values.y, values.z}, sizeof(double) * 3);
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
