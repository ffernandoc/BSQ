/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:06:17 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 15:06:17 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* Verifica se é caractere imprimível */
static int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

/* Converte a parte numérica do header no número de linhas */
static int	parse_lines(char *line, int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < len - 3)
	{
		if (line[i] < '0' || line[i] > '9')
			return (-1);
		n = n * 10 + (line[i] - '0');
		i++;
	}
	if (n <= 0)
		return (-1);
	return (n);
}

/* Extrai lines/empty/obstacle/full e valida */
int	parse_header_line(char *line, int len, t_map *map)
{
	map->lines = parse_lines(line, len);
	if (map->lines <= 0)
		return (0);
	map->empty = line[len - 3];
	map->obstacle = line[len - 2];
	map->full = line[len - 1];
	if (!is_printable(map->empty) || !is_printable(map->obstacle)
		|| !is_printable(map->full))
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}
