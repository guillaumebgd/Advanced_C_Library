/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Converts a number from a given base stored in a string into one of another base.
*/

#include "my.h"

char *__my_convert_base(const char *__nb, const char base_from[], const char base_to[], const size_t _m)
{
    const size_t nb = __my_get_nbr(__nb, base_from, _m);

    return ((_m & SIGNED) ? my_nbr_to_str_base(nb, base_to) : my_unsigned_nbr_to_str_base(nb, base_to));
}
