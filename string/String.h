#ifndef STRING_H
#define STRING_H

// Libraries
#include <stddef.h>     // size_t

/** strCpy
 * Copies a null-terminated string pointed to by src to the buffer pointed to by
 * dest. It's the responsibility of the caller to provide a buffer that's large
 * enough.
 *
 * @param dest      Pointer to a buffer.
 * @param src       Pointer to a string.
 * @return          A pointer to the the destination string.
 */
char* strCpy(char *dest, const char* src);

/** strnCpy
 * Copies a null-terminated string pointed to by src to the buffer pointed to by
 * dest. At most n characters are copied, and if there's no terminating null
 * byte among that interval dest will not be null-terminated. If the string
 * pointed to by src contains less characters than n strnCpy writes additional m
 * null bytes to ensure n characters were written. Note that it's the
 * responsibility of the caller to procive a buffer that's large enough.
 *
 * @param dest      Pointer to a buffer.
 * @param src       Pointer to a string.
 * @param n         Amount of characters to copy.
 * @return          A pointer to the the destination string.
 */
char* strnCpy(char *dest, const char* src, size_t n);

/** strChr
 * Searches for the first occurance of c in the null-terminated string pointed
 * to by str. Here, the terminating null-byte is considered to be part of the
 * string and is a valid character to search for.
 *
 * @param str       Pointer to a string.
 * @param c         Value of the character to search for.
 * @return          A pointer to the first occurance of c in str; NULL if no
 *                  match.
 */
char* strChr(const char *str, int c);

#endif // STRING_H
