# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfonseca <hfonseca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 16:23:15 by hfonseca          #+#    #+#              #
#    Updated: 2026/02/16 16:23:15 by hfonseca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c line_reader.c header.c rows.c solve.c display.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
