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

#endif