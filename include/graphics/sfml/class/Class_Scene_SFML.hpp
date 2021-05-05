/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Class_Scene_SFML
*/

#ifndef CLASS_SCENE_SFML_HPP_
#define CLASS_SCENE_SFML_HPP_

/*!
* \file Class_Scene_SFML.hpp
* \author Nico
* \brief Contain scene graphic for render
* \version 2.0
*/

#include "IGraphic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>


/**
 * \class Entity_Grapic inherits Scale and Position Class
 * \brief Contain all element for render
*/
class Entity_Graphic : public Scale, public Position
{
    public:
        sf::IntRect *rect; /**< object sfml rectangle */
        sf::Image *image; /**< object sfml image */
        sf::Texture *texture; /**< object sfml texture*/
        sf::Sprite *sprite; /**< object sfml sprite */
        std::string name; /**< name of object */
        int rand; /**< rand for action */
        short depth; /**< depth of entity*/
        short draw; /**< 0 for not draw 1 for draw */
};

/**
 * \class Render
 * \brief Contain list for render
*/
class Render
{
    public:
        std::vector <Entity_Graphic *> list_element; /**< list for render */
};

#endif /* !CLASS_SCENE_SFML_HPP_ */
