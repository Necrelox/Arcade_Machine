/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Class_Scene_SDL
*/

#ifndef CLASS_SCENE_SDL_HPP_
#define CLASS_SCENE_SDL_HPP_

#include "IGraphic.hpp"
#include <SDL2/SDL.h>
#include <memory>
#include <iostream>

/**
 * \class Entity_Grapic inherits Scale and Position Class
 * \brief Contain all element for render
*/
class Entity_Graphic : public Scale, public Position
{
    public:
        SDL_Rect *rect; /**< object sdl rectangle */
        SDL_Surface *image; /**< obect sdl surface image (manage by cpu) */
        SDL_Texture *texture; /**< obect sdl texture */
        // sf::Image *image; /**< object sfml image */
        // sf::Texture *texture; /**< object sfml texture*/
        // sf::Sprite *sprite; /**< object sfml sprite */

        std::string name; /**< name of object */
        int rand; /**< rand for action */
        short depth; /**< depth of entity*/
        short draw; /**< 0 for not draw 1 for draw */
};

/**
 * \class Render
 * \brief Contain list for render
*/
class RenderList
{
    public:
        std::vector <Entity_Graphic *> list_element; /**< list for render */
};

#endif /* !CLASS_SCENE_SDL_HPP_ */
