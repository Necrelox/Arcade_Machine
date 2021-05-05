/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Core_class_core
*/


#ifndef CORE_CLASS_CORE_HPP_
#define CORE_CLASS_CORE_HPP_

/*!
* \file Core_Class_core.hpp
* \author Nico
* \brief Core of Arcade, content pointer of lib graphic and lib game
* \version 3.0
*/

#include "Core_Class_filehandle.hpp"
#include "Core_Class_error.hpp"
#include <iostream>
#include <vector>

/**
 * \class ComponentEvent
 * \brief contain an events like close window or other
*/
class ComponentEvent
{
    protected:
        short event; /**< event that was retrieved of graphic class */
};

/**
 * \class Core inherits of class ComponentEvent
 * \brief Core contain algo of arcade machine and handle basic event like close window
*/

class Core : public ComponentEvent
{
    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 21/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Core(std::string file_graphic)
        ///
        /// \brief Constructor of child class
        ///
        /// \param[in] file_graphic path of graphic library
        ///
        ////////////////////////////////////////////////////////////
        Core(std::string file_graphic);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 21/03/21
        ///
        /// \version 2.0
        ///
        /// \fn ~Core()
        ///
        /// \brief Destructor of child class
        ///
        ////////////////////////////////////////////////////////////
        ~Core();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 8/04/21
        ///
        /// \version 7.0
        ///
        /// \fn core()
        ///
        /// \brief Core of arcade machine with loop and switch library etc
        ///
        ////////////////////////////////////////////////////////////
        void core();


    private:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 8/04/21
        ///
        /// \version 9.0
        ///
        /// \fn Core_Event_Handler(TYPE ACTION)
        ///
        /// \brief Basics Event Core (exemple close window is a basic event he modif the core not the game) 
        ///
        /// \param scene contain action for arcade machine and select game/graphic
        ///
        /// \return a action for core game
        ///
        ////////////////////////////////////////////////////////////
        short Core_Event_Handler(Scene *scene);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 1.0
        ///
        /// \fn std::string get_path_game(select_scene check)
        ///
        /// \brief Search path of game
        ///
        /// \param[in] check enum of game for search path
        ///
        /// \return Path of game
        ///
        ////////////////////////////////////////////////////////////
        std::string get_path_game(select_scene check);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 2.0
        ///
        /// \fn void switcher_game()
        ///
        /// \brief Delete old scene delete list of render and set new game with new scene 
        ///
        ////////////////////////////////////////////////////////////
        void switcher_game();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 1.0
        ///
        /// \fn std::string get_path_graphic(select_scene check)
        ///
        /// \brief Search path of game
        ///
        /// \param[in] check enum of graphic for search path
        ///
        /// \return Path of graphic
        ///
        ////////////////////////////////////////////////////////////
        std::string get_path_graphic(select_graphic check);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 1.0
        ///
        /// \fn void switcher_graphic()
        ///
        /// \brief Delete old class graphic and set new graphic class 
        ///
        ////////////////////////////////////////////////////////////
        void switcher_graphic();


        Scene *scene; /**< Contain a pointer of scene game like menu or other*/
        select_scene select_game; /**< Select game */
        select_scene old_scene; /**< Old Game*/
        unsigned apply_game : 1; /**< Apply select game*/
        select_graphic select_graph; /**< Select graphic */
        unsigned apply_graphic : 1; /**< Apply select graphic*/
        

        std::string _file_graphic; /**< name of file graphic */
        std::string _file_scene; /**< name of file scene */
        std::unique_ptr<LibHandle> lib; /**< unique ptr of LibHandler (Class for handling graphic and game library) */
        std::unique_ptr<IGraphic> class_graphic; /**< unique_ptr of Graphic class*/
        std::unique_ptr<IGames> class_game; /**< unique_ptr of Games class*/
};

#endif /* !CORE_CLASS_CORE_HPP_ */