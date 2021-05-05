/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Core_Class_error
*/

#ifndef CORE_CLASS_ERROR_HPP_
#define CORE_CLASS_ERROR_HPP_

/*!
 * \file Core_Class_error.hpp
 * \author Nico
 * \brief Class Error
 * \version 2.0
*/

#include <exception>
#include <string>

/**
 * \class Core_Class_error inherits of class std::exception
 * \brief For throw a error with file and error message
 */

class Core_Class_error : public std::exception
{
    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn Core_Class_error(const std::string &file, const std::string &error_msg)
        ///
        /// \brief Constructor
        ///
        /// \param[in] file file contain a file name
        /// \param[in] error_msg message of error
        ///
        ////////////////////////////////////////////////////////////
        Core_Class_error(const std::string &file, const std::string &error_msg);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 1.0w
        ///
        /// \fn const std::string get_name_file() const
        ///
        /// \brief Getter of name file
        ///
        /// \return Name of file
        ///
        ////////////////////////////////////////////////////////////
        const std::string get_name_file() const;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 1.0
        ///
        /// \fn const std::string get_error_msg() const
        ///
        /// \brief Getter of error message
        ///
        /// \return Error message
        ///
        ////////////////////////////////////////////////////////////
        const std::string get_error_msg() const;

    private:
        std::string _file; /**< String contain name of file */
        std::string _error_msg; /**< String contain error message*/
};

#endif /* !CORE_CLASS_ERROR_HPP_ */
