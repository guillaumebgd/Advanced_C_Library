/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Main file to test library more in depth.
*/

#include "my.h"

int main(const int ac, const char **av)
{
    int fd = -1;
    char *result = NULL;

    if (ac < 2)
        return (1);
    fd = open(av[1], O_RDONLY);
    if (fd <= -1)
        return (1);
    do {
        if (result)
            free(result);
        result = get_next_line(fd);
        if (result)
            printf("%s\n", result);
    } while (result);
    return (0);
}