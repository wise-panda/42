# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbogar <lbogar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 14:48:13 by lbogar            #+#    #+#              #
#    Updated: 2018/04/25 14:15:35 by lbo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ls

LS =		ft_ls.c

OBJS += 	$(addprefix build/, $(LS:.c=.o))

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror -g
CFLAGS += 	-I includes/
LFLAGS = 	-L ./libft -lft

all: $(NAME)

$(NAME): $(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

build:
	@mkdir build/

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib
