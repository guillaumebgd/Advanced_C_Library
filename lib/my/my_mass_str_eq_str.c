/*
** Personnal C Library
** libraries
** File description:
** my_mass_str_eq_str.c
*/

#include "my.h"

bool my_mass_str_eq_str(size_t nb_args, const char *mask, ...)
{
    va_list ap;
    bool match = false;
    char *arg = NULL;

    va_start(ap, mask);
    for (arg = va_arg(ap, char *); nb_args > 0; arg = va_arg(ap, char *)) {
        if (my_str_eq_str(mask, arg)) {
            match = true;
            break;
        }
        nb_args -= 1;
    }
    va_end(ap);
    return (match);
}