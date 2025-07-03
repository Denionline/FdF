/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:06:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/03 15:43:32 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int key_press(int keycode, t_head * head)
{
	// ft_printf("Keycode => %d\n", keycode);
	if (keycode == KEY_PLUS)
		head->draw->pad += 1;
		if (keycode == KEY_MINUS && head->draw->pad > 1)
		head->draw->pad -= 1;

	if (keycode == KEY_ARROW_UP)
		head->draw->position.y += 2;
	if (keycode == KEY_ARROW_DOWN)
		head->draw->position.y -= 2;
	if (keycode == KEY_ARROW_RIGHT)
		head->draw->position.x += 2;
	if (keycode == KEY_ARROW_LEFT)
		head->draw->position.x -= 2;

	if (keycode == KEY_COL_LEFT)
		head->draw->z += 2;
	if (keycode == KEY_COL_RIGHT)
		head->draw->z -= 2;
	if (keycode == KEY_ESC)
	{
		head->draw->loop = FALSE;
		mlx_loop_end(head->vars.mlx);
		mlx_destroy_window(head->vars.mlx, head->vars.win);
		return (0);
	}
	mlx_clear_window(head->vars.mlx, head->vars.win);
	render(head);
	return (0);
}

void hooks(t_head * head)
{
	mlx_hook(head->vars.win, 2, 1L << 0, key_press, head);
}