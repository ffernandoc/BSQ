/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcruz <frcruz@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:51:58 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/18 19:42:26 by frcruz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
** Copia len bytes de src para dst.
*/
static void	copy_buf(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
** Aumenta o buffer dinamico ate suportar len bytes.
*/
static int	grow_buffer(char **buf, int *cap, int len)
{
	char	*newbuf;
	int		new_cap;

	new_cap = *cap;
	while (new_cap <= len)
	{
		if (new_cap > 1073741823)
			return (0);
		new_cap *= 2;
	}
	newbuf = (char *)malloc(new_cap);
	if (!newbuf)
		return (0);
	copy_buf(newbuf, *buf, len);
	free(*buf);
	*buf = newbuf;
	*cap = new_cap;
	return (1);
}

/*
** Le uma linha logica e exige newline no fim.
*/
static int	read_loop(int fd, char **buf, int *len, int *cap)
{
	char	c;
	int		r;

	r = read(fd, &c, 1);
	while (r > 0 && c != '\n')
	{
		if (*len + 1 >= *cap && !grow_buffer(buf, cap, *len + 1))
			return (-1);
		(*buf)[*len] = c;
		(*len)++;
		r = read(fd, &c, 1);
	}
	if (r < 0)
		return (-1);
	if (r == 0 && *len == 0)
		return (0);
	if (r == 0)
		return (-2);
	return (1);
}

/*
** Devolve linha sem '\\n'; 0 em EOF; negativo em erro.
*/
int	read_line_dyn(int fd, char **out)
{
	char	*buf;
	int		cap;
	int		len;
	int		status;

	cap = 64;
	buf = (char *)malloc(cap);
	if (!buf)
		return (-1);
	len = 0;
	status = read_loop(fd, &buf, &len, &cap);
	if (status <= 0)
	{
		free(buf);
		return (status);
	}
	buf[len] = '\0';
	*out = buf;
	return (len);
}
