/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:59:00 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/20 20:26:05 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void init_fps(t_fps * fps)
{
	gettimeofday(&fps->last_time, NULL);
	fps->frame_count = 0;
	fps->current_fps = 0;
	ft_bzero(fps->fps_str, 20);
}

void update_fps(t_fps * fps)
{
	struct timeval current_time;
	double		   elapsed;

	fps->frame_count += 1;
	gettimeofday(&current_time, NULL);

	elapsed = (current_time.tv_sec - fps->last_time.tv_sec) + (current_time.tv_usec - fps->last_time.tv_usec) / 1000000.0;

	printf("%.2f\n", elapsed);
	if (elapsed >= 1.0)
	{
		fps->current_fps = fps->frame_count;
		fps->frame_count = 0;
		fps->last_time = current_time;
		printf("%d\n", fps->current_fps);
	}
}