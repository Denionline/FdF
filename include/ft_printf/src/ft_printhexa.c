/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:28:10 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	fh_sizehexa(unsigned int nbr)
{
	size_t	i;

	i = 0;
	while (++i && nbr >= 16)
		nbr /= 16;
	return (i);
}

int	ft_printhexa(unsigned int n, int c)
{
	const char	*hexa = "0123456789abcdef";
	size_t		bytes;
	size_t		size;
	char		*buff;

	size = fh_sizehexa(n);
	buff = (char *)malloc(size + 1);
	if (!buff)
		return (0);
	buff[size] = '\0';
	while (size--)
	{
		if (c == 'X')
			buff[size] = ft_toupper((hexa)[n % 16]);
		else
			buff[size] = hexa[n % 16];
		n /= 16;
	}
	bytes = ft_printstr(buff);
	return (free(buff), bytes);
}
