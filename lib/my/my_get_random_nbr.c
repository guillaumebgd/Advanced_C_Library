/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets a random number from a range.
*/

#include <stdlib.h>

ssize_t my_get_random_nbr(const ssize_t min, const ssize_t max)
{
    return ((max - min == 0) ? max : (rand() % (max - min) + min));
}
