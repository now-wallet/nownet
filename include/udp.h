/**
 * @file udp.h
 * @author Krisna Pranav
 * @brief udp
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

    struct udp_flowinfo
    {
        char remote_host[256];
        uint16_t remote_port;
        int socket_id;
    };

    struct udp_bind_result
    {
        int socket_id;
    };

    typedef int (*udp_flow_filter)(void *userdata, const struct udp_flowinfo *remote_address, void **flow_userdata, int *timeout_seconds);

    typedef void(udp_create_flow_func)(void *userdata, void **flow_userdata, int *timeout_seconds);

    typedef void (*udp_flow_recv_func)(const struct udp_flow_info *remote_address, const char *pkt_data, size_t pkt_length, void *flow_userdata);

    typedef void (*udp_flow_timeout_func)(const struct udp_flowinfo *remote_address, void *flow_userdata);

    /**
     * @param exposedPort
     * @param filter
     * @param recv
     * @param timeout
     * @param user
     * @param result
     * @param ctx
     * @return int
     */
    int EXPORT udp_bind(uint16_t exposedPort, udp_flow_filter filter, udp_flow_recv_func recv, udp_flow_timeout_func timeout, void *user, struct udp_bind_result *result, struct context *ctx);

    /**
     * @param create_flow
     * @param user
     * @param remote
     * @param ctx
     * @return int
     */
    int EXPORT udp_establish(udp_create_flow_func create_flow, void *user, const struct udp_flowinfo *remote, struct context *ctx);

    /**
     * @param remote
     * @param ptr
     * @param len
     * @param ctx
     * @return int
     */
    int EXPORT udp_flow_send(const struct udp_flowinfo *remote, const void *ptr, size_t len, struct context *ctx);

    /**
     * @param socket_id
     * @param ctx
     */
    void EXPORT udp_close(int socket_id, struct context *ctx);

#ifdef __cplusplus
}
#endif