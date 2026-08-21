# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llinda <llinda@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 12:28:27 by mmankows          #+#    #+#              #
#    Updated: 2026/08/21 15:45:17 by llinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I./includes -I./libft -I./ft_printf -I./ft_printf/includes

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
SRC_DIR = ./src
OBJ_DIR = ./obj

PS_SRCS = \
			dlist_utils.c \
			errors.c \
			insertion_sort.c \
			main.c \
			operations.c \
			operations2.c \
			operations3.c \
			parser.c \
			parser_utils.c \
			utils.c \
			benchmark.c \
			disorder.c \
			medium_sort.c \
			complex_sort.c

PS_OBJS = $(addprefix $(OBJ_DIR)/, $(PS_SRCS:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(PS_OBJS)
	@echo "$(GREEN)Creating push_swap...$(RESET)"
	@$(CC) $(CFLAGS) $(PS_OBJS) $(LIBFT) $(PRINTF) -o $@
	@echo "$(GREEN)Binary compiled: $(NAME)$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(GREEN)Compiling ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)Removing binaries...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re