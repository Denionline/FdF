/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_art_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:01:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/24 18:18:18 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void draw_logo(t_head * h, int * line)
{
	const char * logo[] = {" _____ ____  _____ ",
						   "|  ___|  _ \\|  ___|",
						   "| |_  | | | | |_   ",
						   "|  _| | |_| |  _|  ",
						   "|_|   |____/|_|    ",
						   NULL};
	int			 i;

	i = 0;
	while (logo[i])
	{
		mlx_string_put(h->vars.mlx,
					   h->vars.win,
					   4 * LETTER_SIZE,
					   ++*line * LETTER_SIZE,
					   0xFFFFFF,
					   (char *)logo[i]);
		i++;
	}
}

void draw_art_menu(t_head * h)
{
	int line;

	line = 2;
	draw_logo(h, &line);
	draw_button(h, );
}

	// line += 5;
	// mlx_string_put(h->vars.mlx, h->vars.win, 8 * letter_size, ++line * letter_size, 0xFFFFFF, "ROTATE");
	// line++;
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "| Q |  | W |  | E |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	// line++;
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "| A |  | S |  | D |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	// line += 5;
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      +------+");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  /\\  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+-----+      +-----+");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "|                  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "| <==          ==> |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "|                  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+-----+      +-----+");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  \\/  |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      +------+");
	// line += 5;
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "    +---+   +---+");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "    | + |   | - |");
	// mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "    +---+   +---+");