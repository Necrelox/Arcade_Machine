/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** core_event_handler
*/

#include "Core_Class_core.hpp"

short Core::Core_Event_Handler(Scene *scene)
{
    switch (scene->action)
    {
        case CLOSE:
            this->class_graphic->closeWindow();
            std::cout << "close window\n";
            return -1;
            break;
        case PLAY:
            this->apply_game = 1;
            break;
    }

    switch (scene->select_game) {
        case menu:
            this->old_scene = this->select_game;
            this->select_game = menu;
            break;
        case Nibbler:
            this->old_scene = this->select_game;
            this->select_game = Nibbler;
            break;
        case Pacman:
            this->old_scene = this->select_game;
            this->select_game = Pacman;
            break;
    }

    switch(scene->select_graphic) {
        case sfml:
            this->select_graph = sfml;
            this->apply_graphic = 1;
            break;
        case sdl:
            this->select_graph = sdl;
            this->apply_graphic = 1;
            break;
        case ncurse:
            this->select_graph = ncurse;
            this->apply_graphic = 1;
            break;
        default:
            break;
    }
    return -1;
}