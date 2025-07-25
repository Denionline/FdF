/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:20:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/25 18:40:21 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

#ifndef TYPES_H
#define TYPES_H

typedef struct s_double_axis
{
	double x;
	double y;
	double z;
} t_double_axis;

typedef struct s_pixel
{
	int x;
	int y;
	int z;
	int color;
} t_pixel;

typedef struct s_fps
{
	struct timeval last_time;
	int			   frame_count;
	int			   current_fps;
	char		   fps_str[5];
} t_fps;

typedef struct s_img
{
	void * img;
	int	   pixel_bits;
	int	   line_bytes;
	int	   endian;
	char * buffer;
} t_img;

typedef struct s_arts
{
	const char * logo[20];
} t_arts;

typedef struct s_menu
{
	t_arts arts;
} t_menu;

typedef struct s_control
{
	t_double_axis rotation;
	t_double_axis position;
	t_pixel		  pad;
	double		  zoom;
	t_keys		  is_on;
} t_control;

typedef struct s_bresenham
{
	t_pixel delta;
	t_pixel direction;
	int		base_decision;
	int		decision;
} t_bresenham;

typedef struct s_draw
{
	t_double_axis ang;
	t_pixel		  position;
	t_pixel		  start;
	t_pixel		  pad;
	double		  projection[3][3];
	double		  values[3];
	double		  distance;
	double		  zoom;
	t_img		  image;

} t_draw;

typedef struct s_map
{
	t_pixel ** points;
	char *	   path;
	t_pixel	   size;
} t_map;

typedef struct s_vars
{
	void * mlx;
	void * win;
} t_vars;

typedef struct s_head
{
	t_vars	  vars;
	t_map *	  map;
	t_draw *  draw;
	t_fps	  fps;
	t_menu	  menu;
	t_control controls;
} t_head;

#endif