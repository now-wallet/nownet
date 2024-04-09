/**
 * @file small.c
 * @author Krisna Pranav
 * @brief small
 * @version 1.0
 * @date 2024-04-09
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#if __AVX2__
#include <immintrin.h>
#include "params.h"
#include "small.h"

/**
 * @param c
 * @param f
 */
void small_encode(unsigned char *c, const small *f)
{
    small c0;
    int i;

    for (i = 0; i < p / 4; ++i)
    {
        c0 = *f++ + 1;
        c0 += (*f++ + 1) << 2;
        c0 += (*f++ + 1) << 4;
        c0 += (*f++ + 1) << 6;
        *c++ = c0;
    }
    c0 = *f++ + 1;
    *c++ = c0;
}

/**
 * @param f
 * @param c
 */
void small_decode(small *f, const unsigned char *c)
{
    unsigned char c0;
    int i;

    for (i = 0; i < p / 4; ++i)
    {
        c0 = *c++;
        *f++ = ((small)(c0 & 3)) - 1;
        c0 >>= 2;
        *f++ = ((small)(c0 & 3)) - 1;
        c0 >>= 2;
        *f++ = ((small)(c0 & 3)) - 1;
        c0 >>= 2;
        *f++ = ((small)(c0 & 3)) - 1;
    }
    c0 = *c++;
    *f++ = ((small)(c0 & 3)) - 1;
    *f++ = 0;
    *f++ = 0;
    *f++ = 0;
    *f++ = 0;
    *f++ = 0;
    *f++ = 0;
    *f++ = 0;
}

#endif