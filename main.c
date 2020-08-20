/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Main file to test the library in depth.
*/

#include "my.h"

int main(const int ac, const char **av)
{
    char *result = my_int_to_str(-100);

    if (result) {
        printf("res = %s\n", result);
        free(result);
    }
    return (0);
}
