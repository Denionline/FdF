/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:32:02 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/20 19:05:53 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void transform(t_head * head)
{
	if (head->controls.rotation.x != 0)
		head->draw->ang_x += head->controls.rotation.x;
	if (head->controls.rotation.y != 0)
		head->draw->ang_y += head->controls.rotation.y;
	if (head->controls.rotation.z != 0)
		head->draw->ang_z += head->controls.rotation.z;
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
}
