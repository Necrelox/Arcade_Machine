/*
** EPITECH PROJECT, 2021
** ù
** File description:
** Menu_animation
*/

#include "Class_Menu.hpp"

short Menu::animation_how(TYPE ACTION)
{
    size_t i = 0;
    static char key = 0;

    if (ACTION == HOW) {
        key = 100;
        for (size_t j = 0 ; j < this->scene->button.size();j++)
            this->scene->button[j]->draw = 0;
        for (size_t j = 0 ; j < this->scene->entitys.size(); j++)
            this->scene->entitys[j]->draw = 0;
        for (i = 0; i < this->scene->layer.size() && this->scene->layer[i]->name.compare("background") != 0 ;i++);
        if (this->scene->layer[i]->name.compare("background") == 0) {
            if (this->scene->layer[i]->pos_y > -2000)
                this->scene->layer[i]->pos_y -= 21;
            if (this->scene->layer[i]->pos_x > -1700)
                this->scene->layer[i]->pos_x -= 18;
            if (this->scene->layer[i]->scale_x < 1.75)
                this->scene->layer[i]->scale_x += 0.015;
            if (this->scene->layer[i]->scale_y < 1.75)
                this->scene->layer[i]->scale_y += 0.015;
            if (this->scene->layer[i]->pos_y <= -2000 && this->scene->layer[i]->pos_x <= -1700 &&
                this->scene->layer[i]->scale_y >= 1.75 && this->scene->layer[i]->scale_x >= 1.75)
                    key = 1;
            if (key == 1) {
                for (size_t j = 0 ; j < this->scene->layer.size(); j++)
                    if (this->scene->layer[j]->name.compare("howlayer") == 0)
                        this->scene->layer[j]->draw = 1;
                return HOW;
            }
        }
    }
    if (ACTION == ESC) {
        key = 100;
        for (size_t j = 0 ; j < this->scene->layer.size(); j++)
            if (this->scene->layer[j]->name.compare("howlayer") == 0)
                this->scene->layer[j]->draw = 0;
        for (i = 0; i < this->scene->layer.size() && this->scene->layer[i]->name.compare("background") != 0 ;i++);
        if (this->scene->layer[i]->name.compare("background") == 0) {
            if (this->scene->layer[i]->pos_y < 0)
                this->scene->layer[i]->pos_y += 20;
            if (this->scene->layer[i]->pos_x < 0)
                this->scene->layer[i]->pos_x += 20;
            if (this->scene->layer[i]->scale_x > 0.333333333)
                this->scene->layer[i]->scale_x -= 0.015;
            if (this->scene->layer[i]->scale_y > 0.333333333)
                this->scene->layer[i]->scale_y -= 0.015;

            if (this->scene->layer[i]->pos_y >= 0 && this->scene->layer[i]->pos_x >= 0 &&
                this->scene->layer[i]->scale_y <= 0.333333333 && this->scene->layer[i]->scale_x <= 0.333333333) {
                    this->scene->layer[i]->pos_y = 0, this->scene->layer[i]->pos_x = 0;
                    this->scene->layer[i]->scale_y = 0.333333333, this->scene->layer[i]->scale_x = 0.333333333;
                    key = 0;
                }
        }
        if (key == 0) {
            for (size_t j = 0 ; j < this->scene->button.size(); j++)
                    this->scene->button[j]->draw = 1;
            for (size_t j = 0 ; j < this->scene->entitys.size(); j++)
                    this->scene->entitys[j]->draw = 1;
            return NOTHING;
        }
    }
    return HOW;
}
