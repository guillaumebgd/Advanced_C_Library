/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Finds if first matches with any va_arg.
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>

bool __my_mass_eq(size_t nb_args, const size_t first, ...)
{
    va_list ap;
    bool match = false;

    va_start(ap, first);
    for (; nb_args > 0; nb_args -= 1) {
        if (first == va_arg(ap, size_t)) {
            match = true;
            break;
        }
    }
    va_end(ap);
    return (match);
}