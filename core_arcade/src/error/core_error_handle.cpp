/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** core_error_handle
*/

#include "Core_Class_error.hpp"

const std::string Core_Class_error::get_error_msg() const
{
    return _error_msg;
}

const std::string Core_Class_error::get_name_file() const
{
    return _file;
}

Core_Class_error::Core_Class_error(const std::string &file, const std::string &error_msg): _file(file), _error_msg(error_msg)
{

}