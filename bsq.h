/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:12:36 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 01:12:36 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>

/*
 * Estrutura que representa um mapa e o maior quadrado encontrado. Os campos
 * 'empty', 'obstacle' e 'full' armazenam os caracteres correspondentes às
 * células livres, obstáculos e marcação do quadrado. As dimensões são
 * armazenadas em 'lines' e 'cols'. 'data' aponta para a matriz de caracteres.
 * 'max_side', 'best_row' e 'best_col' guardam o lado e a posição do maior
 * quadrado encontrado.
 */
typedef struct s_map
{
    char    empty;
    char    obstacle;
    char    full;
    int     lines;
    int     cols;
    char    **data;
    int     max_side;
    int     best_row;
    int     best_col;
}   t_map;

/* Funções públicas implementadas nos ficheiros correspondentes */

#endif