/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Allocates a new string and places digits that makes a number into the string.
*/

#include "my.h"

static void __my_nbr_to_str_fill(char **__s, const size_t _nb, const char __base[], const size_t _m)
{
    const ssize_t __len = my_strlen(__base);

    if (((_m & SIGNED) && _nb >= 10) || ((_m & UNSIGNED) && (size_t)_nb >= 10)) {
        __my_nbr_to_str_fill(__s, (_m & SIGNED) ? _nb / __len : ((size_t)_nb) / (size_t)__len, __base, _m);
        __my_nbr_to_str_fill(__s, (_m & SIGNED) ? _nb % __len : ((ssize_t)_nb) % (size_t)__len, __base, _m);
    } else {
        *(*__s)++ = __base[_nb];
    }
}

char *__my_nbr_to_str(ssize_t __s_nb, const char __base[], const size_t _m)
{
    const bool __n = (_m & SIGNED) && __s_nb < 0;
    const ssize_t __len = __my_nbr_size(__s_nb, __base, _m) + __n;
    char *__s = NULL;
    char *save = NULL;

    if (__len == 0)
        return (NULL);
    __s = malloc(sizeof(char) * (__len + 1));
    if (!__s) {
        return (NULL);
    }
    if (__n) {
        *__s++ = '-';
        __s_nb *= -1;
    }
    save = __s - __n;
    __my_nbr_to_str_fill(&__s, __s_nb, __base, _m);
    __s = save;
    __s[__len] = '\0';
    return (__s);
}
