/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:06:25 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/18 10:06:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

double (*rotate_x(t_head * head))[3]
{
	const double c = cos(head->draw->ang_x);
	const double s = sin(head->draw->ang_x);

	ft_memcpy(head->draw->projection,
			  (double[3][3]){
				  {1, 0, 0},
				  {0, c, -s},
				  {0, s, c}},
			  sizeof(double) * 9);
	return (head->draw->projection);
}

double (*rotate_y(t_head * head))[3]
{
	const double c = cos(head->draw->ang_y);
	const double s = sin(head->draw->ang_y);

	ft_memcpy(head->draw->projection,
			  (double[3][3]){
				  {c, 0, s},
				  {0, 1, 0},
				  {-s, 0, c}},
			  sizeof(double) * 9);
	return (head->draw->projection);
}

double (*rotate_z(t_head * head))[3]
{
	const double c = cos(head->draw->ang_z);
	const double s = sin(head->draw->ang_z);

	ft_memcpy(head->draw->projection,
			  (double[3][3]){
				  {c, -s, 0},
				  {s, c, 0},
				  {0, 0, 1}},
			  sizeof(double) * 9);
	return (head->draw->projection);
}