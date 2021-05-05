/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Class_nibbler
*/

#ifndef CLASS_NIBBLER_HPP_
#define CLASS_NIBBLER_HPP_

#include "IGames.hpp"
#include <iostream>

class CNibbler : public IGames
{
    private:
        Scene *scene; /* Pointer of scene for the menu*/
        Entity *init_background();
        void init_layer();
        
    public:
        CNibbler();
        ~CNibbler();
        std::string get_name_game() const override;
        Scene *init_scene() override;
        Scene *update_scene(Position *cursor, TYPE ACTION) override;
};

extern "C"
{
    IGames *get_game_class();
}

#endif /* !CLASS_NIBBLER_HPP_ */
