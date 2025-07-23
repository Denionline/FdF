/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:27 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/23 12:13:19 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int mouse_release(int button, int x, int y, t_head * head)
{
	if (button == MOUSE_LEFT_CLICK && x && y)
	{
		head->controls.is_on.mouse_left_click = FALSE;
		head->controls.rotation.x = 0;
		head->controls.rotation.y = 0;
	}
	return (0);
}

int mouse_press(int button, int x, int y, t_head * head)
{
	if (button == MOUSE_SCROLL_UP && head->controls.is_on.key_ctrl)
	{
		head->draw->zoom += 0.05;
		if (head->draw->zoom > MAX_ZOOM)
			head->draw->zoom = MAX_ZOOM;
	}
	if (button == MOUSE_SCROLL_DOWN && head->controls.is_on.key_ctrl)
	{
		head->draw->zoom -= 0.05;
		if (head->draw->zoom < MIN_ZOOM)
			head->draw->zoom = MIN_ZOOM;
	}
	if (button == MOUSE_LEFT_CLICK && x && y)
		head->controls.is_on.mouse_left_click = TRUE;
	return (0);
}

int mouse_move(int x, int y, t_head * head)
{
	if (head->controls.is_on.mouse_left_click)
	{
		x -= (VW / 2);
		if (x > 0)
			head->draw->ang.x -= x * 0.0001;
		else if (x < 0)
			head->draw->ang.x += x * 0.0001;

		y -= (VH / 2);
		if (y > 0)
			head->draw->ang.y -= y * 0.0001;
		else if (y < 0)
			head->draw->ang.y += y * 0.0001;
	}
	return (0);
}