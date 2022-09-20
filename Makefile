# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:26:21 by bchabot           #+#    #+#              #
#    Updated: 2022/09/20 16:23:43 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/pipex.c \
		srcs/parse_data.c \
		srcs/pipex_utils.c \
		srcs/check_errors.c

CC = gcc

LIBFT = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

NAME = pipex

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -sC libft
	@echo "\033[92mLibft compiled."

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\033[100m\033[1m\033[92mProgram compiled and ready to execute."

clean :
	rm -f $(OBJS)
	make -sC libft fclean
	@echo "\033[91mObjects cleaned."

fclean : clean
	rm -rf $(NAME)
	@echo "\033[91mObjects and program cleaned."

re : fclean all

.PHONY : all re clean fclean
.SILENT :
