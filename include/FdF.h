/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/20 18:49:41 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
#define FT_FDF

#include "minilibx-linux/mlx.h"
#include "get_next_line/include/get_next_line.h"
#include "libft/include/libft.h"
#include <stdlib.h>

typedef struct s_map
{
	int ** coordinates;
	char * path;
	int	   size_x;
	int	   size_y;
} t_map;

typedef struct s_window
{
	void * content;
	int	   vh;
	int	   vw;
} t_window;

typedef struct s_mlx
{
	void *	   connection;
	t_window * window;
	t_map *	   map;
} t_mlx;

void render(t_mlx * mlx);
void load_map(t_map ** map);

#endif