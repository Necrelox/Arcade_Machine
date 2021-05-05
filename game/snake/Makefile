##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

############### Compiler ##################
CC = @g++
###########################################

###############  Default  #################
NAME 	= ../../lib/arcade_nibbler.so
SRC		= 	$(wildcard src/*.cpp)

OBJ		=	$(SRC:.cpp=.o)
INCPATH = 	-I../../include/game/snake 			\
			-I../../include/game/snake/class 	\
			-I../../include/core/				\
			-I../../include/core/interfaces		\
			-I../../include/core/class
LIB 	=
CFLAGS	= -Wall -Wextra -Werror -g3 -fPIC
###########################################


################# Rules ###################

.cpp.o:
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m Compile\e[1;93m" $< "\e[1;91mto\e[1;92m" $@ "\e[0m"
	$(CC) $(CFLAGS) $(INCPATH) -c $< -o $@

all: $(OBJ)
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m LINK\e[1;93m" $< "\e[1;91mto\e[1;92m" $(NAME) "\e[0m"
	$(CC) -shared $(OBJ) -o $(NAME)

	@echo "\e[1;92m Compile library Nibbler, Finish ! \e[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

###########################################