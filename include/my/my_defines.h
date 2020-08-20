/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Special characters used in my library.
*/

#ifndef MY_SPECIAL_CHARS_H_
#define MY_SPECIAL_CHARS_H_

///////////////////////////////////////////////////////////////

///////////////////////

#define NONE (0)

///////////////////////

///////////
// Bases //
///////////

///////////////////////

#define BINARY_BASE ("01")
#define OCTAL_BASE ("01234567")
#define DECIMAL_BASE ("0123456789")
#define HEXADECIMAL_LOWERCASE_BASE ("0123456789abcdef")
#define HEXADECIMAL_UPPERCASE_BASE ("0123456789ABCDEF")

///////////////////////

///////////////////////

//////////////////
// Contraptions //
//////////////////

// Gets the absolute value of a variable.
#define ABS(x) ((x < 0) ? (-x) : (x))

///////////////////////

//////////////
// Matching //
//////////////

// Wildcards //

///////////////////////

// * Characters

#define WC_ANY_STR ('*')
#define WC_ANY_CHAR ('?')

///////////////////////

///////////////////////

// * Flags

#define WC_STR (1)
#define WC_CHAR (1 << 1)
#define WC_STR_CHAR (WC_STR | WC_CHAR)

///////////////////////

/////////////
// Indexes //
/////////////

// Until what a counter index should stop counting. //

///////////////////////

#define UNTIL_INDEX (1)
#define UNTIL_CHAR (1 << 1)

///////////////////////

///////////////////////

// Flags for return values.

#define DONT_GET_CHAR_INDEX (1)
#define GET_CHAR_INDEX (1 << 1)

///////////////////////

///////////
// Signs //
///////////

///////////////////////

// Flags.

#define UNSIGNED (1 << 2)
#define SIGNED (1 << 3)

///////////////////////

//////////////
// Printers //
//////////////

///////////////////////

// Flags for character counting.

#define NO_COUNT_PRINTED_CHAR (1)
#define COUNT_PRINTED_CHAR (1 << 1)

///////////////////////

//////////////////////////
// String manipulations //
//////////////////////////

///////////////////////

// Flags for my_strcat().

#define FREE_FIRST (1)
#define FREE_SECOND (2)
#define FREE_BOTH (FREE_FIRST | FREE_SECOND)

///////////////////////

///////////////////////

// Flags for getters of numbers in strings.

///////////////////////

#define ONE_NEG_SIGN (1 << 4)

///////////////////////

/////////////////////
// File management //
/////////////////////

///////////////////////

// Flags.

#define GET_FILE_NAME (1)
#define GET_FILE_PATH (1 << 1)

///////////////////////

///////////////////////////////////////////////////////////////

#endif /* MY_SPECIAL_CHARS_H_ */
