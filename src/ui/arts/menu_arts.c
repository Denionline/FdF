/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_arts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:32:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 12:49:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void get_logo_art(t_arts * arts)
{
	static const char * const logo_src[6] = {
		" _____ ____  _____ ",
		"|  ___|  _ \\|  ___|",
		"| |_  | | | | |_   ",
		"|  _| | |_| |  _|  ",
		"|_|   |____/|_|    ",
		NULL};
	arts->logo.color = DEFAULT_KEY_COLOR;
	ft_memcpy(arts->logo.str, logo_src, sizeof(logo_src));
}

void get_title_art(t_arts * arts)
{
	static const char * const zoom_title[4] = {
		"ZOOM",
		NULL};
	static const char * const rotation_title[4] = {
		"ROTATION",
		NULL};
	static const char * const move_title[4] = {
		"MOVE",
		NULL};
	arts->zoom_title.color = DEFAULT_KEY_COLOR;
	arts->rotation_title.color = DEFAULT_KEY_COLOR;
	arts->move_title.color = DEFAULT_KEY_COLOR;
	ft_memcpy(arts->zoom_title.str, zoom_title, sizeof(zoom_title));
	ft_memcpy(arts->rotation_title.str, rotation_title, sizeof(rotation_title));
	ft_memcpy(arts->move_title.str, move_title, sizeof(move_title));
}
