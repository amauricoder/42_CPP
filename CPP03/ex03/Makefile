# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 15:01:11 by aconceic          #+#    #+#              #
#    Updated: 2024/11/29 14:23:22 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex03
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp \

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


#-Wshadow -Wno-shadow

#Usar -Wshadow:
#    Quando você quer garantir que variáveis com o mesmo nome em diferentes escopos sejam evitadas, para aumentar a clareza do código.
#    Em projetos grandes ou em equipe, onde o shadowing pode causar confusão e bugs sutis.

#Usar -Wno-shadow:
#    Se você entende os impactos do shadowing no código e não considera que isso seja problemático no seu projeto.
#    Quando o uso de shadowing é deliberado e os avisos do compilador são excessivos ou desnecessários.

