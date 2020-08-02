/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Puts a character on a given file descriptor.
*/

#include <stdbool.h>
#include <unistd.h>

bool __my_putchar(const char c, const int fd)
{
    return ((write(fd, &c, 1)) > 0);
}