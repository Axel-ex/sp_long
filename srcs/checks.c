/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelchab <achabrer@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:26:25 by axelchab          #+#    #+#             */
/*   Updated: 2023/05/29 13:42:01 by axelchab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_ber(char *str)
{
	if (ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		return (1);
	}
	return (0);
}

int	check_equal_line(t_map *map)
{
	int	i;

	i = 1;
	while (i < map->width)
	{
		if (ft_strlen(map->matrix[i]) != ft_strlen(map->matrix[i - 1]))
			return (0);
		i++;
	}
	map->length = ft_strlen(map->matrix[0]);
	return (1);
}

int	check_accepted_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == '1' || map->matrix[i][j] == 'E'
				|| map->matrix[i][j] == '0' || map->matrix[i][j] == 'P'
				|| map->matrix[i][j] == 'C')
				j++;
			else
				return (0);
			if (map->matrix[i][j + 1] == '\0')
				break ;
		}
		i++;
	}
	return (1);
}

int	check_numb_items(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == 'P')
				map->player++;
			if (map->matrix[i][j] == 'C')
				map->collect++;
			if (map->matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->collect == 0 || map->exit != 1)
		return (0);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if ((i == 0 || i == map->width) && map->matrix[i][j] != '1')
				return (0);
			if ((j == 0 || j == map->length) && map->matrix[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
