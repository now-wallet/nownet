/**
 * @file addr.h
 * @author Krisna Pranav
 * @brief address
 * @version 1.0
 * @date 2024-03-31
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#pragma once

#include "context.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @return char*
     */
    char *EXPORT address(struct context *);

#ifdef __cplusplus
}
#endif