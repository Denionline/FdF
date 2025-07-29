/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:33:48 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	fh_parse_flags(t_flag *f, const char **s)
{
	while (**s && !ft_strchr(".cspdiuxX%123456789", **s))
	{
		if (**s == '-')
			f->minus = (++f->is_there_flags > 0);
		else if (**s == '+')
			f->plus = (++f->is_there_flags > 0);
		else if (**s == ' ')
			f->space = (++f->is_there_flags > 0);
		else if (**s == '0')
			f->zero = (++f->is_there_flags > 0);
		else if (**s == '#')
			f->hash = (++f->is_there_flags > 0);
		(*s)++;
	}
	if (ft_isdigit(**s))
		f->width = ft_atoi(*s);
	while (ft_isdigit(**s))
		*s += 1;
	if (**s == '.')
	{
		f->dot = (++f->is_there_flags);
		while (ft_isdigit(*(++*s)))
			f->precision = f->precision * 10 + (**s - '0');
	}
	f->is_there_flags += (f->width > 0 || f->precision > 0);
}

static size_t	fh_printsy(int sy, va_list args)
{
	if (sy == 's')
		return (ft_printstr(va_arg(args, char *)));
	if (sy == 'c')
		return (ft_printchar((char)va_arg(args, int)));
	if (sy == '%')
		return (ft_printchar(sy));
	if (sy == 'u')
		return (ft_printuint(va_arg(args, unsigned int)));
	if (sy == 'p')
		return (ft_printptr(va_arg(args, void *)));
	if (sy == 'd' || sy == 'i')
		return (ft_printnbr(va_arg(args, int)));
	if (sy == 'x' || sy == 'X')
		return (ft_printhexa(va_arg(args, int), sy));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	bytes;
	t_flag	flags;

	va_start(args, format);
	bytes = 0;
	while (*format)
	{
		if (*format == '%' && *(format++))
		{
			ft_memset(&flags, 0, sizeof(flags));
			fh_parse_flags(&flags, &format);
			if (flags.is_there_flags)
				bytes += ft_printflags(*format++, args, &flags);
			else
				bytes += fh_printsy(*format++, args);
		}
		else
			bytes += ft_printchar(*(format++));
	}
	va_end(args);
	return (bytes);
}
