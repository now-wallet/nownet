/**
 * @file socket.h
 * @author Krisna Pranav
 * @brief socket
 * @version 1.0
 * @date 2024-04-01
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
     * @param poll
     * @param numsockets
     * @param ctx
     * @return int
     */
    int EXPORT poll(struct pollfd *poll, nfds_t numsockets, struct context *ctx);

    /**
     * @param id
     * @param ctx
     */
    void EXPORT close_socket(int id, struct context *ctx);

#ifdef __cplusplus
}
#endif