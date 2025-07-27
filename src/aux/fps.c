/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:59:00 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 11:27:28 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	fh_get_itoa_size(int number)
{
	int	i;

	i = 0;
	while (number > 0 && ++i)
		number /= 10;
	return (i);
}

static void	itoa_fps(t_fps *fps, int number)
{
	const int	size = fh_get_itoa_size(number);
	int			i;

	i = 0;
	while (i <= size)
		fps->fps_str[i++] = '\0';
	i = 0;
	while (i++ < size)
	{
		fps->fps_str[size - i] = number % 10 + '0';
		number /= 10;
	}
	while (i <= 5)
		fps->fps_str[i++] = '\0';
}

void	init_fps(t_fps *fps)
{
	gettimeofday(&fps->last_time, NULL);
	fps->frame_count = 0;
	fps->current_fps = 0;
	ft_bzero(fps->fps_str, 5);
}

void	update_fps(t_head *h, t_fps *fps)
{
	struct timeval	current_time;
	double			elapsed;

	fps->frame_count += 1;
	gettimeofday(&current_time, NULL);
	elapsed = (current_time.tv_sec - fps->last_time.tv_sec);
	elapsed += (current_time.tv_usec - fps->last_time.tv_usec) / 1000000.0;
	if (elapsed >= 1.0)
	{
		fps->current_fps = fps->frame_count;
		fps->frame_count = 0;
		fps->last_time = current_time;
		itoa_fps(fps, fps->current_fps);
	}
	mlx_string_put(h->vars.mlx, h->vars.win, VW - 60, 15, 0xFFFFFF, "FPS:");
	mlx_string_put(h->vars.mlx,
		h->vars.win,
		VW - 25,
		15,
		0xFFFF00,
		fps->fps_str);
}
