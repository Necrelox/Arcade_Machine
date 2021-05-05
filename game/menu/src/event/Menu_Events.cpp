/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Menu_Events
*/

#include "Class_Menu.hpp"

short Menu::event_button(Position *cursor, TYPE ACTION)
{
    for (size_t i = 0; i < this->scene->button.size() ; i++) {
        if (this->scene->button[i]->pos_x < cursor->pos_x &&
            cursor->pos_x < (this->scene->button[i]->pos_x + this->scene->button[i]->width / 2) &&
            this->scene->button[i]->pos_y <= cursor->pos_y &&
            cursor->pos_y <= (this->scene->button[i]->pos_y + this->scene->button[i]->height / 3)) {
                if (ACTION == CLIC)
                    return this->scene->button[i]->action;
                this->scene->button[i]->left = 0;
            }
        else
            this->scene->button[i]->left = this->scene->button[i]->increment_left;
    }
    return ACTION;
}

void Menu::event_how_to_play(TYPE ACTION)
{
    switch (ACTION) {
    case HOW:
        this->animation_how(HOW);
        break;
    case ESC:
        this->animation_how(ESC);
        break;
    default:
        break;
    }
}

void Menu::event_entity_switchGame(Position *cursor, TYPE ACTION)
{
    for (size_t i = 0; i < this->scene->entitys.size(); i++) {
        if (this->scene->entitys[i]->name.compare("game_switch") == 0)
            if (this->scene->entitys[i]->pos_x < cursor->pos_x &&
                cursor->pos_x < (this->scene->entitys[i]->pos_x + this->scene->entitys[i]->width / 3) &&
                this->scene->entitys[i]->pos_y <= cursor->pos_y &&
                cursor->pos_y <= (this->scene->entitys[i]->pos_y + this->scene->entitys[i]->height / 3)) {
                    if (ACTION == CLIC) {
                        this->scene->entitys[i]->left += this->scene->entitys[i]->increment_left;
                        if (this->scene->entitys[i]->left >= 1533)
                            this->scene->entitys[i]->left = 4;
                        switch (this->scene->entitys[i]->left) {
                        case 4:
                            this->scene->select_game = menu;
                            break;
                        case 515:
                            this->scene->select_game = Nibbler;
                            break;
                        case 1026:
                            this->scene->select_game = Pacman;
                            break;
                        default:
                            break;
                        }
                    }
                }
    }
}

void Menu::event_entity_switchGraphic(Position *cursor, TYPE ACTION)
{
    for (size_t i = 0; i < this->scene->entitys.size(); i++) {
        if (this->scene->entitys[i]->name.compare("graphic_switch") == 0)
            if (this->scene->entitys[i]->pos_x < cursor->pos_x &&
                cursor->pos_x < (this->scene->entitys[i]->pos_x + this->scene->entitys[i]->width / 3 - 10) &&
                this->scene->entitys[i]->pos_y + 50 <= cursor->pos_y &&
                cursor->pos_y <= (this->scene->entitys[i]->pos_y + this->scene->entitys[i]->height / 3) - 10) {
                    if (ACTION == CLIC) {
                        this->scene->entitys[i]->left += this->scene->entitys[i]->increment_left;
                        if (this->scene->entitys[i]->left >= 2073)
                            this->scene->entitys[i]->left = 0;
                        switch (this->scene->entitys[i]->left)
                        {
                            case 0:
                                this->scene->select_graphic = sfml;
                                break;
                            case 691:
                                this->scene->select_graphic = sdl;
                                break;
                            case 1382:
                                this->scene->select_graphic = ncurse;
                                break;
                            default:
                                break;
                        }
                    }
                }
    }
}

short Menu::event_handler(Position *cursor, TYPE ACTION)
{
    static short oldAction = NOTHING;

    this->event_entity_switchGame(cursor, ACTION);
    this->event_entity_switchGraphic(cursor, ACTION);

    if (ACTION == CLOSE)
        return CLOSE;
    if (ACTION == ESC)
        oldAction = ESC;

    if (oldAction != HOW)
        ACTION = this->event_button(cursor, ACTION);

    if (ACTION == HOW)
        oldAction = HOW;
    switch (oldAction) {
    case HOW:
        this->event_how_to_play(HOW);
        break;
    case ESC:
        this->event_how_to_play(ESC);
        break;
    default:
        break;
    }
    // std::cout << this->scene->select_game << std::endl; 
    return ACTION;
}