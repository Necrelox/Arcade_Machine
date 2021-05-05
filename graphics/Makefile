##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

################# Rules ###################
all:
	@make --no-print-directory -C ncurse re
	@make --no-print-directory -C sdl re
	@make --no-print-directory -C sfml re

clean:
	@make --no-print-directory -C ncurse clean
	@make --no-print-directory -C sdl clean
	@make --no-print-directory -C sfml clean

fclean: clean
	@make --no-print-directory -C ncurse fclean
	@make --no-print-directory -C sdl fclean
	@make --no-print-directory -C sfml fclean

re: fclean all

###########################################