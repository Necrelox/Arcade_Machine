/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** main
*/

/*! 
 * \file main.cpp
 * \author Nico
 * \brief entry point of ARCADE MACHINE
 * \version 2.0
*/

/**
 * \mainpage Main page: of arcade machine
 * If number of argument is two, try core programme or catch an exception.
*/

#include "Core_Class_core.hpp"

int main(int ac, char **av)
{
    if (ac == 2) {
        try {
            Core core(av[1]);
            core.core();
            return OK;
        }
        catch(Core_Class_error &error) {
            std::cout << error.what() << " : " << error.get_name_file() << std::endl << error.get_error_msg() << std::endl;
            return ERROR;
        }
    }
    std::cout << "Too much or less argument.\n\t For use : ./arcade ./lib/[graphic name]\n";
    return ERROR;
}
