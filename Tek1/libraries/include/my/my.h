/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
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

#define NONE (0)

///////////////////////////////////////////////////////////////

//////////////////
// Binary Scale //
//////////////////

bool __my_mass_eq(size_t nb_args, const size_t first, ...);

//Returns if first matches with any args from va_args.
//
//nb -> nb of va_args.
#define my_mass_eq(nb_args, first, ...) \
                    (__my_mass_eq(nb_args, (size_t)first, __VA_ARGS__))

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

///////////////////////////////////////////////////////////////

///////////////////////////
// Objects sizes related //
///////////////////////////

//Gets the size of a given NULL-terminated string.
//
//-> Returns -1 if the given string is NULL.
//-> Returns 0 if the given string only contains a '\0'.
ssize_t my_strlen(const char *str);

///////////////////////////////////////////////////////////////

#endif /* MY_H_ */
