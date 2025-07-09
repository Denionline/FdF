/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/09 17:03:45 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft/include/libft.h"
#include "get_next_line/include/get_next_line.h"
#include "keys.h"
#include "minilibx-linux/mlx.h"
#include "types.h"
#include <math.h>

#define abs(value) ((value) < 0 ? -(value) : (value))

#define PI 3.14159

// load_map.c
void load_map(t_map ** map, char * path);

// render.c
void render(t_head * mlx);

// draw.c
void draw(t_head * head, int y, int x);

// bresenham.c
void bresenham(t_head * head, t_pixel s0, t_pixel s1);

// hooks.c
void hooks(t_head * head);

// math.c
t_pixel mat_mult(double projection[3][3], t_pixel values);
void rotate_x(t_head * head);
void rotate_y(t_head * head);
void rotate_z(t_head * head);

#endif