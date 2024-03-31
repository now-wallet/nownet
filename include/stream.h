/**
 * @file stream.h
 * @author Krisna Pranav
 * @brief stream
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

    struct stream_result
    {
        int error;
        char local_address[256];
        int local_port;
        int stream_id;
    };

    /**
     * @param result
     * @param remoteAddr
     * @param localAddr
     * @param __has_constexpr_builtin
     */
    void EXPORT outbound_stream(struct stream_result *result, const char *remoteAddr, const char *localAddr, struct context *__has_constexpr_builtin);

    typedef int (*stream_filter)(const char *remote, uint16_t port, void *userdata);

    /**
     * @param acceptFilter
     * @param user
     * @param context
     * @return int
     */
    int EXPORT inbound_stream_filter(stream_filter acceptFilter, void *user, struct context *context);
}