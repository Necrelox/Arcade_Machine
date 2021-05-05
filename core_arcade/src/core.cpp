/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** core
*/

#include "Core_Class_core.hpp"
#include <chrono>

std::string Core::get_path_game(select_scene check)
{
    switch (check) {
    case menu:
        return "./lib/arcade_menu.so";
        break;
    case Nibbler:
        return "./lib/arcade_nibbler.so";
        break;
    case Pacman:
        return "./lib/arcade_pacman.so";
        break;
    default:
        break;
    }
    return nullptr;
}

void Core::switcher_game()
{
    delete this->scene;
    this->class_graphic->clear_graphical_scene();
    this->class_game.reset();
    this->lib->close_lib(GAME, this->get_path_game(this->old_scene));
    this->lib->verif_file(this->get_path_game(this->select_game));
    this->lib->open_lib(GAME, this->get_path_game(this->select_game));
    this->class_game = std::unique_ptr<IGames> ((IGames *)this->lib->get_class_lib(GAME));
    this->class_graphic->set_Title(this->class_game->get_name_game());
    this->scene = this->class_game->init_scene();
    this->class_graphic->init_scene(this->scene);
    std::cout << "load : " << this->get_path_game(this->select_game) << std::endl;
    this->apply_game = 0;
}

std::string Core::get_path_graphic(select_graphic check)
{
    switch (check)
    {
    case sfml:
        return "./lib/arcade_sfml.so";
        break;
    case sdl:
        return "./lib/arcade_sdl2.so";
        break;
    case ncurse:
        return "./lib/arcade_ncurses.so";
        break;
    default:
        break;
    }
    return nullptr;
}

void Core::switcher_graphic()
{
    this->class_graphic->closeWindow();
    this->class_graphic->clear_graphical_scene();
    this->class_graphic.reset();

    this->lib->close_lib(GRAPHIC, this->_file_graphic);
    this->_file_graphic = this->get_path_graphic(this->select_graph);
    this->lib->verif_file(this->_file_graphic);
    this->lib->open_lib(GRAPHIC, this->_file_graphic);
    this->class_graphic = std::unique_ptr<IGraphic> ((IGraphic *)this->lib->get_class_lib(GRAPHIC));
    this->class_graphic->init_scene(this->scene);
    this->apply_graphic = 0;
}

void Core::core()
{
    this->select_game = menu;
    this->old_scene = menu;
    this->lib->verif_file(this->get_path_game(this->select_game));
    this->lib->open_lib(GAME, this->get_path_game(this->select_game));
    this->class_game = std::unique_ptr<IGames> ((IGames *)this->lib->get_class_lib(GAME));

    if (this->class_graphic->initialize_window(1280, 720, this->class_game->get_name_game()) < 0)
        throw Core_Class_error(this->class_graphic->get_name_graphic(), "Error : Initialize window");
    this->scene = this->class_game->init_scene();
    this->class_graphic->init_scene(this->scene);

    auto time_start = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds elapse(20);

    while (this->class_graphic->windowIsOpen()) {
        if (this->apply_game == 1)
            this->switcher_game();

        if (this->apply_graphic == 1)
            this->switcher_graphic();

        auto time_stop = std::chrono::high_resolution_clock::now();
        this->class_graphic->display();
        if(elapse <= std::chrono::duration_cast<std::chrono::milliseconds>(time_stop - time_start)) {
            time_start = time_stop;
            this->event = this->class_graphic->get_event();
            this->scene = this->class_game->update_scene(this->class_graphic->getMouse_position(), this->event);
            this->Core_Event_Handler(this->scene);
            this->class_graphic->update_scene(this->scene);
        }
    }
}

Core::Core(std::string file_graphic) : _file_graphic(file_graphic)
{
    this->lib = std::make_unique <LibHandle>();
    this->lib->verif_file(this->_file_graphic);
    this->lib->open_lib(GRAPHIC, this->_file_graphic);
    this->class_graphic = std::unique_ptr<IGraphic> ((IGraphic *)this->lib->get_class_lib(GRAPHIC));
}

Core::~Core()
{
    this->class_graphic.reset();
    this->class_game.reset();
    lib->close_lib(GRAPHIC, this->_file_graphic);
    lib->close_lib(GAME, this->get_path_game(this->old_scene));
}