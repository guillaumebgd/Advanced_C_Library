/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Finds if a given character is numerical.
*/

#include <stdbool.h>

bool my_is_num(const char c)
{
    return ((c >= '0') & (c <= '9'));
}
