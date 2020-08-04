/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Checks if atleast a character of a list is in a NULL-terminated string.
*/

#include "my.h"

ssize_t __my_str_contains(const char *str, const char list[], const size_t _m)
{
    register ssize_t i_str = 0;
    register ssize_t i_list = 0;

    if (!str || !list)
        return ((_m & GET_CHAR_INDEX) ? -1 : false);
    for (; list[i_list]; i_list += 1) {
        for (; str[i_str]; i_str += 1) {
            if (str[i_str] == list[i_list])
                return ((_m & GET_CHAR_INDEX) ? i_str : true);
        }
        i_str = 0;
    }
    return ((_m & GET_CHAR_INDEX) ? -1 : false);
}
