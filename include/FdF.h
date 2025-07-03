/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/02 17:39:40 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
#define FT_FDF

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft/include/libft.h"
#include "get_next_line/include/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

#define abs(value) ((value) < 0 ? -(value) : (value))

typedef struct s_axis
{
	int x;
	int y;
} t_axis;

typedef struct s_draw
{
	t_axis _;
	t_axis s0;
	t_axis s1;
	t_axis off;
	int	   color;
	int	   pad;
} t_draw;

typedef struct s_point
{
	int z;
	int color;
} t_point;

typedef struct s_map
{
	t_point ** coordinates;
	char *	   path;
	t_axis	   size;
} t_map;

typedef struct s_window
{
	void * _;
	t_axis size;
} t_window;

typedef struct s_mlx
{
	void *	   connection;
	t_map *	   map;
	t_window * window;
	t_draw *   draw;
} t_mlx;

// load_map.c
void load_map(t_map ** map, char *path);

// render.c
void render(t_mlx * mlx);

// draw.c
void draw(t_mlx * mlx, t_draw * dw);

#endif