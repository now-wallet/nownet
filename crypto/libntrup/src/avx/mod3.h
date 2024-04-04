/**
 * @file mod3.h
 * @author Krisna Pranav
 * @brief mod3
 * @version 1.0
 * @date 2024-04-04
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#ifndef mod3_h
#define mod3_h

#include "small.h"
#include <sodium/crypto_int32.h>

/**
 * @param x
 * @return int
 */
static inline int mod3_nonzero_mask(small x)
{
    return -x * x;
}

/**
 * @param a
 * @return small
 */
static inline small mod3_freeze(crypto_int32 a)
{
    a -= 3 * ((10923 * a) >> 15);
    a -= 3 * ((89478485 * a + 134217728) >> 28);
    return a;
}

/**
 * @param a
 * @param b
 * @param c
 * @return small
 */
static inline small mod3_minusproduct(small a, small b, small c)
{
    crypto_int32 A = a;
    crypto_int32 B = b;
    crypto_int32 C = c;
    return mod3_freeze(A - B * C);
}

/**
 * @param a
 * @param b
 * @param c
 * @return small
 */
static inline small mod3_plusproduct(small a, small b, small c)
{
    crypto_int32 A = a;
    crypto_int32 B = b;
    crypto_int32 C = c;
    return mod3_freeze(A + B * C);
}

/**
 * @param a
 * @param b
 * @return small
 */
static inline small mod3_product(small a, small b)
{
    return a * b;
}

/**
 * @param a
 * @param b
 * @return small
 */
static inline small mod3_sum(small a, small b)
{
    crypto_int32 A = a;
    crypto_int32 B = b;
    return mod3_freeze(A + B);
}

/**
 * @param a1
 * @return small
 */
static inline small mod3_reciprocal(small a1)
{
    return a1;
}

/**
 * @param num
 * @param den
 * @return small
 */
static inline small mod3_quotient(small num, small den)
{
    return mod3_product(num, mod3_reciprocal(den));
}

#endif