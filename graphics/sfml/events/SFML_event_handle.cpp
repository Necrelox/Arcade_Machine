/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SFML_event_handle
*/

#include "Class_SFML.hpp"

Position *SFML::getMouse_position()
{
    sf::Mouse mouse;
    sf::Vector2i pos = mouse.getPosition(this->window);
    Position *cursor_pos = new Position;
    cursor_pos->pos_x = pos.x;
    cursor_pos->pos_y = pos.y;
    return cursor_pos;
}

int SFML::get_event()
{
    while (this->window.pollEvent(this->event)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            return CLIC;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return ESC;
        switch (this->event.type) {
        case sf::Event::Closed :
            return CLOSE;
            break;
        default:
            break;
        }
    }
    return NOTHING;
}