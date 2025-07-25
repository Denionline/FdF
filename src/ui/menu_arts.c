/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_arts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:32:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/25 18:48:34 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void get_logo_art(t_head * head)
{
	static const char * const logo_src[6] = {
		" _____ ____  _____ ",
		"|  ___|  _ \\|  ___|",
		"| |_  | | | | |_   ",
		"|  _| | |_| |  _|  ",
		"|_|   |____/|_|    ",
		NULL};

	ft_memcpy(head->menu.arts.logo, logo_src, sizeof(logo_src));
}
