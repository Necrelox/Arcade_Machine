/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** core_event
*/

#ifndef CORE_EVENT_HPP_
#define CORE_EVENT_HPP_

enum input_event {NOTHING = -0x2, CLIC = 0xaa, ESC = 0xab, CLOSE = 0xe, HOW = 0xf,
                PLAY = 0xfa}; /**< All Actions */

enum select_scene {menu = 0xffa, Nibbler = 0xffb, Pacman = 0xffc};
enum select_graphic {sfml = 0xff1, sdl = 0xff2, ncurse = 0xff3};
#endif /* !CORE_EVENT_HPP_ */
