/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcruz <frcruz@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 01:12:36 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 03:40:35 by frcruz           ###   ########.fr       */
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

/* =========================
 * Fluxo geral / erros
 * ========================= */
int			process_file(const char *path, t_map *map);
void		print_map_error(void);

/* =========================
 * Memória
 * ========================= */
void		free_rows(char **rows, int count);

/* =========================
 * Leitura / parsing / validação
 * ========================= */
int			read_line_dyn(int fd, char **out);
int			parse_header_line(char *line, int len, t_map *map);
int			check_row_chars(char *row, int len, t_map *map);

/* =========================
 * Leitura do mapa (alto nível)
 * ========================= */
int			read_map_from_fd(int fd, t_map *map);

/* =========================
 * Helpers de leitura do mapa
 * (divisão para cumprir Norm)
 * ========================= */
void		init_map(t_map *map);
int			read_and_parse_header(int fd, t_map *map);
int			alloc_data(t_map *map);
int			read_all_rows(int fd, t_map *map);

#endif
