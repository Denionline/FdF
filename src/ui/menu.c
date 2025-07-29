/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:29:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:11:47 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	paint_background(t_img *img)
{
	int	x;
	int	y;

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

void	menu(t_head *h)
{
	create_new_image(h->vars.mlx, &h->menu.image, MENU_W, MENU_H);
	paint_background(&h->menu.image);
	mlx_put_image_to_window(h->vars.mlx,
		h->vars.win,
		h->menu.image.img,
		0,
		0);
	draw_art_menu(h);
}
