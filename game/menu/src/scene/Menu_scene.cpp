/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Menu_scene
*/

#include "Class_Menu.hpp"

Entity *Menu::init_background()
{
    Entity *background = new Entity();
    background->path_entity = "./ressources/menu/layer/background.jpg";
    background->scale_x = 0.333333333, background->scale_y = 0.333333333;
    background->height = 2160;
    background->width = 3840;
    background->depth = 0;
    background->name = "background";
    background->draw = 1;
    return background;
}

Entity *Menu::init_layer_how()
{
    Entity *howlayer = new Entity();
    howlayer->path_entity = "./ressources/menu/layer/how.png";
    howlayer->scale_x = 0.333333333, howlayer->scale_y = 0.333333333;
    howlayer->height = 2160;
    howlayer->width = 3840;
    howlayer->depth = 2;
    howlayer->name = "howlayer";
    howlayer->draw = 0;
    return howlayer;
}

Entity *Menu::init_button_exit()
{
    Entity *exit = new Entity();
    exit->path_entity = "./ressources/menu/button/exit.png";
    exit->pos_x = 324, exit->pos_y = 515;
    exit->scale_x = 0.333333333, exit->scale_y = 0.333333333;
    exit->height = 300;
    exit->width = 345;
    exit->left = 345;
    exit->increment_left = 345;
    exit->draw = 1;
    exit->depth = 1;
    exit->name = "exit";
    exit->action = CLOSE;
    return exit;
}

Entity *Menu::init_button_how()
{
    Entity *how = new Entity();
    how->path_entity = "./ressources/menu/button/how.png";
    how->pos_x = 380, how->pos_y = 395;
    how->scale_x = 0.333333333, how->scale_y = 0.333333333;
    how->height = 306;
    how->width = 314;
    how->left = 314;
    how->increment_left = 314;
    how->depth = 1;
    how->name = "how";
    how->draw = 1;
    how->action = HOW;
    return how;
}

Entity *Menu::init_button_play()
{
    Entity *play = new Entity();
    play->path_entity = "./ressources/menu/button/play.png";
    play->pos_x = 745, play->pos_y = 175;
    play->scale_x = 0.333333333, play->scale_y = 0.333333333;
    play->height = 490;
    play->width = 390;
    play->left = 417;
    play->increment_left = 417;
    play->draw = 1;
    play->depth = 1;
    play->name = "play";
    play->action = PLAY;
    return play;
}

Entity *Menu::init_entity_switchGame()
{
    Entity *switcher = new Entity();
    switcher->path_entity = "./ressources/menu/entitys/games.png";
    switcher->pos_x = 472, switcher->pos_y = 140;
    switcher->scale_x = 0.333333333, switcher->scale_y = 0.333333333;
    switcher->height = 283;
    switcher->width = 490;
    switcher->left = 4;
    switcher->increment_left = 511;
    switcher->draw = 1;
    switcher->depth = 2;
    switcher->name = "game_switch";
    return switcher;
}

Entity *Menu::init_entity_switchGraphic()
{
    Entity *switcher = new Entity();
    switcher->path_entity = "./ressources/menu/entitys/graphics.png";
    switcher->pos_x = 988, switcher->pos_y = 220;
    switcher->scale_x = 0.333333333, switcher->scale_y = 0.333333333;
    switcher->height = 537;
    switcher->width = 682;
    switcher->left = 0;
    switcher->increment_left = 691;
    switcher->draw = 1;
    switcher->depth = 2;
    switcher->name = "graphic_switch";
    return switcher;
}

void Menu::init_button()
{
    this->scene->button.push_back(this->init_button_exit());
    this->scene->button.push_back(this->init_button_how());
    this->scene->button.push_back(this->init_button_play());
}

void Menu::init_layer()
{
    this->scene->layer.push_back(this->init_background());
    this->scene->layer.push_back(this->init_layer_how());
}

void Menu::init_entity()
{
    this->scene->entitys.push_back(this->init_entity_switchGame());
    this->scene->entitys.push_back(this->init_entity_switchGraphic());
}

Scene *Menu::init_scene()
{
    this->init_layer();
    this->init_button();
    this->init_entity();
    return this->scene;
}

Scene *Menu::update_scene(Position *cursor, TYPE ACTION)
{
    this->scene->action = this->event_handler(cursor, ACTION);
    return this->scene;
}