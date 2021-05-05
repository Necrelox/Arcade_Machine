/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** Core_Class_filehandle
*/

#ifndef CLASS_FILE_LIB_HPP_
#define CLASS_FILE_LIB_HPP_

/*!
* \file Core_Class_filehandle.hpp
* \author Nico
* \brief Contain a handle class of library 
*/

#include "core_define.hpp"
#include "IGraphic.hpp"
#include "IGames.hpp"
#include <sys/stat.h>

#ifdef __unix__
    #include <unistd.h>
#endif

/**
 * \class LibHandle
 * \brief verif open close libray graphic or game
*/
class LibHandle
{
    private:
        void *lib_graphic; /**< pointer of lib_graphic current */
        void *lib_games; /**< pointer of lib game current */

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void verif_if_file_exist(std::string filename
        ///
        /// \brief Check if the file exist
        ///
        /// \param[in] filename path for verif
        ///
        ////////////////////////////////////////////////////////////
        void verif_if_file_exist(std::string filename);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void verif_if_file_is_not_empty(std::string filename)
        ///
        /// \brief Check if the file is not empty
        ///
        /// \param[in] filename path for verif
        ///
        ////////////////////////////////////////////////////////////
        void verif_if_file_is_not_empty(std::string filename);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void verif_if_acces_to_read(std::string filename)
        ///
        /// \brief Check if they was access to read
        ///
        /// \param[in] filename path for verif
        ///
        ////////////////////////////////////////////////////////////
        void verif_if_acces_to_read(std::string filename);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void verif_if_elf_file(std::string filename)
        ///
        /// \brief Check if the file exist
        ///
        /// \param[in] filename path for verif
        ///
        ////////////////////////////////////////////////////////////
        void verif_if_elf_file(std::string filename);

    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 3.0
        ///
        /// \fn LibHandle()
        ///
        /// \brief Constructor
        ///
        ////////////////////////////////////////////////////////////
        LibHandle();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 1.0
        ///
        /// \fn ~LibHandle()
        ///
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        ~LibHandle();

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void verif_file(std::string filename)
        ///
        /// \brief Call all method of verif in private
        ///
        /// \param[in] filename patth for check
        ///
        ////////////////////////////////////////////////////////////
        void verif_file(std::string filename);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 1.0
        ///
        /// \fn void open_lib(TYPE ACTION, std::string filename)
        ///
        /// \brief Open Library (Graphic or Game)
        ///
        /// \param[in] ACTION Game or Graphic select if you want open a graphic lib or game lib
        /// \param[in] filename path of the lib for open
        ///
        ////////////////////////////////////////////////////////////
        void open_lib(TYPE ACTION, std::string filename);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 2.0
        ///
        /// \fn void *get_class_lib(TYPE ACTION)
        ///
        /// \brief Get class of the Library (Graphic or Game)
        ///
        /// \param[in] ACTION Game or Graphic select if you want get class of a graphic lib or game lib
        ///
        /// \return class of lib (graphic or game) pointer of function
        ///
        ////////////////////////////////////////////////////////////
        void *get_class_lib(TYPE ACTION);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 24/03/21
        ///
        /// \version 1.0
        ///
        /// \fn void close_lib(TYPE ACTION, std::string filename)
        ///
        /// \brief Close Library (Graphic or Game)
        ///
        /// \param[in] ACTION Game or Graphic select if you want close class of a graphic lib or game lib
        /// \param[in] filename path of library for close
        ///
        ////////////////////////////////////////////////////////////
        void close_lib(TYPE ACTION, std::string filename);
};

#endif /* !CLASS_FILE_LIB_HPP_ */