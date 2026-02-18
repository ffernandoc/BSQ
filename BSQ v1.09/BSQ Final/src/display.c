/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:21:22 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 16:21:22 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(t_map *map)
{
	int	r;
	int	c;
	int	side;

	side = map->max_side;
	r = map->best_row;
	while (r > map->best_row - side)
	{
		c = map->best_col;
		while (c > map->best_col - side)
		{
			map->data[r][c] = map->full;
			c--;
		}
		r--;
	}
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->lines)
	{
		write(1, map->data[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->lines)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	map->data = NULL;
}
