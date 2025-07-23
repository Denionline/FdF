/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:08:14 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/23 17:38:12 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void rotate_action(int keycode, t_control * control)
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

static void zoom_action(int keycode, t_head * head)
{
	if (keycode == KEY_PLUS)
		head->controls.zoom = 0.05;
	else if (keycode == KEY_MINUS)
		head->controls.zoom = -0.05;
}

static void move_action(int keycode, t_head * head)
{
	if (keycode == KEY_ARROW_UP)
		head->controls.position.y = -1;
	else if (keycode == KEY_ARROW_DOWN)
		head->controls.position.y = 1;
	if (keycode == KEY_ARROW_RIGHT)
		head->controls.position.x = 1;
	else if (keycode == KEY_ARROW_LEFT)
		head->controls.position.x = -1;
}

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
	move_action(keycode, head);
	zoom_action(keycode, head);
	if (keycode == KEY_CTRL)
		head->controls.is_on.key_ctrl = TRUE;
	if (keycode == KEY_ESC)
		mlx_loop_end(head->vars.mlx);
	return (0);
}
