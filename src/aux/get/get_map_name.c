/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:04:09 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/26 13:08:58 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

char * get_map_name(char * path)
{
	char ** path_sep;
	char *	fdf_file;
	int		i;

	path_sep = ft_split(path, '/');
	fdf_file = NULL;
	i = 0;
	while (path_sep[i])
	{
		if (ft_strnstr(path_sep[i], ".fdf", ft_strlen(path_sep[i])))
			fdf_file = path_sep[i];
		else
			free(path_sep[i]);
		i++;
	}
	free(path_sep);
	return (fdf_file);
}