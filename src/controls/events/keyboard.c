/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:14 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/24 12:13:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int key_release(int keycode, t_head * head)
{
	if ((keycode == KEY_W || keycode == KEY_S))
		head->controls.rotation.x = 0;
	if (keycode == KEY_D || keycode == KEY_A)
		head->controls.rotation.y = 0;
	if (keycode == KEY_E || keycode == KEY_Q)
		head->controls.rotation.z = 0;
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		head->controls.zoom = 0;
	if (keycode == KEY_ARROW_UP || keycode == KEY_ARROW_DOWN)
		head->controls.position.y = 0;
	if (keycode == KEY_ARROW_RIGHT || keycode == KEY_ARROW_LEFT)
		head->controls.position.x = 0;
	if (keycode == KEY_CTRL)
		head->controls.is_on.key_ctrl = 0;
	return (0);
}

int key_press(int keycode, t_head * head)
{
	rotate_action(keycode, &head->controls);
	move_action(keycode, &head->controls);
	zoom_action(keycode, &head->controls);
	if (keycode == KEY_CTRL)
		head->controls.is_on.key_ctrl = TRUE;
	if (keycode == KEY_ESC)
		mlx_loop_end(head->vars.mlx);
	return (0);
}
