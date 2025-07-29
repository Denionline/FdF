/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:42:34 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*fh_getstring(va_list args, t_flag *f)
{
	if (f->sy == 's')
		return (ft_handlestr(va_arg(args, char *), f));
	if (f->sy == 'c')
		return (ft_handlechar((char)va_arg(args, int)));
	if (f->sy == 'u')
		return (ft_handleuint(va_arg(args, unsigned int), f));
	if (f->sy == 'p')
		return (ft_handleptr(va_arg(args, void *), f));
	if (f->sy == 'd' || f->sy == 'i')
		return (ft_handlenbr(va_arg(args, int), f));
	if (f->sy == 'x' || f->sy == 'X')
		return (ft_handlehexa(va_arg(args, int), f->sy, f));
	return (NULL);
}

static char	*fh_getprefix(int c, t_flag *f)
{
	char	*prefix;
	int		lprefix;

	lprefix = 0;
	prefix = ft_strdup("--");
	if (!prefix)
		return (NULL);
	if ((f->sy == 'i' || f->sy == 'd') && !f->negative)
	{
		if (f->plus)
			prefix[lprefix++] = '+';
		if (f->space)
			prefix[lprefix++] = ' ';
	}
	if (f->hash && c != '0')
	{
		prefix[lprefix++] = '0';
		if (f->sy == 'x' || f->sy == 'X')
			prefix[lprefix++] = f->sy;
		if (f->sy == 'p')
			prefix[lprefix++] = 'x';
	}
	prefix[lprefix] = 0;
	return (prefix);
}

static void	fh_setwp(char *string, int len, t_flag *f)
{
	int	p;

	p = 0;
	if (f->dot && f->sy == 's')
	{
		if (!ft_strncmp(string, "(null)", 6) && f->precision < 6)
			len = 0;
		else if (f->precision < len)
			len = f->precision;
		string[len] = '\0';
	}
	else if (f->precision > 0)
	{
		if (f->precision > len)
		{
			p = f->precision - len;
			len = f->precision;
		}
	}
	f->precision = p;
	if (f->width)
		f->width -= (len + f->negative);
}

static int	fh_putall(char *s, char *pre, t_flag *f)
{
	int	bytes;
	int	i;

	bytes = 0;
	if (f->negative && f->pad == '0')
		bytes += ft_printchar('-');
	if (f->width > 0 && !f->minus)
		while (f->width--)
			bytes += ft_printchar(f->pad);
	if (f->negative && f->pad == ' ')
		bytes += ft_printchar('-');
	i = 0;
	while (pre[i] != '\0')
		bytes += ft_printchar(pre[i++]);
	if (f->precision)
		while (f->precision--)
			bytes += ft_printchar('0');
	if (f->sy == 'c' && s[0] == '\0')
		bytes += ft_printchar('\0');
	else
		bytes += ft_printstr(s);
	if (f->width > 0 && f->minus)
		while (f->width--)
			bytes += ft_printchar(f->pad);
	return (bytes);
}

int	ft_printflags(int sy, va_list args, t_flag *flags)
{
	char	*string;
	char	*prefix;
	int		bytes;

	flags->sy = sy;
	if (flags->sy == '%')
		return (ft_printchar('%'));
	string = fh_getstring(args, flags);
	if (!string)
		return (0);
	prefix = fh_getprefix(string[0], flags);
	fh_setwp(string, ft_strlen(string), flags);
	if (flags->sy == 'c' && string[0] == '\0')
		flags->width--;
	if (flags->zero && !flags->minus && !flags->hash && !flags->dot)
		flags->pad = '0';
	else
		flags->pad = ' ';
	flags->width -= ft_strlen(prefix);
	bytes = fh_putall(string, prefix, flags);
	free(string - flags->negative);
	free(prefix);
	return (bytes);
}
