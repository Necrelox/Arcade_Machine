/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** NCurse
*/

#include "Class_Ncurse.hpp"

void NCURSE::init_scene(Scene *scene)
{
    (void)scene;
}

void NCURSE::update_scene(Scene *scene)
{
    (void)scene;
}

void NCURSE::clear_graphical_scene()
{
}

IGraphic *get_graphical_class()
{
    return new NCURSE();
}

bool NCURSE::in_terminal() const
{
    return true;
}

std::string NCURSE::get_name_graphic() const
{
    return "Ncurse";
}

NCURSE::NCURSE()
{

}

NCURSE::~NCURSE()
{

}
