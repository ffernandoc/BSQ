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

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

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

int		read_line_dyn(int fd, char **out);
int		parse_header_line(char *line, int len, t_map *map);
int		read_map(int fd, t_map *map);
int		find_square(t_map *map);
void	fill_square(t_map *map);
void	print_map(t_map *map);
void	free_map(t_map *map);
void	ft_putstr(char *s);
void	ft_putchar(char c);

#endif
