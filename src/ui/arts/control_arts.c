/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_arts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:32:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 20:11:54 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	get_aux_arts(t_arts *arts)
{
	const char	*key_esc[4] = {"+---+", "|ESC| Exit", "+---+", NULL};
	const char	*key_tab[4] = {"+---+", "|TAB|", "+---+", NULL};

	arts->key_esc.color = 0xAF0000;
	arts->key_tab.color = DEFAULT_KEY_COLOR;
	ft_memcpy(arts->key_esc.str, key_esc, sizeof(key_esc));
	ft_memcpy(arts->key_tab.str, key_tab, sizeof(key_tab));
}

void	get_zoom_arts(t_arts *arts)
{
	const char	*k_plus[4] = {"+---+", "| + |", "+---+", NULL};
	const char	*k_minus[4] = {"+---+", "| - |", "+---+", NULL};

	ft_memcpy(arts->key_plus.str, k_plus, sizeof(k_plus));
	ft_memcpy(arts->key_minus.str, k_minus, sizeof(k_minus));
}

void	get_move_arts(t_arts *arts)
{
	const char	*up[4] = {"+---+", "| ^ |", "+---+", NULL};
	const char	*down[4] = {"+---+", "| v |", "+---+", NULL};
	const char	*left[4] = {"+---+", "| < |", "+---+", NULL};
	const char	*right[4] = {"+---+", "| > |", "+---+", NULL};

	ft_memcpy(arts->key_up.str, up, sizeof(up));
	ft_memcpy(arts->key_down.str, down, sizeof(down));
	ft_memcpy(arts->key_left.str, left, sizeof(left));
	ft_memcpy(arts->key_right.str, right, sizeof(right));
}

void	get_rotation_arts_1(t_arts *arts)
{
	const char	*key_q[4] = {"+---+", "| Q |", "+---+", NULL};
	const char	*key_w[4] = {"+---+", "| W |", "+---+", NULL};
	const char	*key_e[4] = {"+---+", "| E |", "+---+", NULL};

	ft_memcpy(arts->key_q.str, key_q, sizeof(key_q));
	ft_memcpy(arts->key_w.str, key_w, sizeof(key_w));
	ft_memcpy(arts->key_e.str, key_e, sizeof(key_e));
}

void	get_rotation_arts_2(t_arts *arts)
{
	const char	*key_a[4] = {"+---+", "| A |", "+---+", NULL};
	const char	*key_s[4] = {"+---+", "| S |", "+---+", NULL};
	const char	*key_d[4] = {"+---+", "| D |", "+---+", NULL};

	ft_memcpy(arts->key_a.str, key_a, sizeof(key_a));
	ft_memcpy(arts->key_s.str, key_s, sizeof(key_s));
	ft_memcpy(arts->key_d.str, key_d, sizeof(key_d));
}
