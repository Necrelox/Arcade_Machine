/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** nibbler
*/

#include "Class_Nibbler.hpp"

std::string CNibbler::get_name_game() const
{
    std::cout << "OUI ça marche" << std::endl;
    return "Nibbler";
}

Entity *CNibbler::init_background()
{
    Entity *background = new Entity();
    background->path_entity = "./ressources/game/fond.jpg";
    background->scale_x = 1, background->scale_y = 1;
    background->height = 720;
    background->width = 1280;
    background->depth = 0;
    background->name = "background";
    background->draw = 1;
    return background;
}

void CNibbler::init_layer()
{
    this->scene->layer.push_back(this->init_background());
}

Scene *CNibbler::init_scene()
{
    this->init_layer();
    std::cout << "OUI ça marche" << std::endl;
    return this->scene;
}

Scene *CNibbler::update_scene(Position *cursor, TYPE ACTION)
{
    (void)cursor;
    (void)ACTION;
    this->scene->action = ACTION;
    std::cout << "OUI ça marche" << std::endl;
    return this->scene;
}

CNibbler::CNibbler()
{
    this->scene = new Scene;
}

CNibbler::~CNibbler()
{
}

IGames *get_game_class()
{
    return new CNibbler();
}