/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Finds if a given character is alphabetical.
*/

#include <stdbool.h>

bool my_is_alpha(const char c)
{
    return (((c >= 'a') & (c <= 'z')) | ((c >= 'A') & (c <= 'Z')));
}
