/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:21:27 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 17:21:27 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* Resolve um mapa a partir de um fd (ficheiro ou stdin) */
static void	solve_fd(int fd)
{
	t_map	map;

	if (!read_map(fd, &map))
	{
		ft_putstr("map error\n");
		return ;
	}
	find_square(&map);
	fill_square(&map);
	print_map(&map);
	free_map(&map);
}

/* Resolve um ficheiro pelo nome */
static void	solve_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("map error\n");
		return ;
	}
	solve_fd(fd);
	close(fd);
}

/* Ponto de entrada: 0 args => stdin; N args => N ficheiros */
int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		solve_fd(0);
	else
	{
		i = 1;
		while (i < argc)
		{
			solve_file(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}