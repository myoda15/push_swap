# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mande-so <mande-so@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 15:59:58 by mande-so          #+#    #+#              #
#    Updated: 2026/01/21 01:47:36 by mande-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= srcs/main.c \
			  srcs/error.c \
			  srcs/parsing.c \
			  srcs/init.c \
			  srcs/utils/utils.c \
			  srcs/utils/stack_utils.c \
			  srcs/operations/swap.c \
			  srcs/operations/push.c \
			  srcs/operations/rotate.c \
			  srcs/operations/reverse_rotate.c \
			  srcs/algorithm/sort_small.c \
			  srcs/algorithm/sort_medium.c \
			  srcs/algorithm/sort_large.c

BONUS_SRCS	= srcs/bonus/checker.c \
			  srcs/bonus/checker_ops.c \
			  srcs/bonus/checker_utils.c \
			  srcs/bonus/get_next_line.c \
			  srcs/error.c \
			  srcs/parsing.c \
			  srcs/init.c \
			  srcs/utils/utils.c \
			  srcs/utils/stack_utils.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
