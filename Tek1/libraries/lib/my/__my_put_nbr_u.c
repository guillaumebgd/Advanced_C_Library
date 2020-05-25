/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Puts an unsigned number on a file descriptor.
*/

#include "my.h"

static ssize_t __my_put_nbr_u_c(const size_t nb, const char base[], const size_t _m, const int fd)
{
    const ssize_t tmp = my_strlen(base);
    size_t len_base = 0;
    ssize_t count = 0;

    if (tmp < 0)
        return (false);
    len_base = (size_t)tmp;
    if (nb >= len_base) {
        count += __my_put_nbr_u_c(nb / len_base, base, _m, fd);
        count += __my_put_nbr_u_c(nb % len_base, base, _m, fd);
    } else
        count += my_dputchar(base[nb], fd);
    return (count);
}

static bool __my_put_nbr_u_no_c(const size_t nb, const char base[], const size_t _m, const int fd)
{
    const ssize_t tmp = my_strlen(base);
    size_t len_base = 0;
    bool is_wrote = true;

    if (tmp < 0)
        return (false);
    len_base = (size_t)tmp;
    if (nb >= len_base) {
        if (!__my_put_nbr_u_no_c(nb / len_base, base, _m, fd)
            || !__my_put_nbr_u_no_c(nb % len_base, base, _m, fd)) {
            is_wrote = false;
        }
    } else {
        if (!my_dputchar(base[nb], fd))
            is_wrote = false;
    }
    return (is_wrote);
}

ssize_t __my_put_nbr_u(const size_t nb, const char base[], const size_t _m, const int fd)
{
    if (_m & COUNT_PRINTED_CHAR)
        return (__my_put_nbr_u_c(nb, base, _m, fd));
    return (__my_put_nbr_u_no_c(nb, base, _m, fd));
}
