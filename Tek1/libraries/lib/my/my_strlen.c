/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** my_strlen.c
*/

#include <unistd.h>

ssize_t my_strlen(const char *str)
{
    ssize_t size = -1;

    if (str) {
        while (str[++size]);
    }
    return (size);
}