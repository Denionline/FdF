/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:09:13 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/24 12:09:57 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void rotate_action(int keycode, t_control * control)
{
	if (keycode == KEY_W)
		control->rotation.x = 0.01;
	else if (keycode == KEY_S)
		control->rotation.x = -0.01;
	if (keycode == KEY_D)
		control->rotation.y = 0.01;
	else if (keycode == KEY_A)
		control->rotation.y = -0.01;
	if (keycode == KEY_E)
		control->rotation.z = 0.01;
	else if (keycode == KEY_Q)
		control->rotation.z = -0.01;
}