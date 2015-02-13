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

/** strSpn
 * Calulates the length (in bytes) of the initial segment pointed to by s that
 * consists entirely of bytes in the segment pointed to by t. The terminating
 * null-byte is not included in the computation. In other words; the index of
 * the last byte in s that's also in t is computed.
 *
 * @param s     Pointer to a null-terminated string.
 * @param t     Pointer to a null-terminated string.
 * @return      Index of the first byte in s that's not in t.
 */
size_t strSpn(const char* s, const char* t);

/** strnCmp
 * Compares two null-terminated strings s and t one character at a time. At most
 * n characters are compared. Function returns at the first nonmatching
 * character or if s and t are identical.
 *
 * @param s         Pointer to the first string.
 * @param t         Pointer to the second string.
 * @param n         Maximum amount of characters to compare.
 * @return          Larger than zero if s > t; Less than zero if s < t;
 *                  Else zero.
 */
int strnCmp(const char* s, const char* t, size_t n);

/** strrChr
 * Searches for the last occurance of c in the null-terminated string pointed
 * to by str. Here, the terminating null-byte is considered to be part of the
 * string and is a valid character to search for.
 *
 * @param str       Pointer to a string.
 * @param c         Value of the character to search for.
 * @return          A pointer to the last occurance of c in str; NULL if no
 *                  match.
 */
char* strrChr(const char* str, int c);

/** strcSpn
 * Calculates the length (in bytes) of the initial segment pointed to by s which
 * are not in the segment pointed to by t. The terminating null-byte is not
 * included in the computation. In other words; the index of the last byte in s
 * that's not in t is computed.
 *
 * @param s         Pointer to a string (examine).
 * @param t         Pointer to a string (search in).
 * @return          Index of the first byte in s that's also in t.
 */
size_t strcSpn(const char* s, const char* t);

/** strpBrk
 * Searches for the firs character in the null-terminated string s that matches
 * any character in the null-terminated string t. Here, the terminating
 * null-byte is not included in the search.
 *
 * @param s         Pointer to a string.
 * @param t         Pointer to a string.
 * @return          Pointer to the first occurance of the character in s that is
 *                  also in t, NULL if no match.
 */
char* strpBrk(const char* s, const char* t);

/** strStr
 * Fins the first occurance of the null-terminated substring t in the 
 * null-terminated string s. Here, the terminating null-bytes are not compared.
 *
 * @param s         Pointer to a string.
 * @param s         Pointer to a string.
 * @return          A pointer to the begining of the substring, NULL if no match
 *                  could be found.
 */
char* strStr(const char* s, const char* t);

/** strTok
 * Breaks a null-terminated string into a sequence of zero or more nonempty 
 * tokens. On the first function call the string to be parsed should be pointed
 * to by str. In each subsequent call that should parse the same string, str
 * must be set to NULL.
 * 
 * @param str       Pointer to a string (first call); NULL (else).
 * @param delim     Pointer to a null-terminated string with delimiting bytes.
 * @return          Pointer to the next token; NULL if there are no more tokens.
 */
char* strTok(char* str, const char* delim);

#endif // STRING_H
