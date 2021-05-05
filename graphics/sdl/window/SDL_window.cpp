/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SDL_window
*/

#include "Class_SDL.hpp"

void SDL::closeWindow()
{
    for (size_t i= 0 ; i < this->render_list->list_element.size(); i++) {
        SDL_DestroyTexture(this->render_list->list_element[i]->texture);
    }
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->render);
    SDL_Quit();
    this->isOpen = false;
}

bool SDL::windowIsOpen()
{
    return this->isOpen;
}

void SDL::set_Title(std::string title)
{
    SDL_SetWindowTitle(this->window, title.c_str());
}

int SDL::initialize_window(short window_x, short window_y, std::string name)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return -1;

    if ((this->window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        window_x, window_y, SDL_WINDOW_SHOWN)) == NULL)
            return -1;

    if ((this->render = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)) == NULL)
        return -1;
    SDL_SetRenderDrawColor(this->render, 255, 255, 255, 255);

    this->isOpen = true;
    return 0;
}
