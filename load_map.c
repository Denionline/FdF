/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:29:36 by dximenes          #+#    #+#             */
/*   Updated: 2025/06/24 13:12:04 by dximenes         ###   ########.fr       */
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

static int ** realloc_coordinates(int ** oldarray, int newlen)
{
	int ** newarray;
	int	   i;

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

static int ** get_values(t_map * map, char ** values)
{
	int i;

	map->coordinates = realloc_coordinates(map->coordinates, map->size.y);
	map->coordinates[map->size.y] = malloc(get_size(values) * sizeof(int));
	if (!map->coordinates || !map->coordinates[map->size.y])
		return (free(map->coordinates), free(map->coordinates[map->size.y]), NULL);
	if (map->size.x < get_size(values))
		map->size.x = get_size(values);
	i = 0;
	while (values[i])
	{
		map->coordinates[map->size.y][i] = ft_atoi(values[i]);
		free(values[i++]);
	}
	free(values);
	map->size.y += 1;
	return (map->coordinates);
}

void load_map(t_map ** map)
{
	char * row;
	int	   fd;

	fd = open((*map)->path, O_RDONLY);
	(*map)->size.x = 0;
	(*map)->size.y = 0;
	row = get_next_line(fd);
	while (row)
	{
		if (!row)
			break;
		(*map)->coordinates = get_values(*map, ft_split(row, ' '));
		free(row);
		row = get_next_line(fd);
	}
	close(fd);
}