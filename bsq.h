/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:22:09 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 17:22:09 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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
	char	empty;
	char	obstacle;
	char	full;
	int		lines;
	int		cols;
	char	**data;
	int		max_side;
	int		best_row;
	int		best_col;
}			t_map;

/* Leitura de linhas (dinâmica) */
int		read_line_dyn(int fd, char **out);

/* Parsing do header */
int		parse_header_line(char *line, int len, t_map *map);

/* Leitura completa do mapa (header + linhas) */
int		read_map(int fd, t_map *map);

/* Resolução */
void	find_square(t_map *map);

/* Output / memória */
void	fill_square(t_map *map);
void	print_map(t_map *map);
void	free_map(t_map *map);

/* Utils */
void	ft_putstr(char *s);
void	ft_putchar(char c);

#endif