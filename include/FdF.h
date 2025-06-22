/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 20:26:00 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
#define FT_FDF

#include "get_next_line/include/get_next_line.h"
#include "libft/include/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_draw
{
	int x0;
	int x1;
	int y0;
	int y1;
	int pad;
} t_draw;

typedef struct s_map
{
	int ** coordinates;
	char * path;
	int	   size_x;
	int	   size_y;
} t_map;

typedef struct s_window
{
	void * content;
	int	   vh;
	int	   vw;
} t_window;

typedef struct s_mlx
{
	void *	   connection;
	t_map *	   map;
	t_window * window;
	t_draw *   draw;
} t_mlx;

void render(t_mlx * mlx);
void load_map(t_map ** map);

#endif