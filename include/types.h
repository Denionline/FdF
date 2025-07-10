/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:20:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/10 16:26:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

#ifndef TYPES_H
#define TYPES_H

typedef struct s_pixel
{
	int x;
	int y;
	int z;
	int color;
} t_pixel;

typedef struct s_draw
{
	t_pixel _;
	t_pixel s0;
	t_pixel s1;
	t_pixel start;
	t_pixel position;
	double ang_x;
	double ang_y;
	double ang_z;
	double ang_2d;
	int	   color;
	int	   pad_y;
	int	   pad_x;
	int	   z;
	double projection[3][3];
	double values[3];
} t_draw;

typedef struct s_map
{
	t_pixel ** coordinates;
	char *	   path;
	t_pixel	   size;
} t_map;

typedef struct s_window
{
	t_pixel size;
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

#endif