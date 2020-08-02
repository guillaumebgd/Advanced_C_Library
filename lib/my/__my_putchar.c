/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Puts a character on a given file descriptor.
*/

#include <stdbool.h>
#include <unistd.h>

bool __my_putchar(const char c, const int fd)
{
    return ((write(fd, &c, 1)) > 0);
}