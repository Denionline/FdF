/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/24 22:53:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
#define FT_FDF

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft/include/libft.h"
#include "get_next_line/include/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>

# define abs(value) ((value) < 0 ? -(value) : (value))

typedef struct s_axis
{
	int x;
	int y;
} t_axis;

typedef struct s_draw
{
	t_axis dot;
	t_axis line;
	t_axis off;
	int	   color;
	int	   pad;
} t_draw;

typedef struct s_map
{
	int ** coordinates;
	char * path;
	t_axis size;
} t_map;

typedef struct s_window
{
	void * content;
	t_axis size;
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