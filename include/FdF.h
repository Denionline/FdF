/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/19 18:09:39 by dximenes         ###   ########.fr       */
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
#include <sys/time.h>

#define PI 3.14159
#define VW 1440
#define VH 900

// load_map.c
void load_map(t_map ** map, char * path);

// render.c
void render(t_head * mlx);

// image.c
void create_new_image(t_head * head);
void put_pixel_image(t_img * img, int x, int y, int color);

// draw.c
void draw(t_head * head, int y, int x);

// color.c
int get_color_between(int color1, int color2, int step, int steps);

// bresenham.c
void bresenham(t_head * head, t_pixel s0, t_pixel s1);

// hooks.c
void hooks(t_head * head);

// verify.c
void end(t_head * head);

// rotate.c
double (*rotate_x(t_head * head))[3];
double (*rotate_y(t_head * head))[3];
double (*rotate_z(t_head * head))[3];

// math.c
int		absolute(int number);
int		get_bigger_abs(int number1, int number2);
t_pixel mat_mult(double projection[3][3], t_pixel values);

#endif