#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okupin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 22:27:15 by okupin            #+#    #+#              #
#    Updated: 2017/10/27 22:37:04 by okupin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC = gcc

SRC = ft_atoi.c\
ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memmove.c\
ft_memset.c\
ft_strlen.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strrchr.c\
ft_strstr.c\
ft_tolower.c\
ft_toupper.c\
ft_memcpy.c\
ft_strnstr.c\
ft_strcat.c\
ft_strchr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdup.c\
ft_strlcat.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_memalloc.c\
ft_memdel.c\
ft_strequ.c\
ft_strnequ.c\
ft_strtrim.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strsub.c\
ft_strjoin.c\
ft_strsplit.c\
ft_itoa.c\
ft_putchar.c\
ft_putstr.c\
ft_putendl.c\
ft_putnbr.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_lstmap.c\
ft_isspace.c\
ft_count_if.c\
ft_swap.c\
ft_skip_tab.c\
ft_sqrt.c\
delforlist.c\
skip_delim.c\
ft_strtoupper.c\

OBJ = $(SRC:.c=.o)
HEAD = libft.h

all: $(NAME)

$(NAME) : $(OBJ)
		@ar rc $(NAME) $(OBJ)
%.o: %.c
		$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@
clean:
	/bin/rm -rf $(OBJ)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all

.NOTPARALLEL: all $(NAME) re