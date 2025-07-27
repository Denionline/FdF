/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:20:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 20:03:48 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "FdF.h"

typedef double	t_rotate3[3];

typedef struct s_double_axis
{
	double	x;
	double	y;
	double	z;
}	t_double_axis;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_pixel;

typedef struct s_fps
{
	struct timeval	last_time;
	int				frame_count;
	int				current_fps;
	char			fps_str[5];
}	t_fps;

typedef struct s_img
{
	void	*img;
	int		bits;
	int		line_bytes;
	int		end;
	char	*buffer;
}	t_img;

typedef struct s_vars_art
{
	const char	*str[20];
	int			color;
}	t_vars_art;

typedef struct s_arts
{
	t_vars_art	logo;
	t_vars_art	zoom_title;
	t_vars_art	rotation_title;
	t_vars_art	move_title;
	t_vars_art	plane_mode;
	t_vars_art	key_tab;
	t_vars_art	key_esc;
	t_vars_art	key_up;
	t_vars_art	key_down;
	t_vars_art	key_left;
	t_vars_art	key_right;
	t_vars_art	key_q;
	t_vars_art	key_w;
	t_vars_art	key_e;
	t_vars_art	key_a;
	t_vars_art	key_s;
	t_vars_art	key_d;
	t_vars_art	key_plus;
	t_vars_art	key_minus;
}	t_arts;

typedef struct s_menu
{
	t_arts	arts;
}	t_menu;

typedef struct s_control
{
	t_double_axis	rotation;
	t_double_axis	position;
	t_pixel			pad;
	double			zoom;
	t_keys			is_on;
}	t_control;

typedef struct s_bresenham
{
	t_pixel	delta;
	t_pixel	direction;
	int		base_decision;
	int		decision;
}	t_bresenham;

typedef struct s_draw
{
	t_double_axis	ang;
	t_pixel			position;
	t_pixel			start;
	t_pixel			pad;
	double			projection[3][3];
	double			values[3];
	double			zoom;
	t_img			image;
	int				plane_mode;

}	t_draw;

typedef struct s_map
{
	t_pixel	**points;
	char	*path;
	t_pixel	size;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_head
{
	t_vars		vars;
	t_map		*map;
	t_draw		*draw;
	t_fps		fps;
	t_menu		menu;
	t_control	controls;
}	t_head;

#endif