/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SDL
*/

#include "Class_SDL.hpp"

IGraphic *get_graphical_class()
{
    return new SDL();
}

bool SDL::in_terminal() const
{
    return false;
}

std::string SDL::get_name_graphic() const
{
    return "SDL";
}

SDL::SDL()
{

}

SDL::~SDL()
{

}