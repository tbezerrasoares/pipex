# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbezerra <tbezerra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 12:16:36 by tbezerra          #+#    #+#              #
#    Updated: 2024/05/17 14:20:32 by tbezerra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ./
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
        ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c\
        ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c\
        ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
        ft_memmove.c ft_memset.c ft_printf_aux.c ft_printf_mem.c ft_printf.c\
        ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
        ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
        ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
        ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c\
        ft_toupper.c get_next_line_bonus.c get_next_line_utils_bonus.c\
		free_ft_split.c ft_strcmp.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADER) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)