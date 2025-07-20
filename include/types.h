/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:20:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/20 11:06:30 by dximenes         ###   ########.fr       */
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

typedef struct s_fps
{
	clock_t last_time;
	int		frame_count;
	int		current_fps;
	char	fps_str[20];
} t_fps;

typedef struct s_img
{
	void * img;
	int	   pixel_bits;
	int	   line_bytes;
	int	   endian;
	char * buffer;
} t_img;

typedef struct s_bresenham
{
	t_pixel delta;
	t_pixel direction;
	int		base_decision;
	int		decision;
} t_bresenham;

typedef struct s_draw
{
	t_pixel start;
	t_pixel position;
	double	ang_x;
	double	ang_y;
	double	ang_z;
	double	distance;
	double	zoom;
	double	margin;
	int		color;
	int		pad_y;
	int		pad_x;
	double	projection[3][3];
	double	values[3];
	t_img	image;

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