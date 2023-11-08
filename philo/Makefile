# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siun <siun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 22:46:12 by siun              #+#    #+#              #
#    Updated: 2023/11/08 14:42:49 by siun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CCFLAGS = -Wall -Werror -Wextra

NAME 	= philo
SRC		=
OBJ		= $(SRC:.c=.o)

all: $(NAME)

clean:
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all

%.o: %.c philo.h

$(NAME): $(OBJ)
			$(CC) $(CCFLAGS) -o $@ $^

.PHONY: all clean fclean re