/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:54:56 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 10:11:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	create_new_image(void *mlx, t_img *img, int width, int height)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	img->img = mlx_new_image(mlx, width, height);
	img->buffer = mlx_get_data_addr(
		img->img,
		&img->bits,
		&img->line_bytes,
		&img->end
	);
}

void	put_pixel_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= VW || y < 0 || y >= VH)
		return ;
	dst = img->buffer + (y * img->line_bytes + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}
