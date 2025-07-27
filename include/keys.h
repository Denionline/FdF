/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:55:24 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 19:35:50 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "FdF.h"

typedef struct s_keys
{
	int	mouse_left_click;
	int	key_ctrl;
	int	any;
}	t_keys;

# define KEY_TAB 65289
# define KEY_ESC 65307
# define KEY_CTRL 65507

# define KEY_PLUS 65451
# define KEY_MINUS 65453

# define KEY_ARROW_UP 65362
# define KEY_ARROW_DOWN 65364
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_RIGHT 65363

# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_D 100
# define KEY_E 101
# define KEY_Q 113
# define KEY_S 115
# define KEY_W 119

# define KEY_NUMPAD_1 65436
# define KEY_NUMPAD_2 65433
# define KEY_NUMPAD_3 65435
# define KEY_NUMPAD_4 65430
# define KEY_NUMPAD_5 65437
# define KEY_NUMPAD_6 65432
# define KEY_NUMPAD_7 65429
# define KEY_NUMPAD_8 65431
# define KEY_NUMPAD_9 65434

# define KEY_COL_LEFT 91
# define KEY_COL_RIGHT 93

# define KEY_DOT 44
# define KEY_COMMA 46

# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

#endif