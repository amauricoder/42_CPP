# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 14:51:24 by aconceic          #+#    #+#              #
#    Updated: 2024/12/09 19:51:00 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex00
SRC = main.cpp Bureaucrat.cpp \

OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all :$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(NAME)
	rm -rf objs

re: fclean all