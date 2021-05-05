/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

/*!
* \file IGames.hpp
* \author Nico
* \brief Contain interface game
* \version 1.0 
*/

#include <vector>
#include <string>
#include <memory>

#include "Class_Scene.hpp"

/**
 * \class Igames
 * \brief contain All abstraite function
*/

class IGames {
    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 07/04/21
        ///
        /// \version 1.0
        ///
        /// \fn virtual ~IGames() = default
        ///
        /// \brief destructor of IGames make
        ///
        ////////////////////////////////////////////////////////////
       virtual ~IGames() = default;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 07/04/21
        ///
        /// \version 1.0
        ///
        /// \fn virtual std::string get_name_game() const = 0
        ///
        /// \brief Get Name of Game
        ///
        /// \return Name of the Game
        ///
        ////////////////////////////////////////////////////////////
       virtual std::string get_name_game() const = 0;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 07/04/21
        ///
        /// \version 1.0
        ///
        /// \fn virtual Scene *init_scene() = 0
        ///
        /// \brief Initialize scene
        ///
        /// \return Scene *
        ///
        ////////////////////////////////////////////////////////////
       virtual Scene *init_scene() = 0;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 07/04/21
        ///
        /// \version 1.0
        ///
        /// \fn virtual Scene *update_scene(Position *cursor, TYPE ACTION) = 0
        ///
        /// \brief Update the scene
        ///
        /// \param[in] cursor position of cursor in window only with a window
        /// \param[in, out] ACTION action in window
        ///
        /// \return Scene *
        ///
        ////////////////////////////////////////////////////////////
       virtual Scene *update_scene(Position *cursor, TYPE ACTION) = 0;
};

#endif /* !IGAMES_HPP_ */
