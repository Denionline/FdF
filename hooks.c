/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:06:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/15 10:11:44 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int key_press(int keycode, t_head * head)
{
	// printf("Keycode => %d\n", keycode);

	// Rotate x
	if (keycode == KEY_NUMPAD_7)
		head->draw->ang_x += 0.1;
	if (keycode == KEY_NUMPAD_4)
		head->draw->ang_x -= 0.1;
	// Rotate y
	if (keycode == KEY_NUMPAD_8)
		head->draw->ang_y += 0.1;
	if (keycode == KEY_NUMPAD_5)
		head->draw->ang_y -= 0.1;
	// Rotate z
	if (keycode == KEY_NUMPAD_9)
		head->draw->ang_z += 0.1;
	if (keycode == KEY_NUMPAD_6)
		head->draw->ang_z -= 0.1;

	if (keycode == KEY_PLUS) // Zoom in
		head->draw->zoom *= 1.1;
	if (keycode == KEY_MINUS && (head->draw->pad_y > 1 && head->draw->pad_x > 1)) // Zoom out
		head->draw->zoom /= 1.1;

	if (keycode == KEY_DOT)
		head->draw->pad_y += 1;
	if (keycode == KEY_COMMA)
		head->draw->pad_y -= 1;

	// Move
	if (keycode == KEY_ARROW_UP)
		head->draw->position.y += 2;
	if (keycode == KEY_ARROW_DOWN)
		head->draw->position.y -= 2;
	if (keycode == KEY_ARROW_RIGHT)
		head->draw->position.x += 2;
	if (keycode == KEY_ARROW_LEFT)
		head->draw->position.x -= 2;

	// deep
	if (keycode == KEY_COL_LEFT)
		head->draw->z += 2;
	if (keycode == KEY_COL_RIGHT)
		head->draw->z -= 2;
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(head->vars.mlx);
		return (0);
	}
	mlx_clear_window(head->vars.mlx, head->vars.win);
	render(head);
	return (0);
}

static int hook_window(int keycode, t_head * head)
{
	mlx_loop_end(head->vars.mlx);
	return (0);
}

void hooks(t_head * head)
{
	mlx_hook(head->vars.win, 17, 0L, hook_window, head);
	mlx_hook(head->vars.win, 2, 1L << 0, key_press, head);
}