/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:29:39 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/28 00:11:22 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	aux_action(int keycode, t_head *head)
{
	if (keycode == KEY_TAB)
	{
		if (head->draw->plane_mode)
			head->draw->plane_mode = FALSE;
		else
			head->draw->plane_mode = TRUE;
	}
	if (keycode == KEY_CTRL)
		head->controls.is_on.key_ctrl = TRUE;
	if (keycode == KEY_ESC)
		end(head);
}