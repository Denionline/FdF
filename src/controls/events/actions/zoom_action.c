/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:09:29 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 18:13:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	zoom_action(int keycode, t_control *control)
{
	if (keycode == KEY_PLUS)
		control->zoom = 0.05;
	else if (keycode == KEY_MINUS)
		control->zoom = -0.05;
}
