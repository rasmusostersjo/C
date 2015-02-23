/*
 * Notation:
 *  String          - A null-terminated character array.
 *  Character       - Assumed to be one byte.
 */

#ifndef STRING_H
#define STRING_H

// Libraries
#include <stddef.h>     // size_t

/** strCpy
 * Copies the string pointed to by src, including the terminating null-byte, to
 * the buffer pointed to by dest. It is the caller's responsibility to provide a
 * large enough buffer.
 *
 * @param dest      Pointer to the destination buffer.
 * @param src       Pointer to the source string.
 * @return          A pointer to the destination string.
 */
char* strCpy(char* dest, const char* src);

/** strnCpy
 * Copies at most n bytes from the string pointed to by src to the buffer
 * pointed to by dest. If there is no null-byte among the first n characters,
 * the destination string will not be null-terminated.
 *
 * The strnCpy() function ensures that n bytes are written. In the case of n
 * being larger than the length of the string pointed to by src additional
 * null-bytes are written to the end of the buffer. Note that it is the caller's
 * responsibility to provide a large enough buffer.
 *
 * @param dest      Pointer to the destination buffer.
 * @param src       Pointer to the source string.
 * @return          A pointer to the destination string.
 */
char* strnCpy(char* dest, const char* src, size_t n);

/** strChr
 * Searches for the first occurrence of the character ch in the string pointed
 * to by str. The terminating null-byte is considered to be part of the string.
 * Thus, a null-byte is a valid character to search for.
 *
 * @param str       Pointer to the string to parse.
 * @param ch        The character to search for.
 * @return          A pointer to the first occurrence of ch in the string
 *                  pointed to by str; NULL if no match could be found.
 */
char* strChr(const char* str, int ch);

/** strCmp
 * Compares the strings pointed to by s and t one character at a time. The
 * strCmp() function returns at the first non-matching character or if either of
 * the parsed strings end.
 *
 * @param s         Pointer to a string.
 * @param t         Pointer to a string.
 * @return          Larger than zero:  s > t;
 *                  Less than zero:    s < t;
 *                  Else:              0
 */
int strCmp(const char* s, const char* t);

/** stpCpy
 * Copies the string pointed to by src, including the terminating null-byte, to
 * the buffer pointed to by dest. It is the caller's responsibility to provide a
 * large enough buffer.
 *
 * @param dest      Pointer to the destination buffer.
 * @param src       Pointer to the source string.
 * @return          A pointer to the end of destination string (the null-byte).
 */
char* stpCpy(char* dest, const char* src);

/** strCat
 * Appends the string pointed to by src, including the terminating null-byte, to
 * the string pointed to by dest. The terminating null-byte in the original
 * string pointed to by dest is overwritten. It is the caller's responsibility
 * to provide a large enough destination string.
 *
 * @param dest      Pointer to the destination string.
 * @param src       Pointer to a string to append.
 * @return          A pointer to destination string.
 */
char* strCat(char* dest, const char* src);

/** strCat
 * Appends the string pointed to by src, including the terminating null-byte, to
 * the string pointed to by dest. At most n characters are appended. If there is
 * no terminating null-byte within the first n characters the destination
 * string will not be null-terminated. It is the caller's responsibility to
 * provide a large enough destination string.
 *
 * @param dest      Pointer to the destination string.
 * @param src       Pointer to a string to append.
 * @param n         Maximum amount of characters to append.
 * @return          A pointer to the destination string.
 */
char* strnCat(char* dest, const char* src, size_t n);

/** strLen
 * Computes the length of the string pointed to by str, excluding the
 * terminating null-byte.
 *
 * @param str       Pointer to a string.
 * @return          Length of the string, excluding the terminating null-byte.
 */
size_t strLen(const char* str);

/** strDup
 * Copies the string pointed to by str to a new string allocated on the heap
 * using malloc. It is the caller's responsibility to free the the allocation
 * using free().
 *
 * @param str       Pointer to a string to dublicate.
 * @return          Pointer to the duplicated string; NULL if malloc failed.
 */
char* strDup(const char* str);

/** strSpn
 * Computes the length of the initial segment pointed to by s that consists
 * entirely of characters in the segment pointed to by t. The terminating
 * null-byte is not included in the computation.
 *
 * @param s     Pointer to the string to parse.
 * @param t     Pointer to a string with delimiting characters.
 * @return      Length of the initial segment pointed to by s that consists
 *              entirely of characters in the segment pointed to by t.
 */
size_t strSpn(const char* s, const char* t);

/** strnCmp
 * Compares the strings pointed to by s and t one character at a time. At most
 * n characters are compared. The strnCmp() function returns at the first
 * non-matching character or if either of the parsed strings end.
 *
 * @param s         Pointer to a string.
 * @param t         Pointer to a string.
 * @param n         Maximum amount of characters to compare.
 * @return          Larger than zero:  s > t;
 *                  Less than zero:    s < t;
 *                  Else:              0
 */
int strnCmp(const char* s, const char* t, size_t n);

/** strrChr
 * Searches for the last occurrence of the character ch in the string pointed to
 * by str. The terminating null-byte is considered to be part of the string.
 * Thus, a null-byte is a valid character to search for.
 *
 * @param str       Pointer to the string to parse.
 * @param ch        The character to search for.
 * @return          A pointer to the last occurrence of ch in the string pointed
 *                  to by str; NULL if no match could be found.
 */
char* strrChr(const char* str, int ch);

/** strcSpn
 * Calculates the length of the initial segment pointed to by s that has no
 * characters in the segment pointed to by t. The terminating null-byte is not
 * included in the computation.
 *
 * @param s     Pointer to the string to parse.
 * @param t     Pointer to a string with delimiting characters.
 * @return      Length of the initial segment pointed to by s that has no
 *              characters in the segment pointed to by t.
 */
size_t strcSpn(const char* s, const char* t);

/** strpBrk
 * Searches for the first character in the string pointed to by s that matches
 * any character in the string pointed to by t. The terminating null-byte is not
 * included in the search.
 *
 * @param s         Pointer to a string to parse.
 * @param t         Pointer to a string with delimiting characters.
 * @return          Pointer to the first matching character; NULL if no match
 *                  could be found.
 */
char* strpBrk(const char* s, const char* t);

/** strStr
 * Search for the first occurrence of the string pointed to by t in the string
 * pointed to by s. The terminating null-bytes are not included in the search.
 * Thus, searching for the empty string yields NULL.
 *
 * @param s         Pointer to the string to parse.
 * @param s         Pointer to the string to search for.
 * @return          Pointer to the first occurrence of the string pointed to by
 *                  t in the string pointed to by s; NULL if no match could be
 *                  found.
 */
char* strStr(const char* s, const char* t);

/** strTok
 * Breaks the string pointed to by str into a sequence of zero or more
 * non-empty  tokens. On the first call to strTok() the string to be parsed
 * should be pointed to by str. In each subsequent call that parses the same
 * string, str must be set to NULL.
 *
 * The strTok() function replaces the first occurrence of any delimiting
 * character in the string initially pointed to by str with a null-byte. Leading
 * delimiting characters are ignored on each call to strTok().
 *
 * @param str       Pointer to the string to parse (first call); NULL (else).
 * @param delim     Pointer to a string with delimiting characters.
 * @return          Pointer to the next token (null-terminated); NULL if there
 *                  are no more tokens.
 */
char* strTok(char* str, const char* delim);

/** strSep
 * Breaks the string pointed to by *str_ptr into sequences of one or more
 * tokens that consists of at least a terminating null-byte.
 *
 * The strSep() function replaces any delimiting characters in the string
 * pointed to by *str_ptr with a null-byte. Thus, empty tokens are returned
 * if there are two or more adjacent delimiting characters.
 *
 * @param str_ptr   Pointer to a string-pointer. Here *str_ptr points to the
 *                  string to break down into tokens. The string-pointer is,
 *                  after each call to strSep(), updated to point to the
 *                  character after the latest token; NULL if there are no more
 *                  tokens.
 * @param delim     Pointer to a string with delimiting characters.
 * @return          Pointer to the next token; NULL if *str_ptr was NULL. 
 */
char* strSep(char** str_ptr, const char* delim);

/** strTok_r
 * Breaks the string pointed to by str into a sequence of zero or more
 * non-empty tokens. On the first call to strTok_r() the string to be parsed
 * should be pointed to by str. In each subsequent call that parses the same
 * string, str must be set to NULL and save_ptr must be unchanged since the
 * last call.
 *
 * The strTok_r() function replaces the first occurrence of any delimiting
 * character in the string initially pointed to by str with a null-byte. Leading
 * delimiting characters are ignored on each call to strTok_r().
 *
 * @param str       Pointer to the string to parse (first call); NULL (else).
 * @param delim     Pointer to a string with delimiting characters.
 * @param save_ptr  Pointer to a string-pointer that is used internally.
 * @return          Pointer to the next token (null-terminated); NULL if there
 *                  are no more tokens.
 */
char* strTok_r(char* str, const char* delim, char** save_ptr);

/** strFry
 * Randomizes the content of the string pointed to by str. Internally, this is
 * achieved by using rand(). It is the responsibility of the function to seed
 * rand() upon the first call to strFry().
 *
 * Note that the real strfry() function is implemented using random_r() and
 * initstate_r(). Thus, this implementation may behave differently.
 *
 * @param str       Pointer to a string.
 * @return          Pointer to the string with its content randomized.
 */
char* strFry(char* str);

/** memCpy
 * Copies n bytes from the buffer pointed to by src to the buffer pointed to by
 * dest. It is the caller's responsibility to provide buffers that are large
 * enough.
 *
 * @param dest      Pointer to the destination buffer.
 * @param src       Pointer to the source buffer.
 * @return          Pointer to the start of the destination buffer.
 */
void* memCpy(void* dest, const void* src, size_t n);

/** memSet
 * Fills the first n bytes in the buffer pointed to by dest with the byte c.
 * It is the caller's responsibility to provide a large enough buffer.
 *
 * @param dest      Pointer to the destination buffer.
 * @param c         Byte to fill the buffer with.
 * @return          Pointer to the start of the destination buffer.
 */
void* memSet(void *dest, int c, size_t n);

#endif // STRING_H
