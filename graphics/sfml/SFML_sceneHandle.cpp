/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SFML_sceneHandle
*/

#include "Class_SFML.hpp"

Entity_Graphic *SFML::create_newElement(Entity *entity)
{
    Entity_Graphic *element = new Entity_Graphic;

    element->name = entity->name;
    element->depth = entity->depth;
    element->draw = entity->draw;
    element->sprite = new sf::Sprite;
    element->texture = new sf::Texture;
    element->image = new sf::Image;
    element->rect = new sf::IntRect;
    element->rect->height = entity->height;
    element->rect->width = entity->width;
    element->rect->top = entity->top;
    element->rect->left = entity->left;
    element->sprite->setTextureRect(*element->rect);
    element->image->loadFromFile(entity->path_entity);
    element->texture->loadFromImage(*element->image);
    element->texture->setSmooth(true);
    element->sprite->setTexture(*element->texture);
    element->sprite->setPosition(sf::Vector2f(entity->pos_x, entity->pos_y));
    element->sprite->setScale(sf::Vector2f(entity->scale_x , entity->scale_y));
    return element;
}

void SFML::init_scene(Scene *scene)
{
    this->render = new Render;
    short depth_max = 0;
    DEPTHMAX(depth_max, scene->layer)
    DEPTHMAX(depth_max, scene->button)
    DEPTHMAX(depth_max, scene->entitys)
    DEPTHMAX(depth_max, scene->particles)

    for (short i = 0; i <= depth_max ; i++) {
        for (size_t j = 0; j < scene->layer.size(); j++)
            if (scene->layer[j]->depth == i)
                this->render->list_element.push_back(this->create_newElement(scene->layer[j]));
        for (size_t j = 0; j < scene->button.size(); j++)
            if (scene->button[j]->depth == i)
                this->render->list_element.push_back(this->create_newElement(scene->button[j]));
        for (size_t j = 0; j < scene->particles.size(); j++)
            if (scene->particles[j]->depth == i)
                this->render->list_element.push_back(this->create_newElement(scene->particles[j]));
        for (size_t j = 0; j < scene->entitys.size(); j++)
            if (scene->entitys[j]->depth == i)
                this->render->list_element.push_back(this->create_newElement(scene->entitys[j]));
    }
}

void SFML::update_entity(Entity *entity, size_t id)
{
    // std::cout << "name update : " << this->render->list_element[id]->name << std::endl;
    this->render->list_element[id]->pos_x = entity->pos_x;
    this->render->list_element[id]->pos_y = entity->pos_y;
    this->render->list_element[id]->rand = entity->rand;
    this->render->list_element[id]->scale_x = entity->scale_x;
    this->render->list_element[id]->scale_y = entity->scale_y;
    this->render->list_element[id]->depth = entity->depth;
    this->render->list_element[id]->rect->width = entity->width;
    this->render->list_element[id]->rect->height = entity->height;
    this->render->list_element[id]->rect->left = entity->left;
    this->render->list_element[id]->rect->top = entity->top;
    this->render->list_element[id]->draw = entity->draw;
    this->render->list_element[id]->sprite->setTextureRect(*this->render->list_element[id]->rect);
    this->render->list_element[id]->sprite->setPosition(sf::Vector2f(this->render->list_element[id]->pos_x, this->render->list_element[id]->pos_y));
    this->render->list_element[id]->sprite->setScale(sf::Vector2f(this->render->list_element[id]->scale_x , this->render->list_element[id]->scale_y));
}

void SFML::update_scene(Scene *scene)
{
    for (size_t i = 0, j = 0; i < scene->layer.size(); i++) {
        for (j = 0; j < this->render->list_element.size() &&
            scene->layer[i]->name.compare(this->render->list_element[j]->name) != 0; j++);
        if (scene->layer[i]->name.compare(this->render->list_element[j]->name) == 0) {}
            this->update_entity(scene->layer[i], j);
    }
    for (size_t i = 0, j = 0; i < scene->button.size(); i++) {
        for (j = 0; j < this->render->list_element.size() &&
            scene->button[i]->name.compare(this->render->list_element[j]->name) != 0; j++);
        if (scene->button[i]->name.compare(this->render->list_element[j]->name) == 0)
            this->update_entity(scene->button[i], j);
    }
    for (size_t i = 0, j = 0; i < scene->entitys.size(); i++) {
        for (j = 0; j < this->render->list_element.size() &&
            scene->entitys[i]->name.compare(this->render->list_element[j]->name) != 0; j++);
        if (scene->entitys[i]->name.compare(this->render->list_element[j]->name) == 0)
            this->update_entity(scene->entitys[i], j);
    }
    for (size_t i = 0, j = 0; i < scene->particles.size(); i++) {
        for (j = 0; j < this->render->list_element.size() &&
            scene->particles[i]->name.compare(this->render->list_element[j]->name) != 0; j++);
        if (scene->particles[i]->name.compare(this->render->list_element[j]->name) == 0)
            this->update_entity(scene->particles[i], j);
    }
}

void SFML::clear_graphical_scene()
{
    this->window.clear();
    this->render->list_element.clear();
}