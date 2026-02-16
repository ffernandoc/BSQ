/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcruz <frcruz@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:06:43 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 04:06:11 by frcruz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>

/*
 * print_map_error:
 * Decisão: o enunciado pede que o erro seja "map error\n" no stdout,
 * então fazemos uma função única para não repetir write espalhado.
 */
void	print_map_error(void)
{
	write(1, "map error\n", 10);
}

/*
 * read_map_from_fd:
 * Orquestra: init -> header -> alloc -> rows.
 */
int	read_map_from_fd(int fd, t_map *map)
{
	init_map(map);
	if (!read_and_parse_header(fd, map))
		return (0);
	if (!alloc_data(map))
		return (0);
	if (!read_all_rows(fd, map))
	{
		free_rows(map->data, map->lines);
		map->data = NULL;
		return (0);
	}
	return (1);
}

/*
 * process_file:
 * Abre o arquivo, chama read_map_from_fd e fecha.
 * Retorna 1 em sucesso, 0 em erro.
 */
int	process_file(const char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (!read_map_from_fd(fd, map))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
