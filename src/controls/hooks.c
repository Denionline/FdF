/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:06:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 18:10:05 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	hooks(t_head *head)
{
	mlx_hook(head->vars.win, 2, 1L << 0, key_press, head);
	mlx_hook(head->vars.win, 3, 1L << 1, key_release, head);
	mlx_hook(head->vars.win, 5, 1L << 3, mouse_release, head);
	mlx_hook(head->vars.win, 4, 1L << 2, mouse_press, head);
	mlx_hook(head->vars.win, 6, 1L << 6, mouse_move, head);
	mlx_hook(head->vars.win, 17, 1L << 17, hook_window, head);
	mlx_loop_hook(head->vars.mlx, render, head);
}
