# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbogar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/31 14:48:13 by lbogar            #+#    #+#              #
#    Updated: 2016/10/31 14:48:15 by lbogar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_ls

LS =		ft_ls.c \
				ft_create_dir.c \
				ft_find_pwd.c \
				ft_parse_flag.c \
				ft_recursive_flag.c

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
