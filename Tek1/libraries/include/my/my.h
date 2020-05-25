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

///////////////////////////////////////////////////////////////

///////////////////////
// Wildcards related //
///////////////////////

/////////////////////////////
#include "my_special_chars.h"
/////////////////////////////

//Checks whether two NULL-terminated strings match.
//
//-> first can contain wildcards to match with second.
//-> wildcards in second don't matter.
//
//Possible wildcards:
//WC_ANY_STR (by default '*') -> defined in 'my_special_chars.h'.
//WC_ANY_CHAR (by default '?') -> defined in 'my_special_chars.h'. 
bool my_match_shell(const char *first, const char *second);

///////////////////////////////////////////////////////////////

/////////////////////////
// Object size related //
/////////////////////////

//Gets the size of a given NULL-terminated string.
//
//-> Returns -1 if the given string is NULL.
//-> Returns 0 if the given string only contains a '\0'.
ssize_t my_strlen(const char *str);

///////////////////////////////////////////////////////////////

#endif /* MY_H_ */
