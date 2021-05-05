/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SDL_Display
*/

#include "Class_SDL.hpp"

void SDL::display()
{
    SDL_RenderClear(this->render);
    SDL_RenderPresent(this->render);
    // std::cout << "i'm display SDL" << std::endl;
}