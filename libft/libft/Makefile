# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 23:40:02 by tbezerra          #+#    #+#              #
#    Updated: 2023/10/26 12:22:27 by tbezerra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRE = ./
HEADER = ./
GNL = ./Get_next_line

SOURCE = ft_atoi.c ft_isprint.c ft_memcpy.c ft_split.c ft_strmapi.c\
	ft_toupper.c ft_bzero.c ft_itoa.c ft_memmove.c ft_strchr.c ft_strncmp.c\
	 ft_memset.c ft_strdup.c ft_strnstr.c ft_isalnum.c ft_putchar_fd.c\
	 ft_strjoin.c ft_strrchr.c ft_isalpha.c ft_putendl_fd.c ft_strlcat.c\
	 ft_strtrim.c ft_isascii.c ft_memchr.c ft_putnbr_fd.c\
	 ft_strlcpy.c ft_substr.c ft_isdigit.c ft_memcmp.c ft_putstr_fd.c\
	 ft_strlen.c ft_tolower.c ft_striteri.c ft_lstadd_back.c ft_lstadd_front.c\
	 ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstiter.c\
	 ft_lstclear.c ft_lstmap.c ft_calloc.c

SOURCE_GNL = get_next_line_bonus.c get_next_line_utils_bonus.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
	   
SOURCES_GNL = ${addprefix $(GNL), $(SOURCE_GNL)}

NAME = libft.a

CC = cc 
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o) 
OBJ_GNL = $(SOURCES_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_GNL)
	ar rcs $@ $(OBJ) $(OBJ_GNL)

.c.o:
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)
    
clean: 
	rm -f $(OBJ) $(OBJ_GNL)
        
fclean: clean
	rm -f $(NAME)

re: fclean all