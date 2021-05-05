/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** verif_lib
*/

#include "Core_Class_filehandle.hpp"
#include "Core_Class_error.hpp"
#include <fstream>

void LibHandle::verif_if_file_exist(std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        file.close();
        throw Core_Class_error(filename, "Error : Can't Open lib");
    }
    file.close();
}

void LibHandle::verif_if_file_is_not_empty(std::string filename)
{
    struct stat info;
    stat(filename.c_str(), &info);

    if (info.st_size == 0)
        throw Core_Class_error(filename, "Error : File empty");
}

void LibHandle::verif_if_acces_to_read(std::string filename)
{
    if (access(filename.c_str(), R_OK) == -1)
        throw Core_Class_error(filename, "Error : Can't read file");
}

void LibHandle::verif_if_elf_file(std::string filename)
{
    char *buff = new char [5];
    FILE *fp = fopen(filename.c_str(), "r");
    if (fread(buff, 5, 1, fp) <= 0) {
        delete[] buff;
        fclose(fp);
        throw Core_Class_error(filename, "Error : Can't read file");
    }
    if (buff[1] != 'E' || buff[2] != 'L' || buff[3] != 'F'){
        delete[] buff;
        fclose(fp);
        throw Core_Class_error(filename, "Error : is not a shared library");
    }
    delete[] buff;
    fclose(fp);
}

void LibHandle::verif_file(std::string filename)
{
    this->verif_if_file_exist(filename);
    this->verif_if_file_is_not_empty(filename);
    this->verif_if_acces_to_read(filename);
    this->verif_if_elf_file(filename);
}