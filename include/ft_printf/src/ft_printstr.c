/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printstr(const char *str)
{
	int	bytes;
	int	i;

	if (!str)
		return (ft_printstr("(null)"));
	bytes = 0;
	i = 0;
	while (str[i])
		bytes += ft_printchar(str[i++]);
	return (bytes);
}
