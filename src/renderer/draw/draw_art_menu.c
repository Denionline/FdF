/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_art_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:33:14 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:11:20 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	draw_art(t_head *h, int column, int row, t_vars_art art)
{
	int	i;

	i = 0;
	while (art.str[i])
	{
		mlx_string_put(h->vars.mlx,
			h->vars.win,
			column * LETTER_SIZE,
			(row + i) * LETTER_SIZE,
			art.color,
			(char *)art.str[i]);
		i++;
	}
	return (row + i);
}

static void	draw_zoom_arts(t_head *h, int default_column, int *row)
{
	*row = draw_art(h, default_column + 4, *row, h->menu.arts.zoom_title);
	*row += 1;
	draw_art(h, default_column + 2, *row, h->menu.arts.key_plus);
	draw_art(h, default_column + 6, *row, h->menu.arts.key_minus);
}

static void	draw_rotation_arts(t_head *h, int default_column, int *row)
{
	*row = draw_art(h, default_column + 3, *row, h->menu.arts.rotation_title);
	*row += 1;
	draw_art(h, default_column, *row, h->menu.arts.key_q);
	draw_art(h, default_column + 4, *row, h->menu.arts.key_w);
	*row = draw_art(h, default_column + 8, *row, h->menu.arts.key_e);
	draw_art(h, default_column, *row, h->menu.arts.key_a);
	draw_art(h, default_column + 4, *row, h->menu.arts.key_s);
	draw_art(h, default_column + 8, *row, h->menu.arts.key_d);
}

static void	draw_move_arts(t_head *h, int default_column, int *row)
{
	*row = draw_art(h, default_column + 4, *row, h->menu.arts.move_title);
	*row += 1;
	*row = draw_art(h, default_column + 4, *row, h->menu.arts.key_up);
	draw_art(h, default_column, *row, h->menu.arts.key_left);
	draw_art(h, default_column + 4, *row, h->menu.arts.key_down);
	draw_art(h, default_column + 8, *row, h->menu.arts.key_right);
}

void	draw_art_menu(t_head *h)
{
	const int	default_column = 4;
	int			row;

	row = 0;
	row = draw_art(h, default_column - 3, row + 1, h->menu.arts.key_esc);
	row = draw_art(h, default_column, row + 2, h->menu.arts.logo);
	row += 40;
	row = draw_art(h, default_column + 3, row, h->menu.arts.plane_mode);
	row += 1;
	draw_art(h, default_column + 4, row, h->menu.arts.key_tab);
	row += 6;
	draw_zoom_arts(h, default_column, &row);
	row += 6;
	draw_rotation_arts(h, default_column, &row);
	row += 6;
	draw_move_arts(h, default_column, &row);
}
