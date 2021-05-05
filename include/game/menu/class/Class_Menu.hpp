/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Core_Class_Menu
*/

#ifndef CORE_CLASS_MENU_HPP_
#define CORE_CLASS_MENU_HPP_

#include <iostream>
#include "IGames.hpp"

class Menu : public IGames
{
    private:
        Scene *scene; /**< Pointer of scene for the menu*/

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_button_how()
        ///
        /// \brief Init button how to play (button vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_button_how();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_button_exit()
        ///
        /// \brief Init button exit (button vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_button_exit();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_button_play()
        ///
        /// \brief Init button play (button vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_button_play();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_button_play()
        ///
        /// \brief Init Buttons (button vector)
        ///
        ////////////////////////////////////////////////////////////
        void init_button();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_background()
        ///
        /// \brief Init Background (layer vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_background();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_layer_how()
        ///
        /// \brief Init how to play layer (layer vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_layer_how();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_layer_how()
        ///
        /// \brief Init entity switch game (entity vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_entity_switchGame();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 10/04/21
        ///
        /// \version 2.0
        ///
        /// \fn Entity *init_entity_switchGraphic()
        ///
        /// \brief Init entity switch graphic (entity vector)
        ///
        /// \return Entity_s *
        ///
        ////////////////////////////////////////////////////////////
        Entity *init_entity_switchGraphic();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn void init_layer()
        ///
        /// \brief Init all layers
        ///
        ////////////////////////////////////////////////////////////
        void init_layer();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void init_layer()
        ///
        /// \brief Init all entity
        ///
        ////////////////////////////////////////////////////////////
        void init_entity();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn short animation_how(TYPE ACTION)
        ///
        /// \brief Animation How
        ///
        /// \param[in, out] Action set how to play or cancel
        ///
        /// \return how or nothing
        ///
        ////////////////////////////////////////////////////////////
        short animation_how(TYPE ACTION);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn short event_button(Position *cursor, TYPE ACTION)
        ///
        /// \brief Event button hover and clic
        ///
        /// \param[in] cursor postion of mouse
        /// \param[in, out] ACTION action of event (exemple clic..)
        ///
        /// \return action of button or nothing
        ///
        ////////////////////////////////////////////////////////////
        short event_button(Position *cursor, TYPE ACTION);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn void event_how_to_play(TYPE ACTION)
        ///
        /// \brief Event how to play
        ///
        /// \param ACTION for how to play display
        ///
        ////////////////////////////////////////////////////////////
        void event_how_to_play(TYPE ACTION);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn void event_entity_switchGame(Position *cursor, TYPE ACTION)
        ///
        /// \brief Event switch game
        ///
        /// \param[in] cursor postion of mouse
        /// \param[in] ACTION for switch or not
        ///
        ////////////////////////////////////////////////////////////
        void event_entity_switchGame(Position *cursor, TYPE ACTION);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn void event_entity_switchGraphic(Position *cursor, TYPE ACTION)
        ///
        /// \brief Event switch game
        ///
        /// \param[in] cursor postion of mouse
        /// \param[in] ACTION for switch or not
        ///
        ////////////////////////////////////////////////////////////
        void event_entity_switchGraphic(Position *cursor, TYPE ACTION);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn short event_handler(Position *cursor, TYPE ACTION)
        ///
        /// \brief Event button hover and clic
        ///
        /// \param[in] cursor postion of mouse
        /// \param[in, out] ACTION action of event (exemple clic..)
        ///
        /// \return action
        ///
        ////////////////////////////////////////////////////////////
        short event_handler(Position *cursor, TYPE ACTION);

    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn Menu()
        ///
        /// \brief Constructor of child class
        ///
        ////////////////////////////////////////////////////////////
        Menu();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn ~Menu()
        ///
        /// \brief Destroy child class
        ///
        ////////////////////////////////////////////////////////////
        ~Menu();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn std::string get_name_game() const override
        ///
        /// \brief Get Name of Game
        ///
        /// \return Name of the Game
        ///
        ////////////////////////////////////////////////////////////
        std::string get_name_game() const override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn Scene *init_scene() override
        ///
        /// \brief Initialize scene
        ///
        /// \return Scene *
        ///
        ////////////////////////////////////////////////////////////
        Scene *init_scene() override;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 31/03/21
        ///
        /// \version 1.0
        ///
        /// \fn Scene *update_scene(Position *cursor, TYPE ACTION) override
        ///
        /// \brief Update the scene
        ///
        /// \param[in] cursor position of cursor in window only with a window
        /// \param[in, out] ACTION action in window
        ///
        /// \return Scene *
        ///
        ////////////////////////////////////////////////////////////
        Scene *update_scene(Position *cursor, TYPE ACTION) override;
};

extern "C"
{
    ////////////////////////////////////////////////////////////
    ///
    /// \author Nico
    ///
    /// \date 31/03/21
    ///
    /// \version 1.0
    ///
    /// \fn IGames *get_game_class()
    ///
    /// \brief return a child class
    ///
    /// \return Child class
    ///
    ///////////////////////////////////////////////////////////
    IGames *get_game_class();
}

#endif /* !CORE_CLASS_MENU_HPP_ */
