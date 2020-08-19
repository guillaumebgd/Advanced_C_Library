/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets the number of ranks of units of an integer.
*/

#include "my.h"

size_t __my_nbr_size(ssize_t __s_nb, const size_t _m)
{
    size_t __u_nb = (size_t)__s_nb;
    size_t i = 0;

    do {
        if (_m & SIGNED) {
            __s_nb /= 10;
        } else {
            __u_nb /= 10;
        }
        i += 1;
    } while (((_m & SIGNED) && __s_nb != 0) || ((_m & UNSIGNED) && __u_nb != 0));
    return (i);
}
