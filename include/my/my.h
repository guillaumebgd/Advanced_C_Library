/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** My library functions.
*/

#ifndef MY_H_
#define MY_H_

///////////////////////////////////////////////////////////////

////////////////////
#include <stdbool.h>
////////////////////
#include <stddef.h>
////////////////////
#include <unistd.h>
////////////////////
#include <stdarg.h>
////////////////////
#include <stdio.h>
////////////////////
#include <fcntl.h>
////////////////////
#include <stdlib.h>
////////////////////

#define NONE (0)

#define BINARY_BASE ("01")
#define OCTAL_BASE ("01234567")
#define DECIMAL_BASE ("0123456789")
#define HEXADECIMAL_LOWERCASE_BASE ("0123456789abcdef")
#define HEXADECIMAL_UPPERCASE_BASE ("0123456789ABCDEF")

///////////////////////////////////////////////////////////////

/////////////////////////
// Objects Comparisons //
/////////////////////////

bool __my_mass_eq(size_t nb_args, const size_t first, ...);

//Returns if first matches with any args from va_args.
//
//nb -> nb of va_args.
#define my_mass_eq(nb_args, first, ...) \
                    (__my_mass_eq(nb_args, (size_t)first, __VA_ARGS__))

//Returns if a given char is alphabetical.
bool my_is_alpha(const char c);

//Returns if a given char is numerical.
bool my_is_num(const char c);

//Returns if a given char is alphabetical or numerical.
static inline bool my_is_alphanum(const char c)
{
    return (my_is_alpha(c) | my_is_num(c));
}

///////////////////////

#define DONT_GET_CHAR_INDEX (0)
#define GET_CHAR_INDEX (1)

ssize_t __my_str_contains(const char *str, const char list[], const size_t _m);

//Returns whether or not a given character is in a given string.
static inline bool my_str_contains(const char *str, const char c)
{
    char list[2];

    list[0] = c;
    list[1] = '\0';
    return (__my_str_contains(str, list, DONT_GET_CHAR_INDEX));
}

//Returns an index to a given character in a given string.
//
//If not found, returns -1.
static inline size_t my_str_contains_index(const char *str, const char c)
{
    char list[2];

    list[0] = c;
    list[1] = '\0';
    return (__my_str_contains(str, list, GET_CHAR_INDEX));
}

//Returns whether atleast one character in a given list is in a given string.
static inline bool my_str_contains_list(const char *str, const char list[])
{
    return (__my_str_contains(str, list, DONT_GET_CHAR_INDEX));
}

///////////////////////////////////////////////////////////////

/////////////
// Fillers //
/////////////

//Puts 'nb' 'c's in 'buffer' from its beginning.
void *my_memset(void *buffer, const int c, const size_t nb);

///////////////////////////////////////////////////////////////

/////////////////////////////
// String matching related //
/////////////////////////////

/////////////////////////////
#include "my_special_chars.h"
/////////////////////////////

///////////////////////

#define NO_WC (0)
#define WC_STR (1)
#define WC_CHAR (1 << 1)
#define WC_STR_AND_CHAR (WC_STR | WC_CHAR)

bool __match(const char *s1, const char *s2, const size_t _m);

//Checks whether two NULL-terminated strings match.
//
//-> first can contain wildcards to match with second.
//-> wildcards in second don't matter.
//
//Possible wildcards:
//WC_ANY_STR (by default '*') -> defined in 'my_special_chars.h'.
static inline bool my_match(const char *first, const char *second)
{
    return (__match(first, second, WC_STR));
}

//Checks whether two NULL-terminated strings match.
//
//-> first can contain wildcards to match with second.
//-> wildcards in second don't matter.
//
//Possible wildcards:
//WC_ANY_STR (by default '*') -> defined in 'my_special_chars.h'.
//WC_ANY_CHAR (by default '?') -> defined in 'my_special_chars.h'. 
static inline bool my_match_shell(const char *first, const char *second)
{
    return (__match(first, second, WC_STR_AND_CHAR));
}

//Checks whether two NULL-terminated strings match.
static inline bool my_str_eq_str(const char *first, const char *second)
{
    return (__match(first, second, NO_WC));
}

//Returns if mask matches with any args from va_args.
//
//nb -> nb of va_args.
bool my_mass_str_eq_str(size_t nb_args, const char *mask, ...);

///////////////////////

#define UNTIL_INDEX (1)
#define UNTIL_CHAR (1 << 1)

///////////////////////////////////////////////////////////////

///////////////////////////
// Objects sizes related //
///////////////////////////

ssize_t __my_strlen(const char *str, const ssize_t c, const size_t _m);

//Gets the size of a given NULL-terminated string.
//
//-> Returns -1 if the given string is NULL.
//-> Returns 0 if the given string only contains a '\0'.
static inline ssize_t my_strlen(const char *str)
{
    return (__my_strlen(str, 0, NONE));
}

static inline ssize_t my_strnlen(const char *str, const ssize_t limit)
{
    if (limit < 0)
        return (0);
    return (__my_strlen(str, limit, UNTIL_INDEX));
}

static inline ssize_t my_strlen_char(const char *str, const char c)
{
    return (__my_strlen(str, (ssize_t)c, UNTIL_CHAR));
}

///////////////////////////////////////////////////////////////

//////////////
// Printers //
//////////////

bool __my_putchar(const char c, const int fd);

//Prints a given character onto the STDOUT.
static inline bool my_putchar(const char c)
{
    return (__my_putchar(c, STDOUT_FILENO));
}

//Prints a given character onto the the given file descriptor.
static inline bool my_dputchar(const char c, const int fd)
{
    return (__my_putchar(c, fd));
}

#define NO_COUNT_PRINTED_CHAR (0)
#define COUNT_PRINTED_CHAR (1)

//////////////////////////

//////////////////////////
// String manipulations //
//////////////////////////

void __my_strcpy(const char *template, char *dest, const ssize_t c, const size_t _m);

static inline void my_strcpy(const char *template, char *dest)
{
    __my_strcpy(template, dest, 0, NONE);
}

static inline void my_strncpy(const char *template, char *dest, const ssize_t limit)
{
    if (limit < 0)
        return;
    __my_strcpy(template, dest, limit, UNTIL_INDEX);
}

static inline void my_strcpy_char(const char *template, char *dest, const char c)
{
    __my_strcpy(template, dest, (ssize_t)c, UNTIL_CHAR);
}

char *__my_strdup(const char *template, const ssize_t c, const size_t _m);

static inline char *my_strdup(const char *template)
{
    return (__my_strdup(template, 0, NONE));
}

static inline char *my_strndup(const char *template, const ssize_t limit)
{
    if (limit < 0)
        return (NULL);
    return (__my_strdup(template, limit, UNTIL_INDEX));
}

static inline char *my_strdup_char(const char *template, const char c)
{
    return (__my_strdup(template, (ssize_t)c, UNTIL_CHAR));
}


#define FREE_FIRST (1)
#define FREE_SECOND (2)
#define FREE_BOTH (FREE_FIRST | FREE_SECOND)

char *my_strcat(char *first, char *second, const size_t free_opt);

//////////////////////////

////////////////////////
// Put Signed numbers //
////////////////////////

ssize_t __my_put_nbr(const ssize_t nb, const char base[], const size_t _m, const int fd);

//Prints a given signed onto the STDOUT.
static inline bool my_put_nbr(const ssize_t nb)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given binary signed onto the STDOUT.
static inline bool my_put_nbr_binary(const ssize_t nb)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given octal signed onto the STDOUT.
static inline bool my_put_nbr_octal(const ssize_t nb)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal signed onto the STDOUT.
static inline bool my_put_nbr_lower_hex(const ssize_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal signed onto the STDOUT.
static inline bool my_put_nbr_upper_hex(const ssize_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given signed onto the STDOUT according to its given base.
static inline bool my_put_nbr_base(const ssize_t nb, const char base[])
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given signed onto the given file descriptor.
static inline bool my_dput_nbr(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given binary signed onto the given file descriptor.
static inline bool my_dput_nbr_binary(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given octal signed onto the given file descriptor.
static inline bool my_dput_nbr_octal(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given lowercase hexadecimal signed onto the given file descriptor.
static inline bool my_dput_nbr_lower_hex(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given lowercase hexadecimal signed onto the given file descriptor.
static inline bool my_dput_nbr_upper_hex(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given signed onto the given file descriptor according to its given base.
static inline bool my_dput_nbr_base(const ssize_t nb, const char base[], const int fd)
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR, fd));
}

//////////////////////////

//////////////////////////
// Put Unsigned numbers //
//////////////////////////

ssize_t __my_put_nbr_u(const size_t nb, const char base[], const size_t _m, const int fd);

//Prints a given unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr(const size_t nb)
{
    return (__my_put_nbr_u(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given binary unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_binary(const size_t nb)
{
    return (__my_put_nbr_u(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given octal unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_octal(const size_t nb)
{
    return (__my_put_nbr_u(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_lower_hex(const size_t nb)
{
    return (__my_put_nbr_u(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_upper_hex(const size_t nb)
{
    return (__my_put_nbr_u(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given unsigned onto the STDOUT according to its given base.
static inline bool my_put_unsigned_nbr_base(const size_t nb, const char base[])
{
    return (__my_put_nbr_u(nb, base, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}

//Prints a given unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr(const size_t nb, const int fd)
{
    return (__my_put_nbr_u(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given binary unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_binary(const size_t nb, const int fd)
{
    return (__my_put_nbr_u(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given octal unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_octal(const size_t nb, const int fd)
{
    return (__my_put_nbr_u(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given lowercase hexadecimal unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_lower_hex(const size_t nb, const int fd)
{
    return (__my_put_nbr_u(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given lowercase hexadecimal unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_upper_hex(const size_t nb, const int fd)
{
    return (__my_put_nbr_u(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR, fd));
}

//Prints a given unsigned onto the given file descriptor according to its given base.
static inline bool my_dput_unsigned_nbr_base(const size_t nb, const char base[], const int fd)
{
    return (__my_put_nbr_u(nb, base, NO_COUNT_PRINTED_CHAR, fd));
}

//////////////////////////

//ssize_t __my_put_double(const double nb, const size_t _m, const int fd);

//Prints a double onto the STDOUT.
/*static inline bool my_put_double(const double nb)
{
    return (__my_put_double(nb, NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
}*/

///////////////////////////////////////////////////////////////

//////////////////
// File parsing //
//////////////////

//Gets the next line of a file and returns it.
char *get_next_line(const int fd);

///////////////////////////////////////////////////////////////

#endif /* MY_H_ */
