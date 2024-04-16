# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:16:36 by tbezerra          #+#    #+#              #
#    Updated: 2023/11/06 16:31:09 by tbezerra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRE = ./ft_printf/
HEADER = ./
FUNCTION = ./libft


SOURCE = ft_printf.C ft_printf_aux.c ft_printf_mem.c ft_printf_utils.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}

NAME = libftprintf.a
LIB = $(FUNCTION)/libft.a


CC = cc
CCFLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(FUNCTION)
	cp $(LIB) $@
	ar rcs $@ $(OBJ)

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -I $(FUNCTION) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all

.PHONY: all clean fclean re bonus