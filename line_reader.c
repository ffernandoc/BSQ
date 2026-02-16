/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:51:58 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 14:51:58 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* Realloc simples: adiciona um char ao buffer (malloc+copy+free)*/
static int append_char(char **buf, int *len, char c)
{
    char *newbuf;
    int i;

    newbuf = (char *)malloc(*len + 2);
    if(!newbuf)
        return(0);
    i = 0;
    while(i < *len)
    {
        newbuf[i] = (*buf)[i];
        i++;
    }
    newbuf[*len] = c;
    newbuf[*len + 1] = '\0';
    free(*buf);
    *buf = newbuf;
    (*len)++;
    return (1);
}

/*Lê até '\\n' (ou EOF), montando a linha no buffer*/
static int read_loop(int fd, char **buf, int *len)
{
    char c;
    int r;

    r = read(fd, &c, 1);
    while(r > 0 && c != '\n')
    {
        if(!append_char(buf, len, c))
            return (-1);
        r = read(fd, &c, 1);
    }
    if(r <= 0 && *len == 0)
        return (0);
    return(1);
}

/*Lê uma linha dinâmica. Retorna len, 0 (EOF vazio) ou -1 (erro)*/
int	read_line_dyn(int fd, char **out)
{
	char	*buf;
	int		len;
	int		status;

	buf = (char *)malloc(1);
	if (!buf)
		return (-1);
	buf[0] = '\0';
	len = 0;
	status = read_loop(fd, &buf, &len);
	if (status <= 0)
	{
		free(buf);
		return (status);
	}
	*out = buf;
	return (len);
}