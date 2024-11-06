# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 13:27:28 by aconceic          #+#    #+#              #
#    Updated: 2024/11/06 12:09:06 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex04
SRC = support.cpp \

OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) main.cpp $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(NAME)
	rm -rf objs

re: fclean all


# $<: é uma variável automática do Makefile 
# que representa o primeiro pré-requisito da regra, 
# que aqui é o arquivo .cpp a ser compilado.

# -c: instrui o compilador a compilar o arquivo sem 
# vinculá-lo (link), ou seja, gerar apenas o arquivo 
# objeto (.o), que pode ser vinculado posteriormente.

# -o $@: especifica o nome do arquivo de saída. 
# $@ é outra variável automática que representa o 
# nome do alvo, ou seja, o arquivo .o a ser criado.