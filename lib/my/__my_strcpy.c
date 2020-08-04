/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Copies characters from a string onto another.
*/

#include "my.h"

void __my_strcpy(const char *template, char *dest, const ssize_t c, const size_t _m)
{
    register ssize_t i = 0;

    if (!template)
        return;
    while (template[i]) {
        dest[i] = template[i];
        if ((_m & UNTIL_INDEX) && i >= c)
            break;
        if ((_m & UNTIL_CHAR) && template[i] == c)
            break;
        i += 1;
    }
    dest[i] = '\0';
}