/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** SDL
*/

#ifndef CLASS_SDL_HPP_
#define CLASS_SDL_HPP_

/*!
* \file Class_SDL.hpp
* \author Nico
* \brief
* \version 1.0
*/

#include "Class_Scene_SDL.hpp"

/**
 * \class ComponentWindow
 * \brief Contain window
*/

#define DEPTHMAX(x, list) for (size_t i = 0; i < list.size() ;i++) \
    x <= list[i]->depth ? x = list[i]->depth: x;

class ComponentWindow
{
    protected:
        SDL_Window *window; /**< Object SDL window*/
        bool isOpen;
};

/**
 * \class ComponentRender
 * \brief Contain render
*/
class ComponentRender
{
    protected:
        SDL_Renderer *render; /**< Object SDL render */
};

/**
 * \class ComponentEvent
 * \brief Contain sdl object for event
*/
class ComponentEvent
{
    protected:
        SDL_Event event; /**< Object sfml Event*/
};

/**
 * \class SDL inherits IGraphic, ComponentWindow, ComponentRender
 * \brief Contain all graphic function
*/
class SDL : public IGraphic, public ComponentWindow, public ComponentRender, public ComponentEvent
{
    private:
        RenderList *render_list; /**< Pointer contain a scene to draw*/

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 11/04/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity_Graphic *create_newElement(Entity *entity)
        ///
        /// \brief create a new element for render list
        ///
        /// \param[in] entity a element of scene core game
        ///
        /// \return Entity_Graphic (element of render)
        ///
        ////////////////////////////////////////////////////////////
        Entity_Graphic *create_newElement(Entity *entity);

    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn SDL()
        ///
        /// \brief Constructor of child class
        ///
        ////////////////////////////////////////////////////////////
        SDL();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn ~SDL()
        ///
        /// \brief destructor child class
        ///
        ////////////////////////////////////////////////////////////
        ~SDL();
        
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn int initialize_window(short window_x, short window_y, std::string name) override
        ///
        /// \brief init in IGraphic class 
        ///
        /// \param window_x Width of window
        /// \param window_y Height of window
        /// \param name Title of the window
        ///
        /// \return negative number if they was a error
        ///
        ////////////////////////////////////////////////////////////
        int initialize_window(short window_x, short window_y, std::string name) override;
        
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn bool windowIsOpen() override
        ///
        /// \brief True if window open else False
        ///
        /// \return True or False
        ///
        ////////////////////////////////////////////////////////////
        bool windowIsOpen() override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void closeWindow() override
        ///
        /// \brief close window
        ///
        ////////////////////////////////////////////////////////////
        void closeWindow() override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 1.0
        ///
        /// \fn void set_Title()
        ///
        /// \brief set new Title
        ///
        /// \param[in] title new title for set
        ///
        ////////////////////////////////////////////////////////////
        void set_Title(std::string title);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void display() override
        ///
        /// \brief display window and obj (sprites, text, shape...)
        ///
        ////////////////////////////////////////////////////////////
        void display() override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn int get_event() override
        ///
        /// \brief Get Event of Window make by user
        ///
        /// \return enum of event
        ///
        ////////////////////////////////////////////////////////////
        int get_event() override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Position *getMouse_position() override
        ///
        /// \brief Get mouse position
        ///
        /// \return Position class with x and y mouse
        ///
        ////////////////////////////////////////////////////////////
        Position *getMouse_position() override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn std::string get_name_graphic() const override
        ///
        /// \brief Get name of the graphic library
        ///
        /// \return name of library
        ///
        ////////////////////////////////////////////////////////////
        std::string get_name_graphic() const override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn bool in_terminal() const override
        ///
        /// \brief determine if this class render in a window or in a terminal
        ///
        /// \return true if the render is in terminal else false
        ///
        ////////////////////////////////////////////////////////////
        bool in_terminal() const override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void init_scene(Scene *scene) override
        ///
        /// \brief Init all element of scene game in sdl lib
        ///
        /// \param Scene of core game
        ///
        ////////////////////////////////////////////////////////////
        void init_scene(Scene *scene) override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void update_scene(Scene *scene) override
        ///
        /// \brief update all element of scene game in graphic lib
        ///
        /// \param scene of game
        ///
        ////////////////////////////////////////////////////////////
        void update_scene(Scene *scene) override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 1.0
        ///
        /// \fn void clear_graphical_scene() override
        ///
        /// \brief Clear list of render
        ///
        ////////////////////////////////////////////////////////////
        void clear_graphical_scene() override;
};

extern "C"
{
    ////////////////////////////////////////////////////////////
    ///
    /// \author Nico
    ///
    /// \date 31/03/21
    ///
    /// \version 2.0
    ///
    /// \fn IGraphic *get_graphical_class
    ///
    /// \brief return a child class
    ///
    /// \return Child class
    ///
    ////////////////////////////////////////////////////////////
    IGraphic *get_graphical_class();
}

#endif /* !CLASS_SDL_HPP_ */
