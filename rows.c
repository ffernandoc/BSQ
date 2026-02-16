/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:02:50 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 01:02:50 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*
 * check_row_chars - verifica se todos os caracteres da linha pertencem
 * a empty ou obstacle. Retorna 1 se sim ou 0 se encontrar carácter inválido.
 */
static int check_row_chars(char *row, int len, t_map *map)
{
    int i;

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
 * free_rows - liberta as linhas previamente alocadas em data. Usada em caso
 * de erro para evitar fugas de memória.
 */
static void free_rows(char **data, int rows)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(data[i]);
        i++;
    }
    free(data);
}

/*cleanup_read: limpeza em erro, liberta linha atual (se existir) e o que já foi lido*/
static int cleanup_read(t_map *map, char *row, int count)
{
    if(row)
        free(row);
    free_rows(map->data, count);
    map->data = NULL;
    return (0);
}

/*read_map_rows: Lê e valida as linhas do mapa*/
static int	read_map_rows(int fd, t_map *map)
{
	int		i;
	int		len;
	char	*line;

	map->data = (char **)malloc(sizeof(char *) * map->lines);
	if (!map->data)
		return (0);
	i = 0;
	while (i < map->lines)
	{
		len = read_line_dyn(fd, &line);
		if (len <= 0)
			return (cleanup_read(map, NULL, i));
		if (line[len - 1] == '\r')
			line[--len] = '\0';
		if (i == 0)
			map->cols = len;
		if (len != map->cols || !check_row_chars(line, len, map))
			return (cleanup_read(map, line, i));
		map->data[i++] = line;
	}
	return (1);
}

/* Lê header e depois as linhas */
int	read_map(int fd, t_map *map)
{
	char	*line;
	int		len;

	len = read_line_dyn(fd, &line);
	if (len < 4)
		return (0);
	if (line[len - 1] == '\r')
		line[--len] = '\0';
	if (!parse_header_line(line, len, map))
		return (free(line), 0);
	free(line);
	if (!read_map_rows(fd, map))
		return (0);
	return (1);
}