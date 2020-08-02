/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Puts a decimal number on a file descriptor.
*/

#include "my.h"

static ssize_t __my_put_double_c(const size_t nb, const size_t _m, const int fd)
{
    return (0);
}

static bool __my_put_double_no_c(const double nb, const size_t _m, const int fd)
{
    //if (nb >= 10) {
    //    __my_put_double_no_c(nb / 10.0, _m, fd);
    //    __my_put_double_no_c(nb % 10.0, _m, fd);
    //} else {
    //    //my_dputchar(nb + '0', fd);
    //}
    //return (true);
    long int _integer = (long int)nb;
    double _decimal = nb - (double)_integer;

    printf("%ld | %E\n", _integer, _decimal);
    return (true);
}

ssize_t __my_put_double(const double nb, const size_t _m, const int fd)
{
    //printf("%E\n", nb);
    if (_m & COUNT_PRINTED_CHAR)
        return (__my_put_double_c(nb, _m, fd));
    return (__my_put_double_no_c(nb, _m, fd));
}

// 19.12