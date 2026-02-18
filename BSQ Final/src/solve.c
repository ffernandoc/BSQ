/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:19:16 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 16:19:16 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	min3(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

static void	update_best(t_map *map, int val, int row, int col)
{
	if (val > map->max_side)
	{
		map->max_side = val;
		map->best_row = row;
		map->best_col = col;
	}
	else if (val == map->max_side)
	{
		if (row - val + 1 < map->best_row - map->max_side + 1)
		{
			map->best_row = row;
			map->best_col = col;
		}
		else if (row - val + 1 == map->best_row - map->max_side + 1
			&& col - val + 1 < map->best_col - map->max_side + 1)
		{
			map->best_row = row;
			map->best_col = col;
		}
	}
}

static void	process_row(t_map *map, int *prev, int *curr, int row)
{
	int	col;

	col = 0;
	while (col < map->cols)
	{
		if (map->data[row][col] == map->obstacle)
			curr[col] = 0;
		else if (row == 0 || col == 0)
			curr[col] = 1;
		else
			curr[col] = 1 + min3(prev[col], curr[col - 1], prev[col - 1]);
		update_best(map, curr[col], row, col);
		col++;
	}
}

static int	init_dp_buffers(t_map *map, int **prev, int **curr)
{
	*prev = (int *)malloc(sizeof(int) * map->cols);
	*curr = (int *)malloc(sizeof(int) * map->cols);
	if (!*prev || !*curr)
	{
		free(*prev);
		free(*curr);
		return (0);
	}
	return (1);
}

int	find_square(t_map *map)
{
	int	*prev;
	int	*curr;
	int	row;
	int	*tmp;

	map->max_side = 0;
	map->best_row = 0;
	map->best_col = 0;
	if (!init_dp_buffers(map, &prev, &curr))
		return (0);
	row = 0;
	while (row < map->lines)
	{
		process_row(map, prev, curr, row);
		tmp = prev;
		prev = curr;
		curr = tmp;
		row++;
	}
	free(prev);
	free(curr);
	return (1);
}
