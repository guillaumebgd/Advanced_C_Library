/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Main file to test the library in depth.
*/

#include "my.h"

int main(const int ac, const char **av)
{
    const char nb[] = "10";
    char *result = my_convert_base(nb, DECIMAL_BASE, BINARY_BASE);

    if (result)
        free(result);
    return (0);
}
