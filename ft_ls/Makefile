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

NAME =			ft_ls

LS =				ft_ls.c

OBJS += 		$(addprefix build/, $(LS:.c=.o))

CC = 				gcc
CFLAGS = 		-Wall -Wextra -Werror -g
HEADER = 		-I includes/
LFLAGS = 		-L./libft -lft

all: $(NAME)

$(NAME): $(OBJS) | lib
	@echo "Compiling executable..."
	@$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	@echo "Success!"

build/%.o: srcs/%.c | build
	@echo "Compiling .o files..."
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $^
	@echo "Success!"

build:
	@mkdir build/

lib:
	@echo "Compiling library..."
	@make -C libft/
	@echo "Success!"

clean:
	@echo "Removing build files..."
	@rm -rf build/

fclean: clean
	@echo "Removing library files..."
	@make fclean -C libft/
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib
