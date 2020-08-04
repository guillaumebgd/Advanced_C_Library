/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Fills a string with x characters starting from the beginning.
*/

#include <unistd.h>

void *my_memset(void *buffer, const int c, const size_t nb)
{
    register size_t i = 0;
    char *tmp = buffer;

    for (; i < nb; i += 1)
        tmp[i] = c;
    return (buffer);
}