/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SFML
*/

#include "Class_SFML.hpp"

IGraphic *get_graphical_class()
{
    return new SFML();
}

bool SFML::in_terminal() const
{
    return false;
}

std::string SFML::get_name_graphic() const
{
    return "SFML";
}

SFML::SFML()
{

}

SFML::~SFML()
{

}