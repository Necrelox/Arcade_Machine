/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-clement1.berard
** File description:
** test_core
*/

#include <criterion/criterion.h>
#include "core_prototype.hpp"

Test(test_core, should_success_if_core_get_good_library)
{
    char *str = (char *)"oui";
    cr_assert_eq(core((char *)str), 0, "Erreur : Core function return %d\n", core((char *)str));
}