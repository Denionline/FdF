/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:06:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 15:29:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_rotate3	*rotate_x(t_head *head)
{
	const double	c = cos(head->draw->ang.x);
	const double	s = sin(head->draw->ang.x);

	head->draw->projection[0][0] = 1;
	head->draw->projection[0][1] = 0;
	head->draw->projection[0][2] = 0;
	head->draw->projection[1][0] = 0;
	head->draw->projection[1][1] = c;
	head->draw->projection[1][2] = -s;
	head->draw->projection[2][0] = 0;
	head->draw->projection[2][1] = s;
	head->draw->projection[2][2] = c;
	return (head->draw->projection);
}

t_rotate3	*rotate_y(t_head *head)
{
	const double	c = cos(head->draw->ang.y);
	const double	s = sin(head->draw->ang.y);

	head->draw->projection[0][0] = c;
	head->draw->projection[0][1] = 0;
	head->draw->projection[0][2] = s;
	head->draw->projection[1][0] = 0;
	head->draw->projection[1][1] = 1;
	head->draw->projection[1][2] = 0;
	head->draw->projection[2][0] = -s;
	head->draw->projection[2][1] = 0;
	head->draw->projection[2][2] = c;
	return (head->draw->projection);
}

t_rotate3	*rotate_z(t_head *head)
{
	const double	c = cos(head->draw->ang.z);
	const double	s = sin(head->draw->ang.z);

	head->draw->projection[0][0] = c;
	head->draw->projection[0][1] = -s;
	head->draw->projection[0][2] = 0;
	head->draw->projection[1][0] = s;
	head->draw->projection[1][1] = c;
	head->draw->projection[1][2] = 0;
	head->draw->projection[2][0] = 0;
	head->draw->projection[2][1] = 0;
	head->draw->projection[2][2] = 1;
	return (head->draw->projection);
}
