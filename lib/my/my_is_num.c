/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Finds if a given character is numerical.
*/

#include <stdbool.h>

bool my_is_num(const char c)
{
    return ((c >= '0') & (c <= '9'));
}
