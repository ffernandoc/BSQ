/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:53:49 by hfonseca          #+#    #+#             */
/*   Updated: 2026/02/16 13:53:49 by hfonseca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*Imprime um carácter*/
void ft_putchar(char c)
{
    write(1, &c, 1);
}

/*Imprime uma string*/
void ft_putstr(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
}