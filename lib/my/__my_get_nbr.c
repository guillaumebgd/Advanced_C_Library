/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets a number from a string.
*/

#include "my.h"

static int __my_get_nbr_get_sign(char **tmp)
{
    int sign_multiplier = 1;

    for (; **tmp; *tmp += 1) {
        if (**tmp == '-') {
            sign_multiplier *= -1;
        } else if (**tmp == '+') {
            continue;
        } else {
            break;
        }
    }
    return (sign_multiplier);
}

size_t __my_get_nbr(const char *__str, const size_t _m)
{
    char *tmp = (char *)__str;
    size_t nb = 0;
    int sign_multiplier = 1;

    if (!__str)
        return (0);
    if (_m & SIGNED)
        sign_multiplier = __my_get_nbr_get_sign(&tmp);
    for (; *tmp; tmp += 1)  {
        if (!my_is_num(*tmp)) {
            break;
        }
        if (nb == 0 && *tmp == '0') {
            continue;
        }
        nb = nb * 10 + *tmp - '0';
    }
    return (nb * sign_multiplier);
}
