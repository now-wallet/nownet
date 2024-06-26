/**
 * @file srv.h
 * @author Krisna Pranav
 * @brief srv
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

    struct srv_record
    {
        uint16_t priority;
        uint16_t weight;
        char target[256];
        int port;
    };

    struct srv_lookup_private;

    struct srv_lookup_result
    {
        int error;
        struct srv_lookup_private *internal;
    };

    /**
     * @param host
     * @param service
     * @param result
     * @param ctx
     * @return int
     */
    int EXPORT srv_lookup(char *host, char *service, struct srv_lookup_result *result, struct context *ctx);

    typedef void (*srv_record_iterator)(struct srv_record *, void *);

    /**
     * @param result
     * @param iter
     * @param user
     */
    void EXPORT for_each_srv_record(struct srv_lookup_result *result, srv_record_iterator iter, void *user);

    /**
     * @param result
     */
    void EXPORT srv_lookup_done(struct srv_lookup_result *result);

#ifdef __cplusplus
}
#endif