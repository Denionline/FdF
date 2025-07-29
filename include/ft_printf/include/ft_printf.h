/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:42:07 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/18 16:16:37 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft/include/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_flag
{
	int		is_there_flags;
	int		minus;
	int		negative;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		width;
	int		precision;
	int		dot;
	int		pad;
	char	sy;
}	t_flag;

int		ft_printf(const char *format, ...);

int		ft_printchar(int c);
int		ft_printhexa(unsigned int n, int c);
int		ft_printstr(const char *str);
int		ft_printnbr(int nbr);
int		ft_printptr(void *addr);
int		ft_printuint(unsigned int n);

int		ft_printflags(int sy, va_list args, t_flag *flags);
char	*ft_handlechar(int c);
char	*ft_handlehexa(unsigned int n, int c, t_flag *f);
char	*ft_handlestr(const char *str, t_flag *f);
char	*ft_handlenbr(int nbr, t_flag *f);
char	*ft_handleptr(void *addr, t_flag *f);
char	*ft_handleuint(unsigned int n, t_flag *f);

#endif
