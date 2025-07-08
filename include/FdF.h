/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/08 15:11:15 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "ft_printf/include/ft_printf.h"
#include "ft_printf/include/libft/include/libft.h"
#include "get_next_line/include/get_next_line.h"
#include "keys.h"
#include "types.h"
#include "minilibx-linux/mlx.h"
#include <math.h>

#define abs(value) ((value) < 0 ? -(value) : (value))

#define PI 3.14159

// load_map.c
void load_map(t_map ** map, char * path);

// render.c
void render(t_head * mlx);

// hooks.c
void hooks(t_head * head);

t_axis mat_mult(double projection[2][3], t_axis values);

#endif