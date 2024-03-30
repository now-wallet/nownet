/**
 * @file context.h
 * @author Krisna Pranav
 * @brief context
 * @version 1.0
 * @date 2024-03-30
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#pragma once

#include "export.h"
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"
{
#endif

    struct now_context;

    /**
     * @return struct now_context*
     */
    struct now_context *EXPORT now_context_new();

    void EXPORT now_context_free(struct now_context *);

    /**
     * @return int
     */
    int EXPORT now_context_start(struct now_context *);

    /**
     * @return int
     */
    int EXPORT now_status(struct now_context *);

    /**
     * @param N
     * @return int
     */
    int EXPORT now_wait_for_ready(int N, struct now_context *);

#ifdef __cplusplus
}
#endif