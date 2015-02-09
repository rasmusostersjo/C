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
char* strCpy(char* dest, const char* src);

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
char* strnCpy(char* dest, const char* src, size_t n);

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
char* strChr(const char* str, int c);

/** strCmp
 * Compares two null-terminated strings s and t one character at a time.
 * Function returns at the first nonmatching character or if s and t are
 * identical.
 *
 * Note that each character is compared by its numerical value, i.e.
 * "ab" > "Ab" if ASCII-encoding is used.
 *
 * @param s         Pointer to the first string.
 * @param t         Pointer to the second string.
 * @return          Larger than zero if s > t; Less than zero if s < t;
 *                  Else zero.
 */
int strCmp(const char* s, const char* t);

/** stpCpy
 * Copies a null-terminated string pointed to by src to the buffer pointed to by
 * dest. It's the responsibility of the caller to provide a buffer that's large
 * enough.
 *
 * @param dest      Pointer to a buffer.
 * @param src       Pointer to a string.
 * @return          A pointer to the the end of the destination string (i.e.
 *                  the null-byte).
 */
char* stpCpy(char* dest, const char* src);

/** strCat
 * Appends the null-terminated string pointed to by dest with the
 * null-terminated string pointed to by str. The terminating null-byte at the
 * end of dest is overwritten and then added as soon as the merge is completed.
 * It's the responsibility of the caller to provide a large enough string to
 * safely append src to dest.
 *
 * @param dest      Pointer to a string.
 * @param src       Pointer to a string.
 * @return          A pointer to dest.
 */
char* strCat(char* dest, const char* src);

/** strnCat
 * Appends the null-terminated string pointed to by dest with the
 * null-terminated string pointed to by str. The terminating null-byte at the
 * end of dest is overwritten and at most n characters are copied. If there's no
 * null-byte within the first n characters dest will not be null-terminated.
 * It's the responsibility of the caller to provide a large enough string to
 * safely append src to dest.
 *
 * @param dest      Pointer to a string.
 * @param src       Pointer to a string.
 * @param n         Max amount of characters to append.
 * @return          A pointer to dest.
 */
char* strnCat(char* dest, const char* src, size_t n);

/** strLen
 * Calculates the length of the null-terminated string str, excluding the
 * terminating null-byte.
 *
 * @param str       Pointer to a string.
 * @return          Size of the string.
 */
size_t strLen(const char* str);

/** strDup
 * Copies the null-terminated string str to a new string which is allocated
 * on the heap using malloc. It's the resposibility of the caller to free the
 * the allocation, see free(3).
 *
 * @param str       Pointer to a string.
 * @return          Pointer to the duplicated string, NULL if malloc failed.
 */
char* strDup(const char* str);

#endif // STRING_H
