/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:10:02 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 18:13:21 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	move_action(int keycode, t_control *control)
{
	if (keycode == KEY_ARROW_UP)
		control->position.y = -1;
	else if (keycode == KEY_ARROW_DOWN)
		control->position.y = 1;
	if (keycode == KEY_ARROW_RIGHT)
		control->position.x = 1;
	else if (keycode == KEY_ARROW_LEFT)
		control->position.x = -1;
}
