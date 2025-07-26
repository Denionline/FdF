/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:54:56 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/24 13:58:11 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void create_new_image(void *mlx, t_img * image, int width, int height)
{
	if (image->img)
		mlx_destroy_image(mlx, image->img);
	ft_bzero(image, sizeof(*image));
	image->img = mlx_new_image(mlx, width, height);
	image->buffer = mlx_get_data_addr(
		image->img,
		&image->pixel_bits,
		&image->line_bytes,
		&image->endian);
}

void put_pixel_image(t_img * img, int x, int y, int color)
{
	char * dst;

	if (x < 0 || x >= VW || y < 0 || y >= VH)
		return;
	dst = img->buffer + (y * img->line_bytes + x * (img->pixel_bits / 8));
	*(unsigned int *)dst = color;
}