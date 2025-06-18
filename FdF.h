/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/18 22:55:50 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
# define FT_FDF

typedef struct s_window
{
	int	viewport_y;
	int	viewport_x;
	int	square_min_y;
	int	square_max_y;
	int	square_min_x;
	int	square_max_x;
}	t_window;


#endif