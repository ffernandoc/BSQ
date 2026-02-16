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
int check_row_chars(char *row, int len, t_map *map)
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
void free_rows(char **data, int rows)
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