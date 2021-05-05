##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

############### Compiler ##################
CC = @g++
###########################################

############### Unit_Test #################
NAME 	= unit_tests
SRC		= 	$(filter-out core_arcade/src/main.cpp, $(wildcard core_arcade/src/*.cpp)) \
			$(wildcard lib/ncurse/display/*.cpp) 						\
			$(wildcard lib/sdl/display/*.cpp) 							\
			$(wildcard lib/sfml/display/*.cpp)							\
			$(wildcard tests/core_arcade/*.cpp)

OBJ		=	$(SRC:.cpp=.o)
CFLAGS	= -Wall -Wextra -Werror -g3
INCPATH = 	-I./include/core_arcade/class			\
			-I./include/core_arcade/interfaces		\
			-I./include/core_arcade/				\
			-I./include/lib/ncurse/class	\
			-I./include/lib/sdl/class		\
			-I./include/lib/sfml/class

LIB 	= -lcriterion --coverage
###########################################

################# Rules ###################

all:
	@make --no-print-directory -C core_arcade/ re
	@make --no-print-directory -C game/menu re
	@make --no-print-directory -C graphics/ re
	@make --no-print-directory -C game/ re

.cpp.o:
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m Compile\e[1;93m" $< "\e[1;91mto\e[1;92m" $@ "\e[0m"
	$(CC) $(CFLAGS) $(INCPATH) $(LIB) -c $< -o $@

unit: $(OBJ)
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m LINK\e[1;93m" $(OBJ) "\e[1;91mto\e[1;92m" $(NAME) "\e[0m"
	$(CC) $(OBJ) $(LIB) -o $(NAME)

	@echo "\e[1;92m Compile Unit Test , Finish ! \e[0m"

exec: $(NAME)
	./unit_tests

core:
	@make --no-print-directory -C core_arcade/ re
	@make --no-print-directory -C game/menu re

games:
	@make --no-print-directory -C game/ re

graphicals:
	@make --no-print-directory -C graphics/ re

clean:
	@make --no-print-directory -C core_arcade/ clean
	@make --no-print-directory -C game/menu clean
	@make --no-print-directory -C graphics/ clean
	@make --no-print-directory -C game/ clean
	@rm -f $(OBJ)

fclean: clean
	@make --no-print-directory -C core_arcade/ fclean
	@make --no-print-directory -C game/menu fclean
	@make --no-print-directory -C graphics/ fclean
	@make --no-print-directory -C game/ fclean
	@rm -f $(NAME)

re: fclean all

tests_run: fclean unit exec

###########################################