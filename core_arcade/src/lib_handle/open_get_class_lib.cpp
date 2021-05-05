/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** open_get_class_lib
*/

#include "Core_Class_filehandle.hpp"
#include "Core_Class_error.hpp"
#include <dlfcn.h>

typedef IGraphic *(*ptr_graphic_class)();
typedef IGames *(*ptr_games_class)();

void LibHandle::open_lib(TYPE ACTION, std::string filename)
{
    switch (ACTION)
    {
    case GRAPHIC:
        this->lib_graphic = dlopen(filename.c_str(), RTLD_LAZY);
        break;
    case GAME:
        this->lib_games = dlopen(filename.c_str(), RTLD_LAZY);
        break;
    default:
        break;
    }
}


void *LibHandle::get_class_lib(TYPE ACTION)
{
    if (ACTION == GRAPHIC) {
        void *adress = (IGraphic *)dlsym(this->lib_graphic, "get_graphical_class");
        ptr_graphic_class ptr = (ptr_graphic_class)adress;
        return ptr();
    }
    if (ACTION == GAME) {
        void *adress = (IGames *)dlsym(this->lib_games, "get_game_class");
        ptr_games_class ptr = (ptr_games_class)adress;
        return ptr();
    }
    return nullptr;
}

void LibHandle::close_lib(TYPE ACTION, std::string filename)
{
    switch (ACTION)
    {
    case GRAPHIC:
        if (dlclose(this->lib_graphic) != 0)
            throw Core_Class_error(filename, "Error : can't dlclose");
        break;
    case GAME:
        if (dlclose(this->lib_games) != 0)
            throw Core_Class_error(filename, "Error : can't dlclose");
    default:
        break;
    }
}