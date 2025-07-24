/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:29:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/24 16:31:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void paint_background(t_img * img)
{
	int x;
	int y;

	y = 0;
	while (y < MENU_H)
	{
		x = 0;
		while (x < MENU_W)
		{
			put_pixel_image(img, x, y, MENU_COLOR);
			x++;
		}
		y++;
	}
}

static draw_art(t_head *head, int line, char *str)
{

}

void menu(t_head * h)
{
	t_img	  menu_img;
	const int letter_size = 10;
	int		  line;

	ft_bzero(&menu_img, sizeof(menu_img));
	create_new_image(h->vars.mlx, &menu_img, MENU_W, MENU_H);
	paint_background(&menu_img);
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, menu_img.img, 0, 0);

	line = 1;
	mlx_string_put(h->vars.mlx, h->vars.win, 40, ++line * letter_size, 0xFFFFFF, " _____ ____  _____ ");
	mlx_string_put(h->vars.mlx, h->vars.win, 40, ++line * letter_size, 0xFFFFFF, "|  ___|  _ \\|  ___|");
	mlx_string_put(h->vars.mlx, h->vars.win, 40, ++line * letter_size, 0xFFFFFF, "| |_  | | | | |_   ");
	mlx_string_put(h->vars.mlx, h->vars.win, 40, ++line * letter_size, 0xFFFFFF, "|  _| | |_| |  _|  ");
	mlx_string_put(h->vars.mlx, h->vars.win, 40, ++line * letter_size, 0xFFFFFF, "|_|   |____/|_|    ");
	line += 5;
	mlx_string_put(h->vars.mlx, h->vars.win, 8 * letter_size, ++line * letter_size, 0xFFFFFF, "ROTATE");
	line++;
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "| Q |  | W |  | E |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	line++;
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "| A |  | S |  | D |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+---+  +---+  +---+");
	line += 5;
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      +------+");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  /\\  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+-----+      +-----+");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "|                  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "| <==          ==> |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "|                  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "+-----+      +-----+");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  ||  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      |  \\/  |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "      +------+");
	line += 5;
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "    +---+   +---+");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "    | + |   | - |");
	mlx_string_put(h->vars.mlx, h->vars.win, 4 * letter_size, ++line * letter_size, 0xFFFFFF, "    +---+   +---+");
}
