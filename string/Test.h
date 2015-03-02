#ifndef TEST_H
#define TEST_H

/** test_strCpy
 * Performed tests:
 *  -- Copy empty string
 *  -- Copy normal string
 *  -- Copy sneaky string
 *  -- Copy random string
 *  -- Return value
 *
 * @return      Success (1); else failure (0).
 */
int test_strCpy(void);

/** test_strCmp
 * Performed tests:
 *  -- Empty strings
 *  -- Normal strings
 *
 * @return      Success (1); else failure (0).
 */
int test_strCmp(void);

/** test_strLen
 * Performed tests:
 *  -- Empty string
 *  -- Normal strings
 *  -- Weird String
 *  -- Random strings
 *
 * @return      Success (1); else failure (0).
 */
int test_strLen(void);

#endif // TEST_H
