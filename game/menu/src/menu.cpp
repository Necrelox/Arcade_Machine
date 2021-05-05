/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** menu
*/

#include "Class_Menu.hpp"

std::string Menu::get_name_game() const
{
    return "The Arcade Machine";
}

IGames *get_game_class()
{
    return new Menu();
}

Menu::Menu()
{
    this->scene = new Scene;
}

Menu::~Menu()
{

}