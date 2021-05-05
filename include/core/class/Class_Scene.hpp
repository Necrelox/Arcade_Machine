/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Class_Scene
*/

#ifndef CLASS_SCENE_HPP_
#define CLASS_SCENE_HPP_

/*!
* \file Class_Scene.hpp
* \author Nico
* \brief Content scene core for a game
* \version 4.0
*/

#include "core_define.hpp"
#include "core_event.hpp"
#include <vector>
#include <string>

/**
 * \class Position
 * \brief contain x and y position of one element 
 */
class Position
{
    public:
        float pos_x = 0; /**< position x relative to window */
        float pos_y = 0; /**< Position y relative to window */
};

/**
 * \class Scale
 * \brief contain x and y scale of one element
*/
class Scale
{
    public:
        float scale_x = 1; /**< scale x of entity */
        float scale_y = 1; /**< scale y of entity */
};

/**
 * \class Rect
 * \brief contain width and height of rectangle and membre for animation using
*/
class Rect
{
    public:
        int height = 0; /**< height of rectangle for render */
        int width = 0; /**< width of rectangle for render */
        int left = 0; /**< left decal of rectangle for render */
        int top = 0; /**< top decal of rectangle for render */
        int increment_left = 0; /**< number for left decal */
        int increment_top = 0; /**< number for top decal */
};

/**
 * \class Entity inherits Scale, Position and Rect class
 * \brief contain all information of one element
*/
class Entity : public Scale, public Position, public Rect
{
    public:
        std::string path_entity; /**< path of texture entity*/
        std::string name; /**< nameof entity */
        int rand = -1; /**< number for set a random animation (if animation is created )*/
        short depth = -1; /**< depth of entity (for draw*/
        short action = NOTHING; /**< Action of entity */
        short draw = 0; /**< 0 for not draw 1 for draw*/
};

/**
 * \class Scene
 * \brief contain all list for scene
*/
class Scene {
    public:
        short action = -1; /**< action find in scene */
        short select_game = menu; /**< select game */
        short select_graphic; /**< select graphic  */
        std::vector <Entity *> layer; /**< list of layer (background etc) */
        std::vector <Entity *> button; /**< list of buttons */
        std::vector <Entity *> entitys; /**< list of entitys*/
        std::vector <Entity *> particles; /**< list of particules */
};

#endif /* !CLASS_SCENE_HPP_ */
