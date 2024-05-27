# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:10:52 by codespace         #+#    #+#              #
#    Updated: 2024/05/27 13:43:11 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = ./
MAKE = make -C
CC = cc
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c get_path.c utis.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE) ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)