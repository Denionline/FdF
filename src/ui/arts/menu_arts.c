/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_arts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:32:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 20:12:32 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	get_logo_art(t_arts *arts)
{
	char	*logo_src[6];

	logo_src[0] = " _____ ____  _____ ";
	logo_src[1] = "|  ___|  _ \\|  ___|";
	logo_src[2] = "| |_  | | | | |_   ";
	logo_src[3] = "|  _| | |_| |  _|  ";
	logo_src[4] = "|_|   |____/|_|    ";
	logo_src[5] = NULL;
	arts->logo.color = 0x0000FF;
	ft_memcpy(arts->logo.str, logo_src, sizeof(logo_src));
}

void	get_title_art(t_arts *arts)
{
	const char	*zoom_title[4] = {"ZOOM", NULL};
	const char	*rotate_title[4] = {"ROTATION", NULL};
	const char	*move_title[4] = {"MOVE", NULL};
	const char	*plane_mode[4] = {"PLANE MODE", NULL};

	arts->zoom_title.color = DEFAULT_KEY_COLOR;
	arts->rotation_title.color = DEFAULT_KEY_COLOR;
	arts->move_title.color = DEFAULT_KEY_COLOR;
	arts->plane_mode.color = DEFAULT_KEY_COLOR;
	ft_memcpy(arts->zoom_title.str, zoom_title, sizeof(zoom_title));
	ft_memcpy(arts->rotation_title.str, rotate_title, sizeof(rotate_title));
	ft_memcpy(arts->move_title.str, move_title, sizeof(move_title));
	ft_memcpy(arts->plane_mode.str, plane_mode, sizeof(plane_mode));
}
