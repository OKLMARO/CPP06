# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/25 13:28:36 by oamairi           #+#    #+#              #
#    Updated: 2026/06/25 19:02:03 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	convert

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	ScalarConverter.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
