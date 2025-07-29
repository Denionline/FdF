/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlestr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/22 23:37:30 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_handlestr(const char *str, t_flag *f)
{
	char	*new;

	if (!str)
		return (ft_strdup("(null)"));
	if (f->dot && !(f->precision > 0))
		return (ft_strdup(""));
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	return (new);
}
