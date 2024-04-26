# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:10:52 by codespace         #+#    #+#              #
#    Updated: 2024/04/19 17:59:55 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = ./
CC = cc
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c get_path.c status.c utis.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)