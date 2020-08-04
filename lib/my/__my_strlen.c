/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets the length of a NULL-terminated string.
*/

#include "my.h"

ssize_t __my_strlen(const char *str, const ssize_t c, const size_t _m)
{
    ssize_t size = -1;

    if (str) {
        while (str[++size]) {
            if ((_m & UNTIL_INDEX) && size >= c)
                break;
            if ((_m & UNTIL_CHAR) && str[size] == c)
                break;
        }
    }
    return (size);
}