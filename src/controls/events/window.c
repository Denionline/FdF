/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:09:27 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 18:10:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	hook_window(int keycode, t_head *head)
{
	if (keycode)
		mlx_loop_end(head->vars.mlx);
	return (0);
}
