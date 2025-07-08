/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:20:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/08 17:45:24 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

#ifndef TYPES_H
#define TYPES_H

typedef struct s_axis
{
	int x;
	int y;
	int z;
	int color;
} t_axis;

typedef struct s_draw
{
	t_axis _;
	t_axis s0;
	t_axis s1;
	t_axis start;
	t_axis position;
	double ang_y;
	double ang_x;
	double ang_2d;
	int	   color;
	int	   pad_y;
	int	   pad_x;
	int	   z;
	double projection[2][3];
	double values[3];
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

#endif