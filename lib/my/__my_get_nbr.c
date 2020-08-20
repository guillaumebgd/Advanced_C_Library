/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets a number from a string.
*/

#include "my.h"

static int __my_get_nbr_get_sign(char **tmp, const size_t _m)
{
    int sign_multiplier = 1;

    for (; **tmp && (**tmp == '-' || **tmp == '+'); *tmp += 1) {
        if (**tmp == '-') {
            sign_multiplier *= -1;
            if (_m & ONE_NEG_SIGN) {
                *tmp += 1;
                break;
            }
        } else if (_m & ONE_NEG_SIGN) {
            break;
        }
    }
    return (sign_multiplier);
}

size_t __my_get_nbr(const char *__str, const char base[], const size_t _m)
{
    const ssize_t len_base = my_strlen(base);
    ssize_t index = 0;
    char *tmp = (char *)__str;
    size_t nb = 0;
    int sign_multiplier = 1;

    if (!__str || len_base <= 1)
        return (0);
    if (_m & SIGNED)
        sign_multiplier = __my_get_nbr_get_sign(&tmp, _m);
    for (; *tmp; tmp += 1)  {
        index = my_str_contains_index(base, *tmp);
        if (index < 0)
            break;
        nb = nb * len_base + index;
    }
    return (nb * sign_multiplier);
}
