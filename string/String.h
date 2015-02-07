#ifndef STRING_H
#define STRING_H

/** strcpy
 * Copies a nullterminated string pointer to by src to the buffer pointed to by
 * dest. It's the responsibility of the caller to provide a buffer that's large
 * enough.
 *
 * @param dest      Pointer to a buffer.
 * @param src       Pointer to a string.
 * @return          A pointer to the the destination string.
 */
char *strcpy(char *dest, const char *src);


#endif // STRING_H
