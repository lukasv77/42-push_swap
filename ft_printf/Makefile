# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 11:34:22 by llinda            #+#    #+#              #
#    Updated: 2026/08/18 14:19:51 by llinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
C_FILES = ft_printers02.c ft_printers.c ft_printf.c
OBJ = $(C_FILES:.c=.o)
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJ) ../libft/libft.a
	@cp ../libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
../libft/libft.a:
	@make -C ../libft 
%.o: %.c ft_printf.h
	@$(CC) -c $(CFLAGS) $< -I ../libft 
clean:
	@make clean -C ../libft
	@rm -f $(OBJ) *.gch
fclean: clean
	@make fclean -C ../libft
	@rm -f $(NAME) *.out
re: fclean all

.PHONY: all clean fclean re
