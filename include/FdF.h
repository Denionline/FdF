/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/06 23:35:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
#define FT_FDF

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft/include/libft.h"
#include "get_next_line/include/get_next_line.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

#define abs(value) ((value) < 0 ? -(value) : (value))

#define KEY_ESC 65307

#define KEY_PLUS 65451
#define KEY_MINUS 65453

#define KEY_ARROW_UP 65362
#define KEY_ARROW_DOWN 65364
#define KEY_ARROW_LEFT 65361
#define KEY_ARROW_RIGHT 65363

#define KEY_A 97
#define KEY_B 98
#define KEY_C 99
#define KEY_D 100

#define KEY_NUMPAD_1 65436
#define KEY_NUMPAD_2 65433
#define KEY_NUMPAD_3 65435
#define KEY_NUMPAD_4 65430
#define KEY_NUMPAD_5 65437
#define KEY_NUMPAD_6 65432
#define KEY_NUMPAD_7 65429
#define KEY_NUMPAD_8 65431
#define KEY_NUMPAD_9 65434

#define KEY_COL_LEFT 91
#define KEY_COL_RIGHT 93

#define KEY_DOT 44
#define KEY_COMMA 46

#define PI 3.14159

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
	t_axis position;
	double ang_y;
	double ang_x;
	double ang_2d; // ângulo de rotação 2D
	int	   color;
	int	   pad_y;
	int	   pad_x;
	int	   z;
	int	   loop;
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
	t_axis size;
} t_window;

typedef struct s_vars
{
	void * mlx;
	void * win;
} t_vars;

typedef struct s_head
{
	t_vars	   vars;
	t_map *	   map;
	t_window * window;
	t_draw *   draw;
} t_head;

// load_map.c
void load_map(t_map ** map, char * path);

// render.c
void render(t_head * mlx);

// hooks.c
void hooks(t_head * head);

#endif