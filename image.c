/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:54:56 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/16 12:26:54 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void create_new_image(t_head * head)
{
	if (head->draw->image.img)
		mlx_destroy_image(head->vars.mlx, head->draw->image.img);
	ft_bzero(&head->draw->image, sizeof(head->draw->image));
	head->draw->image.img = mlx_new_image(head->vars.mlx, VW, VH);
	head->draw->image.buffer = mlx_get_data_addr(
		head->draw->image.img,
		&head->draw->image.pixel_bits,
		&head->draw->image.line_bytes,
		&head->draw->image.endian);
}

void put_pixel_image(t_img * img, int x, int y, int color)
{
	char * dst;

	if (x < 0 || x >= VW || y < 0 || y >= VH)
		return;
	dst = img->buffer + (y * img->line_bytes + x * (img->pixel_bits / 8));
	*(unsigned int *)dst = color;
}