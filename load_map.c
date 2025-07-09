/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:29:36 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/09 12:01:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int get_size(char ** values)
{
	int len;

	len = 0;
	while (values[len] != NULL)
		len++;
	return (len);
}

static t_pixel ** realloc_coordinates(t_pixel ** oldarray, int newlen)
{
	t_pixel ** newarray;
	int		   i;

	newarray = malloc((newlen + 1) * sizeof(int *));
	if (!newarray)
		return (NULL);
	i = 0;
	while (oldarray && i < newlen)
	{
		newarray[i] = oldarray[i];
		i++;
	}
	if (oldarray)
		free(oldarray);
	return (newarray);
}

static t_pixel get_point(char * value)
{
	t_pixel pixel;
	char ** values;

	if (ft_strchr(value, ','))
	{
		values = ft_split(value, ',');
		pixel.z = ft_atoi(values[0]);
		pixel.color = ft_basetoi(values[1]+2, "0123456789ABCDEF");
		return (free(values[0]), free(values[1]), free(values), pixel);
	}
	pixel.color = 0xFFFFFF;
	pixel.z = ft_atoi(value);
	return (pixel);
}

static t_pixel ** get_values(t_map * map, char ** values)
{
	int i;

	map->coordinates = realloc_coordinates(map->coordinates, map->size.y);
	map->coordinates[map->size.y] = malloc(get_size(values) * sizeof(t_pixel));
	if (!map->coordinates || !map->coordinates[map->size.y])
		return (free(map->coordinates), free(map->coordinates[map->size.y]), NULL);
	if (map->size.x < get_size(values))
		map->size.x = get_size(values);
	i = 0;
	while (values[i])
	{
		map->coordinates[map->size.y][i] = get_point(values[i]);
		free(values[i++]);
	}
	free(values);
	map->size.y += 1;
	return (map->coordinates);
}

void load_map(t_map ** map, char * path)
{
	const int fd = open(path, O_RDONLY);
	char *	  row;

	ft_bzero(*map, sizeof(**map));
	while (TRUE)
	{
		row = get_next_line(fd);
		if (!row)
			break;
		(*map)->coordinates = get_values(*map, ft_split(row, ' '));
		free(row);
	}
	close(fd);
}