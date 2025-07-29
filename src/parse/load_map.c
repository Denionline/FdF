/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:29:36 by dximenes          #+#    #+#             */
/*   Updated: 2025/07/29 09:59:13 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	get_size(char **values)
{
	int	len;

	len = 0;
	while (values[len] && values[len][0] != '\n')
		len++;
	return (len);
}

static t_pixel	**realloc_coordinates(t_pixel **oldarray, int newlen)
{
	t_pixel	**newarray;
	int		i;

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

static t_pixel	get_point(char *value)
{
	t_pixel	pixel;
	char	**values;

	if (ft_strchr(value, ','))
	{
		values = ft_split(value, ',');
		pixel.z = ft_atoi(values[0]);
		pixel.color = ft_basetoi(values[1] + 2, "0123456789abcdef");
		if (pixel.color == 0)
			pixel.color = COLOR;
		return (free(values[0]), free(values[1]), free(values), pixel);
	}
	pixel.color = COLOR;
	pixel.z = ft_atoi(value);
	return (pixel);
}

static t_pixel	**get_values(t_map *map, char **values)
{
	int	line_size;
	int	i;

	line_size = get_size(values);
	map->points = realloc_coordinates(map->points, map->size.y);
	map->points[map->size.y] = malloc(line_size * sizeof(t_pixel));
	if (!map->points || !map->points[map->size.y])
		return (free(map->points), free(map->points[map->size.y]), NULL);
	if (map->size.x < line_size)
		map->size.x = line_size;
	i = 0;
	while (i < line_size)
	{
		map->points[map->size.y][i] = get_point(values[i]);
		free(values[i++]);
	}
	free(values);
	map->size.y += 1;
	return (map->points);
}

void	load_map(t_head *head, char *path)
{
	const int	fd = open(path, O_RDONLY);
	char		*row;

	if (fd < 3)
		end(head);
	ft_bzero(head->map, sizeof(*head->map));
	while (TRUE)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		head->map->points = get_values(head->map, ft_split(row, ' '));
		free(row);
	}
	set_color_top(head->map->points, head->map->size.x, head->map->size.y);
	close(fd);
}
