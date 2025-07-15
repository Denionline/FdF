/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:35:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/15 21:07:37 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

double	(*rotate_x(t_head * head))[3]
{
	const double c = cos(head->draw->ang_x);
	const double s = sin(head->draw->ang_x);

	ft_memcpy(head->draw->projection, (double[3][3]){\
		{1, 0, 0},\
		{0, c, -s},\
		{0, s, c}\
	}, sizeof(double) * 9);
	return (head->draw->projection);
}

double	(*rotate_y(t_head * head))[3]
{
	const double c = cos(head->draw->ang_y);
	const double s = sin(head->draw->ang_y);

	ft_memcpy(head->draw->projection, (double[3][3]){\
		{c, 0, s},\
		{0, 1, 0},\
		{-s, 0, c}\
	}, sizeof(double) * 9);
	return (head->draw->projection);
}

double	(*rotate_z(t_head * head))[3]
{
	const double c = cos(head->draw->ang_z);
	const double s = sin(head->draw->ang_z);

	ft_memcpy(head->draw->projection, (double[3][3]){\
		{c, -s, 0},\
		{s, c, 0},\
		{0, 0, 1}\
	}, sizeof(double) * 9);
	return (head->draw->projection);
}

t_pixel mat_mult(double projection[3][3], t_pixel values)
{
	double numbers[3];
	double buff[3];
	int	   x;
	int	   y;

	ft_memcpy(numbers, (double[3]){
		values.x, values.y, values.z
	}, sizeof(double) * 3);
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
