/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SDL_sceneHandle
*/

#include "Class_SDL.hpp"
#include <SDL2/SDL_image.h>

Entity_Graphic *SDL::create_newElement(Entity *entity)
{
    Entity_Graphic *element = new Entity_Graphic;

    element->name = entity->name;
    element->depth = entity->depth;
    element->draw = entity->draw;


    element->rect = new SDL_Rect;
    element->image = new SDL_Surface;

    element->image = IMG_Load(entity->path_entity.c_str());
    element->texture = SDL_CreateTextureFromSurface(this->render, element->image);
    SDL_FreeSurface(element->image);

    // element->sprite = new sf::Sprite;

    // element->rect->height = entity->height;
    // element->rect->width = entity->width;
    // element->rect->top = entity->top;
    // element->rect->left = entity->left;

    // element->sprite->setTextureRect(*element->rect);
    // element->image->loadFromFile(entity->path_entity);
    // element->texture->loadFromImage(*element->image);
    // element->texture->setSmooth(true);
    // element->sprite->setTexture(*element->texture);
    // element->sprite->setPosition(sf::Vector2f(entity->pos_x, entity->pos_y));
    // element->sprite->setScale(sf::Vector2f(entity->scale_x , entity->scale_y));
    return element;
}

void SDL::init_scene(Scene *scene)
{
    this->render_list = new RenderList;
    short depth_max = 0;
    DEPTHMAX(depth_max, scene->layer)
    DEPTHMAX(depth_max, scene->button)
    DEPTHMAX(depth_max, scene->entitys)
    DEPTHMAX(depth_max, scene->particles)

    for (short i = 0; i <= depth_max ; i++) {
        for (size_t j = 0; j < scene->layer.size(); j++)
            if (scene->layer[j]->depth == i)
                this->render_list->list_element.push_back(this->create_newElement(scene->layer[j]));
        for (size_t j = 0; j < scene->button.size(); j++)
            if (scene->button[j]->depth == i)
                this->render_list->list_element.push_back(this->create_newElement(scene->button[j]));
        for (size_t j = 0; j < scene->particles.size(); j++)
            if (scene->particles[j]->depth == i)
                this->render_list->list_element.push_back(this->create_newElement(scene->particles[j]));
        for (size_t j = 0; j < scene->entitys.size(); j++)
            if (scene->entitys[j]->depth == i)
                this->render_list->list_element.push_back(this->create_newElement(scene->entitys[j]));
    }
    std::cout << "init_scene\n"; 
}
void SDL::update_scene(Scene *scene)
{
    (void)scene;
    // std::cout << "update_scene\n";
}

void SDL::clear_graphical_scene()
{
    std::cout << "clear_scene\n";
}
