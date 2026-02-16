/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcruz <frcruz@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 00:50:15 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 03:57:41 by frcruz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

static void	print_map(t_map *map)
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

static void	run_one_map(t_map *map, int ok)
{
	if (!ok)
		print_map_error();
	else
	{
		print_map(map);
		free_rows(map->data, map->lines);
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	if (argc < 2)
	{
		run_one_map(&map, read_map_from_fd(0, &map));
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		run_one_map(&map, process_file(argv[i], &map));
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
