/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:31:04 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:05:56 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char *argv[])
{
	t_head	*head;

	if (argc != 2)
		return (0);
	init_program(&head, argv[1]);
	load_map(head, argv[1]);
	init_menu(head);
	init_fps(&head->fps);
	hooks(head);
	return (0);
}
