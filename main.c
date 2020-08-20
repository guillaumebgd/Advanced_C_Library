/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Main file to test the library in depth.
*/

#include "my.h"

int main(const int ac, const char **av)
{
    int nb = my_get_nbr("123");

    printf("%d\n", nb);
    return (0);
}
