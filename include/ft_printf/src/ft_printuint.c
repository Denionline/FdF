/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:07:21 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_uintsize(unsigned int n)
{
	size_t	size;

	size = 0;
	while (++size && n >= 10)
		n /= 10;
	return (size);
}

int	ft_printuint(unsigned int n)
{
	size_t	size;
	size_t	bytes;
	char	*string;

	size = ft_uintsize(n);
	string = (char *)malloc(size + 1);
	if (!string)
		return (0);
	string[size] = '\0';
	while (size--)
	{
		string[size] = (n % 10) + '0';
		n /= 10;
	}
	bytes = ft_printstr(string);
	return (free(string), bytes);
}
