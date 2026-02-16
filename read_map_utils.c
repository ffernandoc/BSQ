/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcruz <frcruz@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 03:35:10 by frcruz            #+#    #+#             */
/*   Updated: 2026/02/16 03:35:15 by frcruz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*
 * init_map:
 * Decisão: iniciar estado previsível para evitar lixo em caso de erro.
 */
void	init_map(t_map *map)
{
	map->data = NULL;
	map->lines = 0;
	map->cols = 0;
	map->max_side = 0;
	map->best_row = -1;
	map->best_col = -1;
}

/*
 * read_and_parse_header:
 * Lê a primeira linha e faz parse (lines, empty, obstacle, full).
 * Retorna 1 em sucesso, 0 em erro.
 */
int	read_and_parse_header(int fd, t_map *map)
{
	char	*line;
	int		len;

	len = read_line_dyn(fd, &line);
	if (len < 0)
		return (0);
	if (!parse_header_line(line, len, map))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

/*
 * alloc_data:
 * Decisão: alocar map->data e inicializar tudo a NULL para free seguro.
 */
int	alloc_data(t_map *map)
{
	int	i;

	map->data = (char **)malloc(sizeof(char *) * map->lines);
	if (!map->data)
		return (0);
	i = 0;
	while (i < map->lines)
	{
		map->data[i] = NULL;
		i++;
	}
	return (1);
}

/*
 * read_all_rows:
 * Decisão: ler todas as linhas, validar e guardar.
 * Se falhar em qualquer linha, libera tudo e sinaliza erro.
 */
int	read_all_rows(int fd, t_map *map)
{
	char	*line;
	char	extra;
	int		len;
	int		i;

	i = 0;
	while (i < map->lines)
	{
		len = read_line_dyn(fd, &line);
		if (len < 0)
			return (0);
		if (i == 0)
			map->cols = len;
		if (len <= 0 || len != map->cols || !check_row_chars(line, len, map))
		{
			free(line);
			return (0);
		}
		map->data[i] = line;
		i++;
	}
	if (read(fd, &extra, 1) != 0)
		return (0);
	return (map->cols > 0);
}
