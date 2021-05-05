/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** NCurse_window
*/

#include "Class_Ncurse.hpp"

void NCURSE::closeWindow()
{
}

bool NCURSE::windowIsOpen()
{
    return true; // modif
}

void NCURSE::set_Title(std::string title)
{
    (void)title;
}

int NCURSE::initialize_window(short window_x, short window_y, std::string name)
{
    std::cout << window_x << window_y << name << std::endl;
    return 0;
}