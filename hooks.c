/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:06:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/03 12:13:10 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int to_close(int keycode, t_hook * hooks)
{
	mlx_destroy_window(hooks->mlx, hooks->win);
	return (0);
}

void hooks(t_mlx * mlx)
{
	t_hook hooks;

	hooks.mlx = mlx->connection;
	hooks.win = mlx->window->_;

	mlx_hook(hooks.win, 2, 1L<<0, to_close, &hooks);
}