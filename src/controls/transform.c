/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:32:02 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:10:06 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	get_art_color(double value, int active_when)
{
	if (active_when > 0 && value > 0.0)
		return (ACTIVE_KEY_COLOR);
	if (active_when < 0 && value < 0.0)
		return (ACTIVE_KEY_COLOR);
	return (DEFAULT_KEY_COLOR);
}

static void	update_art_color(t_control *controls, t_arts *arts)
{
	arts->key_up.color = get_art_color(controls->position.y, -1);
	arts->key_down.color = get_art_color(controls->position.y, 1);
	arts->key_left.color = get_art_color(controls->position.x, -1);
	arts->key_right.color = get_art_color(controls->position.x, 1);
	arts->key_q.color = get_art_color(controls->rotation.z, -1);
	arts->key_e.color = get_art_color(controls->rotation.z, 1);
	arts->key_a.color = get_art_color(controls->rotation.y, -1);
	arts->key_d.color = get_art_color(controls->rotation.y, 1);
	arts->key_s.color = get_art_color(controls->rotation.x, -1);
	arts->key_w.color = get_art_color(controls->rotation.x, 1);
	arts->key_plus.color = get_art_color(controls->zoom, 1);
	arts->key_minus.color = get_art_color(controls->zoom, -1);
}

static void	check_limits(t_head *head)
{
	if (absolute_double(head->draw->ang.x) >= 20 * PI)
		head->draw->ang.x = PI / 8;
	if (absolute_double(head->draw->ang.y) >= 20 * PI)
		head->draw->ang.y = PI / -6;
	if (absolute_double(head->draw->ang.z) >= 20 * PI)
		head->draw->ang.z = PI / 5;
}

void	transform(t_head *head)
{
	if (head->controls.rotation.x != 0)
		head->draw->ang.x += head->controls.rotation.x;
	if (head->controls.rotation.y != 0)
		head->draw->ang.y += head->controls.rotation.y;
	if (head->controls.rotation.z != 0)
		head->draw->ang.z += head->controls.rotation.z;
	if (head->controls.zoom != 0)
	{
		head->draw->zoom += head->controls.zoom;
		if (head->draw->zoom > MAX_ZOOM)
			head->draw->zoom = MAX_ZOOM;
		if (head->draw->zoom < MIN_ZOOM)
			head->draw->zoom = MIN_ZOOM;
	}
	if (head->controls.position.y)
		head->draw->position.y += head->controls.position.y;
	if (head->controls.position.x)
		head->draw->position.x += head->controls.position.x;
	check_limits(head);
	update_art_color(&head->controls, &head->menu.arts);
	if (head->draw->plane_mode)
		head->menu.arts.key_tab.color = ACTIVE_KEY_COLOR;
	else
		head->menu.arts.key_tab.color = DEFAULT_KEY_COLOR;
}
