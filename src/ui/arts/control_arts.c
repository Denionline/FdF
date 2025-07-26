/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_arts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:32:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 12:51:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void get_aux_arts(t_arts * arts)
{
	static const char * const key_esc[4] = {
		"+---+",
		"|ESC|",
		"+---+",
		NULL};
	arts->key_esc.color = DEFAULT_KEY_COLOR;
	ft_memcpy(arts->key_esc.str, key_esc, sizeof(key_esc));
}

void get_zoom_arts(t_arts * arts)
{
	static const char * const key_plus[4] = {
		"+---+",
		"| + |",
		"+---+",
		NULL};
	static const char * const key_minus[4] = {
		"+---+",
		"| - |",
		"+---+",
		NULL};
	ft_memcpy(arts->key_plus.str, key_plus, sizeof(key_plus));
	ft_memcpy(arts->key_minus.str, key_minus, sizeof(key_minus));
}

void get_move_arts(t_arts * arts)
{
	static const char * const arrow_up[4] = {
		"+---+",
		"| ^ |",
		"+---+",
		NULL};
	static const char * const arrow_down[4] = {
		"+---+",
		"| v |",
		"+---+",
		NULL};
	static const char * const arrow_left[4] = {
		"+---+",
		"| < |",
		"+---+",
		NULL};
	static const char * const arrow_right[4] = {
		"+---+",
		"| > |",
		"+---+",
		NULL};
	ft_memcpy(arts->key_up.str, arrow_up, sizeof(arrow_up));
	ft_memcpy(arts->key_down.str, arrow_down, sizeof(arrow_down));
	ft_memcpy(arts->key_left.str, arrow_left, sizeof(arrow_left));
	ft_memcpy(arts->key_right.str, arrow_right, sizeof(arrow_right));
}

void get_rotation_arts_1(t_arts * arts)
{
	static const char * const key_q[4] = {
		"+---+",
		"| Q |",
		"+---+",
		NULL};
	static const char * const key_w[4] = {
		"+---+",
		"| W |",
		"+---+",
		NULL};
	static const char * const key_e[4] = {
		"+---+",
		"| E |",
		"+---+",
		NULL};
	ft_memcpy(arts->key_q.str, key_q, sizeof(key_q));
	ft_memcpy(arts->key_w.str, key_w, sizeof(key_w));
	ft_memcpy(arts->key_e.str, key_e, sizeof(key_e));
}

void get_rotation_arts_2(t_arts * arts)
{
	static const char * const key_a[4] = {
		"+---+",
		"| A |",
		"+---+",
		NULL};
	static const char * const key_s[4] = {
		"+---+",
		"| S |",
		"+---+",
		NULL};
	static const char * const key_d[4] = {
		"+---+",
		"| D |",
		"+---+",
		NULL};
	ft_memcpy(arts->key_a.str, key_a, sizeof(key_a));
	ft_memcpy(arts->key_s.str, key_s, sizeof(key_s));
	ft_memcpy(arts->key_d.str, key_d, sizeof(key_d));
}
