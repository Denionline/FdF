/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:37:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/27 19:32:33 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/include/ft_printf.h"
# include "ft_printf/include/libft/include/libft.h"
# include "get_next_line/include/get_next_line.h"
# include "keys.h"
# include "minilibx-linux/mlx.h"
# include "types.h"
# include <math.h>
# include <sys/time.h>

# define PI 3.14159
# define VW 1440
# define VH 900

# define MENU_W 200
# define MENU_H 900

# define MAX_ZOOM 50.0
# define MIN_ZOOM 0.2
# define BIGGEST_SIZE 250.00
# define SMALLEST_SIZE 10.0
# define MAX_PADZ 10.00
# define MIN_PADZ 1.0

# define COLOR 1023961
# define HIGH_COLOR 16711680
# define MENU_COLOR 2236962
# define DEFAULT_KEY_COLOR 16777215
# define ACTIVE_KEY_COLOR 718102

# define LETTER_SIZE 10

// src/aux/get
char		*get_map_name(char *path);
int			get_max_z(t_pixel **pixels, int size_x, int size_y);

// src/initializers.c
void		init_program(t_head **head, char *path);
void		init_menu(t_head *head);

// src/ui/menu.c
void		menu(t_head *head);

// src/ui/menu_arts.c
void		get_logo_art(t_arts *arts);
void		get_title_art(t_arts *arts);

// src/ui/control_arts.c
void		get_aux_arts(t_arts *arts);
void		get_zoom_arts(t_arts *arts);
void		get_move_arts(t_arts *arts);
void		get_rotation_arts_1(t_arts *arts);
void		get_rotation_arts_2(t_arts *arts);

// src/ui/draw_art_menu.c
void		draw_art_menu(t_head *h);

// load_map.c
void		load_map(t_head *head, char *path);

// render.c
int			render(t_head *mlx);

// image.c
void		create_new_image(void *mlx, t_img *image, int width, int height);
void		put_pixel_image(t_img *img, int x, int y, int color);

// draw.c
void		draw_map(t_head *head);

// color.c
int			get_color_between(int color1, int color2, int step, int steps);
void		set_color_top(t_pixel **pixels, int size_x, int size_y);

// bresenham.c
void		bresenham(t_head *head, t_pixel s0, t_pixel s1);

// src/controls/
void		transform(t_head *head);
void		hooks(t_head *head);

// src/controls/events/
int			hook_window(int keycode, t_head *head);
int			mouse_move(int x, int y, t_head *head);
int			mouse_press(int button, int x, int y, t_head *head);
int			mouse_release(int button, int x, int y, t_head *head);
int			key_release(int keycode, t_head *head);
int			key_press(int keycode, t_head *head);

// src/controls/events/actions
void		rotate_action(int keycode, t_control *control);
void		move_action(int keycode, t_control *control);
void		zoom_action(int keycode, t_control *control);
void		aux_action(int keycode, t_head *head);

// verify.c
void		end(t_head *head);

// fps.c
void		init_fps(t_fps *fps);
void		update_fps(t_head *head, t_fps *fps);

// rotate.c
t_rotate3	*rotate_x(t_head *head);
t_rotate3	*rotate_y(t_head *head);
t_rotate3	*rotate_z(t_head *head);

// math.c
int			absolute(int number);
double		absolute_double(double number);
t_pixel		mat_mult(double projection[3][3], t_pixel values);

#endif