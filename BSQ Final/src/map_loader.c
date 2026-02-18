/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:02:50 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 01:02:50 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Garante que cada celula e empty ou obstacle.
*/
static int	check_row_chars(char *row, int len, t_map *map)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (row[i] != map->empty && row[i] != map->obstacle)
			return (0);
		i++;
	}
	return (1);
}

/*
** Liberta linhas ja lidas quando o parse falha.
*/
static int	cleanup_read(t_map *map, char *row, int count)
{
	if (row)
		free(row);
	while (count > 0)
	{
		count--;
		free(map->data[count]);
	}
	free(map->data);
	map->data = NULL;
	return (0);
}

/*
** Valida tamanho da linha e caracteres permitidos.
*/
static int	validate_row(t_map *map, char *line, int len, int i)
{
	if (line[len - 1] == '\r')
		line[--len] = '\0';
	if (i == 0)
		map->cols = len;
	if (map->cols <= 0 || len != map->cols)
		return (0);
	if (!check_row_chars(line, len, map))
		return (0);
	return (1);
}

/*
** Le todas as linhas e rejeita bytes extra no fim.
*/
static int	read_map_rows(int fd, t_map *map)
{
	int		i;
	int		len;
	char	*line;
	char	extra;

	map->data = (char **)malloc(sizeof(char *) * map->lines);
	if (!map->data)
		return (0);
	i = 0;
	while (i < map->lines)
	{
		len = read_line_dyn(fd, &line);
		if (len <= 0)
			return (cleanup_read(map, NULL, i));
		if (!validate_row(map, line, len, i))
			return (cleanup_read(map, line, i));
		map->data[i++] = line;
	}
	if (read(fd, &extra, 1) == 0)
		return (1);
	return (cleanup_read(map, NULL, map->lines));
}

/*
** Le e valida um mapa completo de fd para t_map.
*/
int	read_map(int fd, t_map *map)
{
	char	*line;
	int		len;

	len = read_line_dyn(fd, &line);
	if (len < 4)
	{
		if (len > 0)
			free(line);
		return (0);
	}
	if (line[len - 1] == '\r')
		line[--len] = '\0';
	if (!parse_header_line(line, len, map))
		return (free(line), 0);
	free(line);
	if (!read_map_rows(fd, map))
		return (0);
	return (1);
}
