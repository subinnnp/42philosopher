# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: subpark <subpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 22:46:12 by siun              #+#    #+#              #
#    Updated: 2024/02/12 17:25:18 by subpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CCFLAGS = -Wall -Werror -Wextra -g

NAME 	= philo
SRC		= action.c free.c ft_atoi.c ft_itoa.c generate.c main.c tools.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

clean:
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all

%.o: %.c philo.h
			$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJ)
			$(CC) $(CCFLAGS) -o $@ $^

.PHONY: all clean fclean re

#-fsanitize=thread -g 