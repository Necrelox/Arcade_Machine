/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SFML_display
*/

#include "Class_SFML.hpp"
#include <unistd.h>

void SFML::animate_icon()
{
    std::string icon_path;
    static int i = 1;
    static sf::Clock clock;

    if (clock.getElapsedTime() > sf::milliseconds(250))  {
        icon_path = "./ressources/menu/icon/icon_" + std::to_string(i) + ".jpg";
        this->icon.loadFromFile(icon_path);
        this->window.setIcon(250, 250, this->icon.getPixelsPtr());
        i++;
        clock.restart();
        i = i == 60 ? 1 :i;
    }
}

void SFML::display_layer()
{
    for (size_t i = 0; i < this->render->list_element.size(); i++)
        if (this->render->list_element[i]->draw == 1)
            window.draw(*this->render->list_element[i]->sprite);

}

void SFML::display()
{
    this->window.clear();
    this->display_layer();
    this->animate_icon();
    this->window.display();
}