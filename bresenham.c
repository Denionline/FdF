/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:54:15 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/09 13:25:48 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void calc_err(int * err_curr, int * pos, int sum_err, int sum_pos)
{
	*err_curr += sum_err;
	*pos += sum_pos;
}

void bresenham(t_head * head, t_pixel s0, t_pixel s1)
{
	int delta_x;
	int delta_y;
	int step_x;
	int step_y;
	int err_init;
	int err_curr;

	delta_x = abs(s1.x - s0.x);
	step_x = 1;
	if (s0.x > s1.x)
		step_x = -1;
	delta_y = -abs(s1.y - s0.y);
	step_y = 1;
	if (s0.y > s1.y)
		step_y = -1;
	err_init = delta_x + delta_y;
	while (s0.x != s1.x || s0.y != s1.y)
	{
		mlx_pixel_put(head->vars.mlx, head->vars.win, s0.x, s0.y, s0.color);
		err_curr = 2 * err_init;
		if (err_curr >= delta_y)
			calc_err(&err_init, &s0.x, delta_y, step_x);
		if (err_curr <= delta_x)
			calc_err(&err_init, &s0.y, delta_x, step_y);
	}
}
