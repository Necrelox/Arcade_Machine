/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SDL_event_handle
*/

#include "Class_SDL.hpp"

Position *SDL::getMouse_position()
{
    Position *pos = new Position;
    pos->pos_x = 0, pos->pos_y = 0;
    return pos;
}

int SDL::get_event()
{
    while (SDL_PollEvent(&this->event)) {
        // if (SDL_GetKeyState)

        switch (this->event.type) {
            case SDL_QUIT:
                return CLOSE;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (this->event.button.button == SDL_BUTTON_LEFT)
                    return CLIC;
                break;
            default:
                break;
        }
    }
    return NOTHING;
}