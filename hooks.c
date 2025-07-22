/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:06:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/22 12:47:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int mouse_release(int button, int x, int y, t_head * head)
{
	if (button == MOUSE_LEFT_CLICK)
	{
		head->controls.is_on.mouse_left_click = FALSE;
		head->controls.rotation.x = 0;
		head->controls.rotation.y = 0;
	}
	return (0);
}

static int mouse_press(int button, int x, int y, t_head * head)
{
	if (button == MOUSE_SCROLL_UP && head->controls.is_on.key_ctrl)
		head->controls.zoom = 0.05;
	if (button == MOUSE_SCROLL_DOWN && head->controls.is_on.key_ctrl)
		head->controls.zoom = -0.05;
	if (button == MOUSE_LEFT_CLICK)
		head->controls.is_on.mouse_left_click = TRUE;
	return (0);
}

static int mouse_move(int x, int y, t_head * head)
{
	if (head->controls.is_on.mouse_left_click)
	{
		x -= (VW / 2);
		if (x > 0 && x < (head->map->size.x * head->draw->pad_x))
			head->controls.rotation.x = x * 0.0001;
		if (x < 0 && (x * -1) < (head->map->size.x * head->draw->pad_x))
			head->controls.rotation.x = x * -0.0001;
		y -= (VH / 2);
		if (y > 0 && y < (head->map->size.y * head->draw->pad_y))
			head->controls.rotation.y = y * 0.0001;
		if (y < 0 && (y * -1) < (head->map->size.y * head->draw->pad_y))
			head->controls.rotation.y = y * -0.0001;
	}
	return (0);
}

static int key_release(int keycode, t_head * head)
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
	return (0);
}
static int key_press(int keycode, t_head * head)
{
	// printf("%d\n", keycode);
	if (keycode == KEY_W)
		head->controls.rotation.x = 0.01;
	else if (keycode == KEY_S)
		head->controls.rotation.x = -0.01;
	if (keycode == KEY_D)
		head->controls.rotation.y = 0.01;
	else if (keycode == KEY_A)
		head->controls.rotation.y = -0.01;
	if (keycode == KEY_E)
		head->controls.rotation.z = 0.01;
	else if (keycode == KEY_Q)
		head->controls.rotation.z = -0.01;

	if (keycode == KEY_PLUS)
		head->controls.zoom = 0.05;
	else if (keycode == KEY_MINUS)
		head->controls.zoom = -0.05;

	if (keycode == KEY_ARROW_UP)
		head->controls.position.y = -1;
	else if (keycode == KEY_ARROW_DOWN)
		head->controls.position.y = 1;
	if (keycode == KEY_ARROW_RIGHT)
		head->controls.position.x = 1;
	else if (keycode == KEY_ARROW_LEFT)
		head->controls.position.x = -1;

	if (keycode == KEY_CTRL)
		head->controls.is_on.key_ctrl = TRUE;
	if (keycode == KEY_ESC)
		mlx_loop_end(head->vars.mlx);
	return (0);
}

static int hook_window(int keycode, t_head * head)
{
	mlx_loop_end(head->vars.mlx);
	return (0);
}

void hooks(t_head * head)
{
	mlx_hook(head->vars.win, 2, 1L << 0, key_press, head);	   // Teclas pressionadas
	mlx_hook(head->vars.win, 3, 1L << 1, key_release, head);   // Teclas liberadas
	mlx_hook(head->vars.win, 17, 1L << 17, hook_window, head); // Fechar janela
	mlx_hook(head->vars.win, 5, 1L << 3, mouse_release, head); // Botões liberados
	mlx_hook(head->vars.win, 4, 1L << 2, mouse_press, head);   // Botões do mouse
	mlx_hook(head->vars.win, 6, 1L << 6, mouse_move, head);	   // Movimento do mouse
	mlx_loop_hook(head->vars.mlx, render, head);
}
