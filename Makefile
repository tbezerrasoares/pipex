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

PRE = ./
HEADER = ./
FUNCTION = ./libft

SOURCE = main.c utis.c get_path.c status.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}

NAME = pipex
LIB = $(FUNCTION)/libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C $(FUNCTION)
.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)
	
clean: 
	rm -f $(OBJ) $(OBJ_BON)
	$(MAKE) clean -C $(FUNCTION)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all