/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:06:43 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 01:06:43 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

/*
 * append_char - acrescenta um carácter ao buffer, redimensionando se
 * necessário. Actualiza len e cap. Retorna 1 em caso de sucesso ou 0 em erro
 * de alocação. Esta função é estática pois só é utilizada neste ficheiro.
 */
static int append_char(char **buf, int *len, int *cap, char c)
{
    int     newcap;
    char    *tmp;
    int     i;

    if (*len >= *cap)
    {
        newcap = (*cap) * 2;
        tmp = (char *)malloc(newcap);
        if (!tmp)
            return (0);
        i = 0;
        while (i < *cap)
        {
            tmp[i] = (*buf)[i];
            i++;
        }
        free(*buf);
        *buf = tmp;
        *cap = newcap;
    }
    (*buf)[*len] = c;
    (*len)++;
    return (1);
}

/*
 * read_line_into_buffer - lê caracteres do descritor fd até '\n' ou EOF,
 * armazenando-os no buffer. Usa append_char para redimensionar. Retorna 1 se
 * pelo menos um carácter foi lido ou 0 em caso de erro ou fim de ficheiro
 * imediato.
 */
static int read_line_into_buffer(int fd, char **buf, int *len, int *cap)
{
    char    c;
    int     r;

    while ((r = read(fd, &c, 1)) > 0 && c != '\n')
    {
        if (!append_char(buf, len, cap, c))
            return (0);
    }
    if (r <= 0 && *len == 0)
        return (0);
    return (1);
}

/*
 * read_line_dyn - lê uma linha dinâmica do descritor fd. Retorna o
 * comprimento da linha sem '\n' ou -1 em caso de erro/EOF sem dados. O
 * ponteiro de saída recebe a string terminada por '\0'.
 */
static int read_line_dyn(int fd, char **out)
{
    int     cap;
    int     len;
    char    *buf;
    char    *line;
    int     i;

    cap = 16;
    len = 0;
    buf = (char *)malloc(cap);
    if (!buf)
        return (-1);
    if (!read_line_into_buffer(fd, &buf, &len, &cap))
    {
        free(buf);
        return (-1);
    }
    line = (char *)malloc(len + 1);
    if (!line)
    {
        free(buf);
        return (-1);
    }
    i = 0;
    while (i < len)
    {
        line[i] = buf[i];
        i++;
    }
    line[len] = '\0';
    free(buf);
    *out = line;
    return (len);
}

/*
 * parse_header_line - analisa a linha de cabeçalho do mapa. O último
 * triplo de caracteres da linha indica empty, obstacle e full. A parte
 * anterior deve conter apenas dígitos que correspondem ao número de linhas.
 * Retorna 1 se a linha é válida ou 0 caso contrário.
 */
static int parse_header_line(char *line, int len, t_map *map)
{
    int i;
    int num;
    int num_len;

    if (len < 4)
        return (0);
    map->empty = line[len - 3];
    map->obstacle = line[len - 2];
    map->full = line[len - 1];
    if (map->empty == map->obstacle || map->empty == map->full
        || map->obstacle == map->full)
        return (0);
    num_len = len - 3;
    i = 0;
    num = 0;
    while (i < num_len)
    {
        if (line[i] < '0' || line[i] > '9')
            return (0);
        num = num * 10 + (line[i] - '0');
        i++;
    }
    if (num <= 0)
        return (0);
    map->lines = num;
    return (1);
}