/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SFML_window
*/

#include "Class_SFML.hpp"

void SFML::closeWindow()
{
    this->window.close();
}

bool SFML::windowIsOpen()
{
    return this->window.isOpen();
}

void SFML::set_Title(std::string title)
{
    this->window.setTitle(title);
}

int SFML::initialize_window(short window_x, short window_y, std::string name)
{
    sf::ContextSettings addons;
    addons.antialiasingLevel = 16.0;
    addons.depthBits = 32;
    this->window.create(sf::VideoMode(window_x, window_y), name, sf::Style::Titlebar | sf::Style::Close
        , addons);
    this->window.setVerticalSyncEnabled(true);
    this->window.setKeyRepeatEnabled(true);
    this->icon.loadFromFile("./ressources/menu/icon/icon_1.jpg");
    this->window.setIcon(250, 250, icon.getPixelsPtr());
    return 0;
}