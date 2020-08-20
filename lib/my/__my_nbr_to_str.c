/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Allocates a new string and places digits that makes a number into the string.
*/

#include "my.h"

static void __my_nbr_to_str_fill(char *__s, size_t *index, const size_t _nb, const size_t _m)
{
    if (((_m & SIGNED) && _nb >= 10) || ((_m & UNSIGNED) && (size_t)_nb >= 10)) {
        __my_nbr_to_str_fill(__s, index, (_m & SIGNED) ? _nb / 10 : ((size_t)_nb) / 10, _m);
        __my_nbr_to_str_fill(__s, index, (_m & SIGNED) ? _nb % 10 : ((ssize_t)_nb) % 10, _m);
    } else {
        __s[*index] = _nb + '0';
        *index += 1;
    }
}

char *__my_nbr_to_str(ssize_t __s_nb, const size_t _m)
{
    const bool __n = (_m & SIGNED) && __s_nb < 0;
    const ssize_t __len = __my_nbr_size(__s_nb, _m) + __n;
    size_t index = 0;
    char *__s = NULL;

    __s = malloc(sizeof(char) * (__len + 1));
    if (!__s) {
        return (NULL);
    }
    if (__n) {
        __s[index++] = '-';
        __s_nb *= -1;
    }
    __my_nbr_to_str_fill(__s, &index, __s_nb, _m);
    __s[index] = '\0';
    return (__s);
}